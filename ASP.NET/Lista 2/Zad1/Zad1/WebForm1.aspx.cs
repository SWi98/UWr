using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.IO;
using System.Text;

namespace Zad1
{   
    public class CustomHTTPHandler : IHttpHandler
    {
        public bool IsReusable {
            get {
                return false;
            }
        }

        public void ProcessRequest(HttpContext context)
        {
            if (context.Request.RequestType == "POST")
            {
                Stream inputStream = context.Request.InputStream;
                StreamReader readStream = new StreamReader(inputStream, Encoding.UTF8);
                context.Response.Write(readStream.ReadToEnd());
            }

            else
            {
                context.Response.Write(context.Request.Url + "<br/>");
                context.Response.Write(context.Request.Headers + " <br/>");
                context.Response.Write(context.Request.RequestType + "<br/>");

                if (context.Request.ContentLength != 0)
                {
                    Stream inputStream = context.Request.InputStream;
                    StreamReader readStream = new StreamReader(inputStream, Encoding.UTF8);
                    context.Response.Write(readStream.ReadToEnd());
                }
                //context.Response.Redirect("https://www.onet.pl/");
            }
        }
    }


    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
    }
}