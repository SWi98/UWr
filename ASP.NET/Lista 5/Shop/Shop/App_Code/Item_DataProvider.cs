using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using Shop;

public class Item_DataProvider
{
    public Item_DataProvider() { }

    public List<Item> Retrieve(string OrderBy, int StartRow, int RowCount)
    {
        if(RowCount > 0)
        {
            return Item_Model.Instance.Items.GetRange(StartRow, RowCount);
        }
        else
        {
            return new List<Item>(new Item[] { Item_Model.Instance.Items[StartRow] });
        }
    }
}