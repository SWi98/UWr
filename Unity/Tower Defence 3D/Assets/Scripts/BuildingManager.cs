using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BuildingManager : MonoBehaviour
{
    // Reference to itself
    public static BuildingManager instance;
    public AudioClip Buying;
    private AudioSource source;
    
    void Awake()
    {
        instance = this;
        source = this.GetComponent<AudioSource>();
    }

    // Turret currently picked to be available to build 
    private TurretBlueprint PickedTurret;

    public GameObject TurretPicked()
    {
        return PickedTurret.TurretPrefab;
    }

   // public GameObject Turret_1;
    public bool AvailableToBuild { get { return PickedTurret != null; } }


    // Setting which turret we want to be available to build
    public void SelectTurretToBuild(TurretBlueprint turr)
    {
        PickedTurret = turr;
    }

    public void NoneSelected()
    {
        PickedTurret = null;
    }

    public void BuildTurret(Tile tile)
    {
        if (PlayerStatus.Money >= PickedTurret.cost)
        {
            GameObject turret = (GameObject)Instantiate(PickedTurret.TurretPrefab,
                tile.transform.position + new Vector3(0, 0.51f, 0), tile.transform.rotation);
            tile.TurretAbove = turret;
            PlayerStatus.Money -= PickedTurret.cost;
            source.PlayOneShot(Buying);
        }
        else
        {
            Debug.Log("Not enough money!");
        }
    }
}
