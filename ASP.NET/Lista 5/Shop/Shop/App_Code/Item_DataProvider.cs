using System;
using System.Collections.Generic;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using Shop;
using System.Linq;

public class Item_DataProvider
{
    public Item_DataProvider() { }
    private int PriceSort = 0;
    private int NameSort = 0;
    public List<Item> Retrieve(string OrderBy, int StartRow, int RowCount)
    {
        List<Item> Res = Item_Model.Instance.Items;//.GetRange(StartRow, SelectItemsCount() - StartRow);
        switch (OrderBy)
        {
            case "price":
                Res.Sort((x, y) => x.price.CompareTo(y.price));
                break;
            case "price DESC":
                Res.Sort((x, y) => y.price.CompareTo(x.price));
                break;
            case "name":
                Res.Sort((x, y) => x.name.CompareTo(y.name));
                break;
            case "name DESC":
                Res.Sort((x, y) => y.name.CompareTo(x.name));
                break;
            default:
                break;
        }
        /*if(OrderBy == "price")
        {
            Res.Sort((x, y) => x.price.CompareTo(y.price));
        }
        else if(OrderBy == "price DESC")
        {
            Res.Sort((x, y) => y.price.CompareTo(x.price));
        }
        else if (OrderBy == "name")
        {
            Res.Sort((x, y) => x.name.CompareTo(y.name));
        }
        else if (OrderBy == "name DESC")
        {
            Res.Sort((x, y) => y.name.CompareTo(x.name));
        }
        else
        {
        }*/
        return Res.GetRange(StartRow, SelectItemsCount() - StartRow);
    }

    public int SelectItemsCount()
    {
        return Item_Model.Instance.Items.Count;
    }

    public static void Update(Item UpdatedItem) {
        var cs = ConfigurationManager.AppSettings["ShopDB"];
        using(var ItemDC = new ItemDataContext(cs))
        {
            Item OldItem = (from i in ItemDC.Items
                            where i.id == UpdatedItem.id
                            select i).First();
            //OldItem = UpdatedItem;
            OldItem.name = UpdatedItem.name;
            OldItem.description = UpdatedItem.description;
            OldItem.price = UpdatedItem.price;
            OldItem.image = UpdatedItem.image;
            ItemDC.SubmitChanges();
        }
    }

    public static void Delete(int ItemID)
    {
        var cs = ConfigurationManager.AppSettings["ShopDB"];
        using (var ItemDC = new ItemDataContext(cs))
        {
            var ItemToDelete = (from i in ItemDC.Items
                                where i.id == ItemID
                                select i).First();

            ItemDC.Items.DeleteOnSubmit(ItemToDelete);
            ItemDC.SubmitChanges();
        }
    }

    /*public int SelectItemsCount(string OrderBy, int StartRow, int RowCount)
    {
        return Item_Model.Instance.Items.Count;
    }*/


}