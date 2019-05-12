using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShopManager : MonoBehaviour
{
    public TurretBlueprint BasicEyeTurret;
    public TurretBlueprint RocketTurret;
    public TurretBlueprint IceTurret;
    public int HealthCost;

    BuildingManager buildManager;

    void Start()
    {
        buildManager = BuildingManager.instance;
    }

    // After clicking on a desired turret, inform buildManager which turret is to be built. 
    public void SelectBasicEyeTurret()
    {
        buildManager.SelectTurretToBuild(BasicEyeTurret);
    }

    public void SelectRocketTurret()
    {
        buildManager.SelectTurretToBuild(RocketTurret);
    }

    public void SelectIceTurret()
    {
        buildManager.SelectTurretToBuild(IceTurret);
    }

    public void SelectNone()
    {
        buildManager.NoneSelected();
    }

    public void IncreaseHealth()
    {
        if(PlayerStatus.Money >= HealthCost)
        {
            PlayerStatus.Money -= HealthCost;
            PlayerStatus.Health++;
        }
        SelectNone();
    }
}
