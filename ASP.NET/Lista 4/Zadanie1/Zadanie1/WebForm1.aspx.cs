using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Zadanie1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            var user = System.Security.Principal.WindowsIdentity.GetCurrent().Name;
            //Response.Write(user);


            var cs = ConfigurationManager.AppSettings["cn2"];

            using ( var ctx = new PersonCatalogDataContext(cs))
            {
                var persons = ctx.Persons.ToList();
                foreach(var person in persons)
                {
                    Response.Write(person);
                    Response.Write("<br/>");
                }
            }
            
        }
    }
}