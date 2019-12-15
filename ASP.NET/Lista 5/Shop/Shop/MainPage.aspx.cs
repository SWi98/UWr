using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.Security;
using System.Web.UI.WebControls;

namespace Shop
{
    public partial class MainPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
        }

        protected void ListView1_ItemCommand(object sender, ListViewCommandEventArgs e)
        {
            if(e.CommandName == "AddToCart")
            {
                if(!HttpContext.Current.User.Identity.IsAuthenticated)
                {
                    return;
                }

                ShoppingCart shoppingCart = ShoppingCart.Instance;
                int id = Int32.Parse(e.CommandArgument.ToString());

                var cs = System.Configuration.ConfigurationManager.AppSettings["ShopDB"];
                using(var ItemDC = new ItemDataContext(cs))
                {
                    Item itemToAdd = (from i in ItemDC.Items.ToList()
                                      where i.id == id
                                      select i).First();

                    shoppingCart.AddItem(itemToAdd);
                }
            }
        }

        protected void ListView1_ItemUpdating(object sender, ListViewUpdateEventArgs e)
        {
            Response.Write(e.OldValues.ToString());
        }

        protected void ObjectDataSource1_Updating(object sender, ObjectDataSourceMethodEventArgs e)
        {
            int ItemID = (int)e.InputParameters["id"];
            var x = e;
            string NewName = ((TextBox)ListView1.EditItem.FindControl("EditNameTextBox")).Text;
            string NewDesc = ((TextBox)ListView1.EditItem.FindControl("EditDescTextBox")).Text;
            string NewImage = ((TextBox)ListView1.EditItem.FindControl("EditImageTextBox")).Text;
            double NewPrice = Double.Parse(((TextBox)ListView1.EditItem.FindControl("EditPriceTextBox")).Text);

            Item item = new Item();
            item.id = ItemID;
            item.name = NewName;
            item.description = NewDesc;
            item.image = NewImage;
            item.price = NewPrice;

            e.InputParameters.Clear();
            e.InputParameters.Add("UpdatedItem", item);
        }

        protected void ObjectDataSource1_Updated(object sender, ObjectDataSourceStatusEventArgs e)
        {
            // Setting Session container containing list of Items to null forces Item_Model to refresh its value
            // after accessing Item_Model.Instance
            //HttpContext.Current.Session["item_model"] = null;
        }

        protected void Sort_Click(object sender, EventArgs e)
        {
            ListView1.Sort("price", SortDirection.Ascending);
        }

        protected void ObjectDataSource1_Deleting(object sender, ObjectDataSourceMethodEventArgs e)
        {
            int itemID = (int)e.InputParameters["id"];

            e.InputParameters.Clear();
            e.InputParameters.Add("ItemID", itemID);
        }
    }
}