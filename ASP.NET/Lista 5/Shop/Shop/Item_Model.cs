using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Web;
using Shop;

public class Item_Model
{
    public List<Item> Items = new List<Item>();

    public Item_Model()
    {
        var cs = ConfigurationManager.AppSettings["ShopDB"];
        using(var ItemDC = new ItemDataContext(cs))
        {
            foreach(var item in ItemDC.Items.ToList())
            {
                var x = item.name;
                Items.Add(item);
            }
        }
    }

    public static Item_Model Instance
    {
        get 
        {
            if(HttpContext.Current.Session["item_model"] == null)
            {
                Item_Model model = new Item_Model();
                HttpContext.Current.Session["item_model"] = model;
            }

            return (Item_Model)HttpContext.Current.Session["item_model"];
        }
    }

}