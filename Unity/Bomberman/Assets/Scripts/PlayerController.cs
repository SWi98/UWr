using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour {

    [SerializeField] float moveSpd;
    Rigidbody2D myRb;

    void Awake()
    {
        myRb = GetComponent<Rigidbody2D>();
        
    }
    void FixedUpdate()
    {

        myRb.MovePosition(transform.position + (((Vector3.right * Input.GetAxisRaw("1stPlayerHorizontal")) +
            (Vector3.up * (Input.GetAxisRaw("1stPlayerVertical"))))) * moveSpd * Time.deltaTime);
    }
}
