using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    public float speed = 10f;
    public int health = 1;
    public GameObject[] EnemyTypes;
     
    
    private Transform target;
    private int WayPointIndex = 0;
    
    void Start()
    {
        // Setting the value of the EnemyTypes array to EnemyTypes array stored in Spawner
        EnemyTypes = GameObject.FindGameObjectWithTag("GameManager").GetComponent<Spawner>().Enemies;
        GetNextWaypoint();
    }

    //Function called by bullet when we want to decrease health of this enemy. 
    //In the same method, we increase player's money by 1. 
    public void DamageEnemy(int value)
    {
        this.health -= value;
        PlayerStatus.Money++;
        if (this.health <= 0)
            Destroy(gameObject);
        else
            TransitionToDiffEnemy(EnemyTypes[this.health-1]);
      /*  switch (health){
            case 0:
                Destroy(gameObject);
                break;
            case 1:
                TransitionToDiffEnemy(EnemyTypes[0]);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            }*/

    }

    void Update()
    {
        // If the health = 0, then we destroy this enemy
        if (health <= 0)
            Destroy(gameObject);

        // Getting direction vector by subtracting enemy's position from target's position
        Vector3 direction = target.position - transform.position;
        transform.Translate(direction.normalized * speed * Time.deltaTime, Space.World);
        if (direction.magnitude <= 1f)
        {
            GetNextWaypoint();
        }
    }

    public void GetNextWaypoint()
    {
        if(WayPointIndex == WaypointsManager.Waypoints.Length - 1)
        {
            PlayerStatus.Health -= this.health;
            Destroy(gameObject);
        }

        target = WaypointsManager.Waypoints[WayPointIndex];
        WayPointIndex++;
    }

    public void TransitionToDiffEnemy(GameObject DifferentEnemy)
    {
        Debug.Log("works");
        Enemy enemyObject = DifferentEnemy.GetComponent<Enemy>();
        this.health = enemyObject.health;
        this.speed = enemyObject.speed;
        this.transform.localScale = enemyObject.transform.localScale;
        this.GetComponent<Renderer>().material = enemyObject.GetComponent<Renderer>().sharedMaterial;
    }
}
