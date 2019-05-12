using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WaypointsManager : MonoBehaviour
{
    public static Transform[] Waypoints;

    void Awake()
    {
        Waypoints = new Transform[transform.childCount];
        // Loop through all children 
        for (int i = 0; i < Waypoints.Length; i++)
        {
            Waypoints[i] = transform.GetChild(i);
        }
    }
}
