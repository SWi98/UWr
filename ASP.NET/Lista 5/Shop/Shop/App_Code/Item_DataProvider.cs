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

    public List<Item> Retrieve(string OrderBy, int StartRow, int RowCount)
    {
        if(RowCount > 0)
        {
            return Item_Model.Instance.Items.GetRange(StartRow, SelectItemsCount() - StartRow);
        }
        else
        {
            return new List<Item>(new Item[] { Item_Model.Instance.Items[StartRow] });
        }
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

    /*public int SelectItemsCount(string OrderBy, int StartRow, int RowCount)
    {
        return Item_Model.Instance.Items.Count;
    }*/


}