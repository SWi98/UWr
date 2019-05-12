using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Spawner : MonoBehaviour
{
    public Text EndText;
    public Text WaveNumber;
    public Text counter;
    public Transform EnemyPrefab;
    public Transform SpawnPlace;
    public GameObject[] Enemies;
    public GameObject RedPrefab;
    public GameObject YellowPrefab;
    public GameObject GreenPrefab;
    public GameObject BluePrefab;
    public GameObject BlackPrefab;
    public GameObject SteelPrefab;
    [Header("Number of enemies in consecutive waves:")]
    public int[] RedEnemies = new int[20];
    public int[] YellowEnemies = new int[20];
    public int[] GreenEnemies = new int[20];
    public int[] BlueEnemies = new int[20];
    public int[] BlackEnemies = new int[20];
    public int[] SteelEnemies = new int[20];
    // Countdown is a different variable because first countdown should be shorter 
    private float Countdown = 10f;
    private float WaitTime = 5f;
   // private int WaveNumber = 1;
    private int WaveCounter;
   // private GameObject[] EnemiesOnMap;


    void Start()
    {
        Debug.Log(WaitTime);
        WaveCounter = 0;
    }
    void Update()
    {
        GameObject[] EnemiesOnMap = GameObject.FindGameObjectsWithTag("Enemy");

        if (WaveCounter == 16)
        {
            EndText.text = "WIN";
            WaveNumber.text = "";
}
        else
        {
            if (EnemiesOnMap.Length == 0)
            {
                counter.text = "Time left: " + Mathf.Ceil(Countdown);
                WaveNumber.text = "Wave nr: " + (WaveCounter + 1) + "/15";
                Countdown -= Time.deltaTime;
            }
            else
            {
                counter.text = "Time left: 0";
            }
            if (Countdown <= 0.0f)
            {

                if (WaveCounter > 0)
                    PlayerStatus.Money += 10;
                StartCoroutine(SpawnWave(RedPrefab, RedEnemies[WaveCounter]));
                StartCoroutine(SpawnWave(YellowPrefab, YellowEnemies[WaveCounter]));
                StartCoroutine(SpawnWave(GreenPrefab, GreenEnemies[WaveCounter]));
                StartCoroutine(SpawnWave(BluePrefab, BlueEnemies[WaveCounter]));
                StartCoroutine(SpawnWave(BlackPrefab, BlackEnemies[WaveCounter]));
                StartCoroutine(SpawnWave(SteelPrefab, SteelEnemies[WaveCounter]));
                Countdown = WaitTime;
                WaveCounter++;

            }
        }

    }

    IEnumerator SpawnWave(GameObject enemyPrefab, int amount)
    {
        float wait = 0.5f;
        if (enemyPrefab == BluePrefab)
            wait = 0.3f;
        else if (enemyPrefab == BlackPrefab)
            wait = 0.3f;
        for (int i = 0; i < amount; i++)
        {
            SpawnEnemy(enemyPrefab);
            yield return new WaitForSeconds(wait);
        }
    }

    void SpawnEnemy(GameObject enemyPrefab)
    {
        Instantiate(enemyPrefab, SpawnPlace.position, SpawnPlace.rotation);
    }
}
