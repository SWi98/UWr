using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class IceTurret : MonoBehaviour
{
    public AudioClip freezeExplosion;
    public GameObject FreezeEffect;
    [Header("Stats")]
    public float Range = 18f;
    public float FireRate = 5f;
    private float FireRateCountdown = 0.0f;
    private IEnumerator coroutine;

    void Start()
    {
        InvokeRepeating("Freeze", 1f, 1/FireRate);
    }

    void Freeze()
    {
        GameObject[] Enemies = GameObject.FindGameObjectsWithTag("Enemy");

        Instantiate(FreezeEffect, transform.position, transform.rotation);
        this.GetComponent<AudioSource>().PlayOneShot(freezeExplosion);
        foreach (GameObject enemy in Enemies)
        {
            float distance = Vector3.Distance(transform.position, enemy.transform.position);
            if (distance <= Range + 0.2f)
            {
                coroutine = SlowEnemyToValue(enemy, 0);
                StartCoroutine(coroutine);

            }
        }
    }

    IEnumerator SlowEnemyToValue(GameObject EnemyToSlow, float value)
    {
        float BasicValue = 0f;
        if(EnemyToSlow != null )
            BasicValue = EnemyToSlow.GetComponent<Enemy>().speed;
        if (EnemyToSlow != null)
            EnemyToSlow.GetComponent<Enemy>().speed = value;
        if (EnemyToSlow != null)
            yield return new WaitForSeconds(1f);
        if (EnemyToSlow != null)
            EnemyToSlow.GetComponent<Enemy>().speed = BasicValue;

        yield return new WaitForSeconds(0f);
    }

    void OnDrawGizmosSelected()
    {
        Gizmos.color = Color.blue;
        Gizmos.DrawWireSphere(transform.position, Range);
    }
}
