using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SecondPlayerController : MonoBehaviour
{

    [SerializeField] float sndSpeed;
    Rigidbody2D sndRb;

    void Awake()
    {
        sndRb = GetComponent<Rigidbody2D>();
    }
    void FixedUpdate()
    {
        sndRb.MovePosition(transform.position + (((Vector3.right * Input.GetAxisRaw("2ndPlayerHorizontal")) +
            (Vector3.up * (Input.GetAxisRaw("2ndPlayerVertical"))))) * sndSpeed * Time.deltaTime);
    }
}
