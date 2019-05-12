using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Turret : MonoBehaviour
{
    private Transform Target;
    public Transform Head;
    public float turnSpeed = 8f;
    public GameObject BulletPrefab;
    public Transform BulletPosition;
    public GameObject RocketPrefab;
    private GameObject EnemyTarget;

    [Header("Stats")]
    public float Range = 18f;
    public float FireRate = 5f;
    private float FireRateCountdown = 0.0f;
    
    void Start()
    {
        InvokeRepeating("UpdateTarget", 0f, 1f);
    }

    void UpdateTarget()
    {
        GameObject[] Enemies = GameObject.FindGameObjectsWithTag("Enemy");
        float shortestDist = Mathf.Infinity;
        GameObject NearestEnemy = null;

        foreach(GameObject enemy in Enemies)
        {
            float distance = Vector3.Distance(transform.position, enemy.transform.position);
            if (shortestDist > distance)
            {
                NearestEnemy = enemy;
                shortestDist = distance;
            }
        }

        if (NearestEnemy != null && shortestDist <= Range)
        {
            EnemyTarget = NearestEnemy;
            Target = NearestEnemy.transform;
        }
        else
            Target = null;
    }

    void Update()
    {
        if (Target == null)
            return;

        Vector3 direction = Target.position - transform.position;
        Quaternion Rotation = Quaternion.LookRotation(direction);
        Rotation.eulerAngles += new Vector3(15, 0, 0);
        Head.rotation = Quaternion.Lerp(Head.rotation, Rotation, Time.deltaTime * turnSpeed);
        if(FireRateCountdown <= 0.0f)
        {
            Shoot();
            FireRateCountdown = 1f / FireRate;
        }
        FireRateCountdown -= Time.deltaTime;
    }

    void Shoot()
    {
        if (this.tag == "BasicEyeTurret")
        {
            GameObject CurrentBullet =
            (GameObject)Instantiate(BulletPrefab, BulletPosition.position, BulletPosition.rotation);

            Bullet bullet = CurrentBullet.GetComponent<Bullet>();
            if (bullet != null)
            {
                bullet.Seek(EnemyTarget);
            }
        }

        else if(this.tag == "RocketTurret")
        {
            Quaternion RocketRotation = BulletPosition.rotation;
            RocketRotation.eulerAngles += new Vector3(90, 0, 0);
            GameObject CurrentRocket =
                (GameObject)Instantiate(RocketPrefab, BulletPosition.position, RocketRotation);
            Bullet bullet = CurrentRocket.GetComponent<Bullet>();
            if (bullet != null)
            {
                bullet.Seek(EnemyTarget);
            }
        }
        
    }

    void OnDrawGizmosSelected()
    {
        Gizmos.color = Color.blue;
        Gizmos.DrawWireSphere(transform.position, Range);
    }
}
