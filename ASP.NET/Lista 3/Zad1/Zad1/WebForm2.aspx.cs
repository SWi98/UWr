using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Zad1
{

    public partial class WebForm2 : System.Web.UI.Page
    {

        private void Z2()
        {
            Response.Write("ZAD2:<br>");

            if (Request.Cookies["testCookie"] != null)
            {
                /*Response.Write(Request.Cookies["testCookie"].Value + "<br>");

                Request.Cookies["testCookie"].Expires = DateTime.Now.AddDays(-1);

                Response.Write(Request.Cookies["testCookie"].Expires + "<br>");
                Response.Write("Request.Cookies[\"testCookie\"] != null == " +
                    Request.Cookies["testCookie"] != null);*/

                 HttpCookie cookie = new HttpCookie("testCookie");
                 cookie.Expires = DateTime.Now.AddDays(-1);
                 Response.Cookies.Add(cookie);
                 Response.Write("Request.Cookies[\"testCookie\"] != null == " +
                     Request.Cookies["testCookie"] != null);
            }
        }

        private void Z3()
        {
            Response.Write("<br>ZAD3:");

            Response.AppendHeader("zadanie3", "abcd");

            Response.Write("<br>" + Response.Headers);
            Response.Write("<br>" + Server.MapPath(""));
            Response.Write("<br>" + Server.MapPath("/___"));
        }

        protected void Page_Load(object sender, EventArgs e)
        {
            Z2();
            Z3();

        }
    }
}