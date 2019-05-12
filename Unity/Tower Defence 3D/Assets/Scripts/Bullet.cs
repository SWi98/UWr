using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    private GameObject Target;
    public AudioClip PopSound;
    public float RocketExplosionRange = 8f;
    public float speed = 50f;
    [Header("Only for rockets")]
    public GameObject ExplosionEffect;
    

    public void Seek(GameObject _target)
    {
        Target = _target;
    }
    
    void Update()
    {
        // When enemy is destroyed before the bullet gets to it
        if(Target == null)
        {
            Destroy(gameObject);
            return;
        }

        Vector3 Direction = Target.transform.position - transform.position;
        float distanceThisFrame = speed * Time.deltaTime;

        if(Direction.magnitude <= distanceThisFrame)
        {
            HitTarget();
            return;  
        }

        transform.Translate(Direction.normalized * distanceThisFrame, Space.World);
    }

    void HitTarget()
    {
        // If our bullet is a basic bullet.
        if (this.tag == "Bullet")
        {
            Enemy enemy = Target.GetComponent<Enemy>();

            // Temporary solution to check whether the enemy is a steel enemy or isn't
            if (enemy.health != 6)
            {
                enemy.DamageEnemy(1);
                this.gameObject.GetComponent<AudioSource>().PlayOneShot(PopSound);
            }

        }

        // If our bullet is a rocket. 
        else if(this.tag == "Rocket")
        {
            GameObject[] Enemies = GameObject.FindGameObjectsWithTag("Enemy");

            foreach (GameObject enemy in Enemies) { 
                float distance = Vector3.Distance(transform.position, enemy.transform.position);
                if (RocketExplosionRange >= distance)
                {
                    enemy.GetComponent<Enemy>().DamageEnemy(1);
                    
                }
            }
            Explode();
            AudioSource.PlayClipAtPoint(PopSound, 0.9f * Camera.main.transform.position + 0.1f * transform.position, 1.0f);
        }

        Destroy(gameObject);
    }
    
    void Explode()
    {
        Instantiate(ExplosionEffect, transform.position, transform.rotation);
    }
}
