using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Zadanie1.Controllers
{
    public class HomeController : Controller
    {
        public string Index()
        {
            return "this is <b>default</b> action";
        }

        public string Welcome()
        {
            return "Welcome string method";
            
        }


        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }
    }
}