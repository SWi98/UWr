using UnityEngine;
using UnityEngine.Tilemaps;

public class BombSpawner : MonoBehaviour
{

    public Tilemap tilemap;
    public GameObject bombPrefab;
    public GameObject PurplePlayer;
    public GameObject YellowPlayer;
    GameObject[] AllBombs;

    // Update is called once per frame
    void Update()
    {
        Vector3 YellowPos = YellowPlayer.transform.position;
        Vector3Int YellowCell = tilemap.WorldToCell(YellowPos);
        Vector3 YellowCenterPos = tilemap.GetCellCenterWorld(YellowCell);
        // Above and below - gettig positions of the cells where players are. 
        Vector3 PurplePos = PurplePlayer.transform.position;
        Vector3Int PurpleCell = tilemap.WorldToCell(PurplePos);
        Vector3 PurpleCenterPos = tilemap.GetCellCenterWorld(PurpleCell);

        if (Input.GetKeyDown("space"))
        {
            Instantiate(bombPrefab, YellowCenterPos, Quaternion.identity);
        }
        if (Input.GetKeyDown(KeyCode.KeypadEnter))
        {
            Instantiate(bombPrefab, PurpleCenterPos, Quaternion.identity);
        }

        AllBombs = GameObject.FindGameObjectsWithTag("Bomb");

        foreach(GameObject bomb in AllBombs)
        {
            //Comparing position (tile) of the bomb with positions of the players.
            Vector3Int BombCell = tilemap.WorldToCell(bomb.transform.position);
            if(BombCell != PurpleCell && BombCell != YellowCell)
            {
                bomb.GetComponent<CircleCollider2D>().enabled = true;
            }
        }
    }
}