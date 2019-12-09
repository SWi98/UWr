using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using Shop;

public class ShoppingCart
{
    public List<Item> ItemsInCart = new List<Item>();

    public ShoppingCart()
    {
    }

    public void AddItem(Item item)
    {
        ItemsInCart.Add(item);
    }

    public static ShoppingCart Instance
    {
        get{
            if(HttpContext.Current.Session["cart"] == null)
            {
                ShoppingCart cart = new ShoppingCart();
                HttpContext.Current.Session["cart"] = cart;
            }

            return (ShoppingCart)HttpContext.Current.Session["cart"];
        }
    }
}