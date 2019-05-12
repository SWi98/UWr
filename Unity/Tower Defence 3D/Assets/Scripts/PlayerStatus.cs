using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class PlayerStatus : MonoBehaviour
{
    public Text EndText;
    public AudioClip Failure;
    public static int Money;
    public int StartingMoney = 100;
    public static int Health;
    public int StartingHealth = 20;
    public Text currentMoney;
    public Text currentHealth;
    public GameObject Background;
    public Material FailColor;

    void Start()
    {
        Money = StartingMoney;
        Health = StartingHealth;
    }

    void Update()
    {
        if (Input.GetKey("escape"))
        {
            Application.Quit();
        }
        currentMoney.text = "$: " + Money;
        currentHealth.text = "Health: " + Health;
        if(Health <= 0)
        {
            Background.GetComponent<Renderer>().material.color = FailColor.color;
            EndText.text = "FAILURE";
            Time.timeScale = 0;
        }
    }
    
}
