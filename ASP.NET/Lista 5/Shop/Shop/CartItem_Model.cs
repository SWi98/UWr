using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using Shop;


public class CartItem_Model
{
    public List<Item> Items = new List<Item>();

    public CartItem_Model()
    {
        Items = ShoppingCart.Instance.ItemsInCart;
    }

    public static CartItem_Model Instance {
        get {
            if (HttpContext.Current.Session["cartitem_model"] == null)
            {
                CartItem_Model model = new CartItem_Model();
                HttpContext.Current.Session["cartitem_model"] = model;
            }

            return (CartItem_Model)HttpContext.Current.Session["cartitem_model"];
        }
    }
}