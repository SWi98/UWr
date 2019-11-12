using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.IO;
using System.Net;
using System.Text;


namespace Zad1
{
    public partial class WebForm1 : System.Web.UI.Page
    { 
        protected void Page_Load(object sender, EventArgs e)
        {
            Response.Cookies["testCookie"].Value = "testowa wartosc " + DateTime.Now.ToString();
            Response.Cookies["testCookie"].Expires = DateTime.Now.AddDays(1);
        }

        public void ToWebForm2(object sender, EventArgs e)
        {
            Response.Redirect("WebForm2.aspx");
        }

        public void LinkButton1_Click(object sender, EventArgs e)
        {
            WebRequest request = WebRequest.Create("http://ap1.myserver.com/");

            request.Method = "POST";

            string PostData = "POST testing with LinkButton";
            byte[] byteArray = Encoding.UTF8.GetBytes(PostData);

            request.ContentLength = byteArray.Length;

            Stream dataStream = request.GetRequestStream();
            dataStream.Write(byteArray, 0, byteArray.Length);

            request.GetResponse();
        }
    }
}