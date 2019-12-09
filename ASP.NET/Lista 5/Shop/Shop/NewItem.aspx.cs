using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Configuration;
using System.Web.Security;

namespace Shop
{
    public partial class NewItem : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void SubmitItemButton_Click(object sender, EventArgs e)
        {
            string ItemName = ItemNameTextBox.Text;
            string ItemPrice = ItemPriceTextBox.Text;
            string ItemDescription = ItemDescTextBox.Text;
            string ItemImageURL = ItemImageURLTextBox.Text;

            var cs = ConfigurationManager.AppSettings["ShopDB"];
            using(var ItemDC = new ItemDataContext(cs))
            {
                var CurrentItems = ItemDC.Items.ToList();
                var ItemWithTheSameName = (from i in CurrentItems
                                           where i.name == ItemName
                                           select i);
                if (ItemWithTheSameName.Any())
                {
                    Response.Write("Przedmiot o tej nazwie już istnieje");
                    return;
                }

                Item newItem = new Item();

                newItem.name = ItemName;
                newItem.price = Double.Parse(ItemPrice);
                newItem.description = ItemDescription;
                newItem.image = ItemImageURL;

                ItemDC.Items.InsertOnSubmit(newItem);
                ItemDC.SubmitChanges();

                HttpContext.Current.Session["item_model"] = new Item_Model();
            }

        }
    }
}