using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Tilemaps;
using UnityEngine.UI;

public class Destroyer : MonoBehaviour
{

    public Tilemap tilemap;
    public Tile wallTile;
    public Tile woodTile;
    public GameObject ExplosionPrefab;
    public GameObject PurplePlayer;
    public GameObject YellowPlayer;
    private IEnumerator coroutine;
    bool isYellowDead;
    bool isPurpleDead;
    GameObject[] AllBombs;
    public GameObject YellowWon;
    public GameObject PurpleWon;
    public GameObject Draw;
    

    public void CancelBombs()
    {
        AllBombs = GameObject.FindGameObjectsWithTag("Bomb");
        foreach (GameObject bomb in AllBombs)
        {
            Object.Destroy(bomb);
        }
    }

    public void Explode(Vector2 Worldpos)
    {
        isYellowDead = false;
        isPurpleDead = false;

        // Changing coords of our player to coords of the tile
        Vector3Int originCell = tilemap.WorldToCell(Worldpos);
       // Tile tile = tilemap.GetTile<Tile>(originCell);

        ExplodeCell(originCell);
        if (ExplodeCell(originCell + new Vector3Int(1, 0, 0)))
            ExplodeCell(originCell + new Vector3Int(2, 0, 0));
        if (ExplodeCell(originCell + new Vector3Int(-1, 0, 0)))
            ExplodeCell(originCell + new Vector3Int(-2, 0, 0));
        if (ExplodeCell(originCell + new Vector3Int(0, 1, 0)))
            ExplodeCell(originCell + new Vector3Int(0, 2, 0));
        if (ExplodeCell(originCell + new Vector3Int(0, -1, 0)))
            ExplodeCell(originCell + new Vector3Int(0, -2, 0));

        if (isYellowDead && isPurpleDead)
        {
            CancelBombs();
            coroutine = WaitAndStop(0.7f);
            StartCoroutine(coroutine);
            YellowPlayer.transform.localScale -= (new Vector3(0.8f, 0.8f, 0));
            PurplePlayer.transform.localScale -= (new Vector3(0.8f, 0.8f, 0));
            Draw.SetActive(true);
        }
        else if (isYellowDead)
        {
            CancelBombs();
            coroutine = WaitAndStop(0.7f);
            StartCoroutine(coroutine);
            YellowPlayer.transform.localScale -= (new Vector3(0.8f, 0.8f, 0));
            PurpleWon.SetActive(true);
        }
        else if (isPurpleDead)
        {
            CancelBombs();
            coroutine = WaitAndStop(0.7f);
            StartCoroutine(coroutine);
            PurplePlayer.transform.localScale -= (new Vector3(0.8f, 0.8f, 0));
            YellowWon.SetActive(true);
        }
    }

    // Destroying selected cell
    bool ExplodeCell(Vector3Int cell)
    {
        // Saving Yellow's and Purple's positions
        Vector3 YellowPos = YellowPlayer.transform.position;
        Vector3Int YellowCell = tilemap.WorldToCell(YellowPos);
        Vector3 PurplePos = PurplePlayer.transform.position;
        Vector3Int PurpleCell = tilemap.WorldToCell(PurplePos);



        Tile tile = tilemap.GetTile<Tile>(cell);
        if (tile == woodTile)
        {
            tilemap.SetTile(cell, null);
            int x = Random.Range(1, 10);
            if (x == 1)
                FindObjectOfType<SpeedPowerupSpawner>().SpawnSpdPowerup(cell);
        }
        else if (tile == wallTile)
        {
            return false;
        }
        else if (cell == YellowCell)
        {
            isYellowDead = true;
        }
        else if (cell == PurpleCell)
        {
            isPurpleDead = true;
        }


        Vector3 pos = tilemap.GetCellCenterWorld(cell);
        Instantiate(ExplosionPrefab, pos, Quaternion.identity);
        return true;
    }
    private IEnumerator WaitAndStop(float waitTime)
    {
        yield return new WaitForSeconds(waitTime);
        Time.timeScale = 0f;
    }
}
