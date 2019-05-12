using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Tilemaps;

public class GameManager : MonoBehaviour {

    public GameObject SpdPowerPrefab;
    public Tilemap tilemap;
    public TileBase[] AllTiles;
    public Tile Chest;
    BoundsInt TilemapBounds;

    void Start() {
        InitializePowerups();
    }

    void InitializePowerups()
    {
        TilemapBounds = tilemap.cellBounds;     //Getting bounds of our tilemap
        AllTiles = tilemap.GetTilesBlock(TilemapBounds);  //Storing all tiles found in our tilemap
        var AllTilesPositions = TilemapBounds.allPositionsWithin;

        //Searching through all tiles positions stored in AllTilesPositions
        foreach(var pos in AllTilesPositions)
        {
            // Getting position of current tile.
            Vector3Int CurrentTilePos = new Vector3Int(pos.x, pos.y, pos.z);
            // Getting centered positions of current tile.
            Vector3 TileCenter = tilemap.GetCellCenterWorld(CurrentTilePos);

            // Creating SpeedPowerup object in TileCenter position.
            if(tilemap.GetTile(CurrentTilePos) == Chest)
            {
                Instantiate(SpdPowerPrefab, TileCenter, Quaternion.identity);
            }

        }

    }

}
