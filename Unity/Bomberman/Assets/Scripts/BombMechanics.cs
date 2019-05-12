using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BombMechanics : MonoBehaviour {

    public float countdown = 2f;

    void Update()
    {   
        countdown -= Time.deltaTime;
        
        if(countdown <= 1f)
        {
            transform.localScale += new Vector3(0.004f, 0.004f, 0);
        }

        if(countdown <= 0f)
        {
            FindObjectOfType<Destroyer>().Explode(transform.position);
            Destroy(gameObject);
        }
    }

}
