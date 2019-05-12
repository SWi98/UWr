using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tile : MonoBehaviour
{
    public Color HoverColor;
    public ParticleSystem CircleRangePrefab;
    public GameObject EyeTurretPrefab;
    public GameObject RocketTurretPrefab;
    public GameObject IceTurretPrefab;
    [Header ("Leave Empty")]
    public GameObject TurretAbove; 
    private Color DefaultColor;
    private Renderer ThisRenderer;
    private Vector3 BuildingPos;
    private BuildingManager buildManager;
    private float eyeTurretRange, rocketTurretRange, iceTurretRange;
    private ParticleSystem.ShapeModule shapeModule;
    private ParticleSystem Circle;




    void Start()
    {
        ThisRenderer = GetComponent<Renderer>();
        DefaultColor = ThisRenderer.material.color;
        buildManager = BuildingManager.instance;
        eyeTurretRange = EyeTurretPrefab.GetComponent<Turret>().Range;
        rocketTurretRange = RocketTurretPrefab.GetComponent<Turret>().Range;
        iceTurretRange = IceTurretPrefab.GetComponent<IceTurret>().Range;
        shapeModule = CircleRangePrefab.shape;
    }

    void OnMouseEnter()
    {
        // If we picked a turret from the shop            
        if (buildManager.AvailableToBuild)
        {            
            ThisRenderer.material.color = HoverColor;
            Quaternion Rotation = transform.rotation;
            Rotation.eulerAngles += new Vector3(90f, 0f, 0f);
            if (buildManager.TurretPicked() == EyeTurretPrefab)
            {
                shapeModule.radius = eyeTurretRange - 0.2f;
            }
            else if(buildManager.TurretPicked() == RocketTurretPrefab)
            {
                shapeModule.radius = rocketTurretRange - 0.2f;
            }
            else if(buildManager.TurretPicked() == IceTurretPrefab)
            {
                shapeModule.radius = iceTurretRange - 0.2f;
            }
            Circle = (ParticleSystem)Instantiate(CircleRangePrefab, transform.position + new Vector3(0f, 2f, 0f), Rotation);

        }
    }

    void OnMouseExit()
    {
        if (Circle != null)
            Destroy(Circle);

        ThisRenderer.material.color = DefaultColor;
    }

    void OnMouseDown()
    {
        // If no turret has been chosen from the shop
        if(!buildManager.AvailableToBuild)
        {
            return;
        }

        // If there is already a turret on our tile
        if(TurretAbove != null)
        {
            return;
        }

        // If we clicked on a tile and it's a tile without any buildings on it and we have chosen a turret to build,
        // then build a turret using method from BuildingManager
        buildManager.BuildTurret(this);
    }
}
