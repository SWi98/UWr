using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Configuration;

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
                Item newItem = new Item();

                newItem.name = ItemName;
                newItem.price = Double.Parse(ItemPrice);
                newItem.description = ItemDescription;
                newItem.image = ItemImageURL;

                ItemDC.Items.InsertOnSubmit(newItem);
                ItemDC.SubmitChanges();
            }

        }
    }
}