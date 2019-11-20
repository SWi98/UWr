using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Zadanie8
{
    public static class IsLogged
    {
        public static bool Logged
        {
            get{
                return HttpContext.Current.Session["email"] != null && 
                    HttpContext.Current.Session["password"] != null;
            }
        }
    }

    public partial class Login : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
        }
        
        public void SubmitUser(object sender, EventArgs e)
        {
            string email = UserEmail.Text;
            string password = UserPassword.Text;
            HttpContext.Current.Session["email"] = email;
            HttpContext.Current.Session["password"] = password;
            if(Request.QueryString["PreviousPage"] != null)
            {
                Response.Redirect(Request.QueryString["PreviousPage"]);
            }
        }
    }
}