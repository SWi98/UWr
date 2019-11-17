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
    public class ItemSingleton
    {
        const string key = "test_item";
        public static String Model
        {
            get
            {
                if(HttpContext.Current.Items[key] == null)
                {
                    String data = HttpContext.Current.Timestamp.ToString();
                    HttpContext.Current.Items[key] = data;
                }
                return (String)HttpContext.Current.Items[key];
            }

        }
    }

    public class SessionSingleton
    {
        const string key = "test_session";
        public static String Model {
            get {
                if(HttpContext.Current.Session[key] == null)
                {
                    String data = HttpContext.Current.Timestamp.ToString();
                    HttpContext.Current.Session[key] = data;
                }
                return (String)HttpContext.Current.Session[key];
            }
        }
    }

    public class ApplicationSingleton
    {
        const string key = "test_app";
        static readonly object _lock = new object();
        public static String Model {
            get {
                if(HttpContext.Current.Application[key] == null)
                {
                    lock (_lock)
                    {
                        String data = HttpContext.Current.Timestamp.ToString();
                        HttpContext.Current.Application[key] = data;
                    }
                }
                return (String)HttpContext.Current.Application[key];
            }
        }
    }

    public partial class WebForm1 : System.Web.UI.Page
    { 
        protected void Page_Load(object sender, EventArgs e)
        {
            Response.Cookies["testCookie"].Value = "testowa wartosc " + DateTime.Now.ToString();
            Response.Cookies["testCookie"].Expires = DateTime.Now.AddDays(1);
            Response.Write("Zadanie 4:<br/>Item: " + ItemSingleton.Model);
            Response.Write("<br/>");
            Response.Write("Session: " + SessionSingleton.Model);
            Response.Write("<br/>");
            Response.Write("Application: " + ApplicationSingleton.Model);
            Response.Write("<br/><br/>");
            // HttpContext.Current.Request;
            // Request
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