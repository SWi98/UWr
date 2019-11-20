using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Zadanie8
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsLogged.Logged)
            {
                Response.Redirect("Login.aspx?" + "PreviousPage=WebForm2.aspx");
            }
        }
    }
}