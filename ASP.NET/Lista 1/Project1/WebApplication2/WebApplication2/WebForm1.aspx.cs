using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;


namespace WebApplication2
{
    
    public partial class WebForm1 : System.Web.UI.Page
    {
        private string UserInput;
        protected void Page_Load(object sender, EventArgs e)
        {
        }

        protected void SubmitText(object sender, EventArgs e)
        {
            UserInput = TextBox1.Text;
            TextBox1.Text = "";
        }


    }
}