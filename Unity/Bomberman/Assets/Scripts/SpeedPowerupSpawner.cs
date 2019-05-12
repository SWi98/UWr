using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Tilemaps;
public class SpeedPowerupSpawner : MonoBehaviour {

    public GameObject SpdPowerupPrefab;
    public Tilemap tilemap;

	public void SpawnSpdPowerup(Vector3Int TilePos)
    {
        //Vector3Int TilePos = tilemap.WorldToCell(Position);
        Vector3 cell = tilemap.GetCellCenterWorld(TilePos);
    //    Instantiate(SpdPowerupPrefab, cell, Quaternion.identity);
    }
}
