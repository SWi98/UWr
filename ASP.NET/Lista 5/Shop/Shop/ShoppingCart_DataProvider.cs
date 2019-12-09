using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using Shop;

public class ShoppingCart_DataProvider
{
    public ShoppingCart_DataProvider()
    {

    }

    public List<Item> Retrieve(string OrderBy, int StartRow, int RowCount)
    {
        if (RowCount > 0)
        {
            return CartItem_Model.Instance.Items.GetRange(StartRow, CartItem_Model.Instance.Items.Count - StartRow);
        }
        else
        {
            return new List<Item>(new Item[] { CartItem_Model.Instance.Items[StartRow] });
        }
    }

    public int SelectItemsCount()
    {
        return CartItem_Model.Instance.Items.Count;
    }
}