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
    }
}