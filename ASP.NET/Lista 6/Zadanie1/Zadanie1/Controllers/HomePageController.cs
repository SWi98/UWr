using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Zadanie1.Controllers
{
    public class HomePageController : Controller
    {
        // GET: HomePage
        public ActionResult Index()
        {
            return View();
        }
        public string Welcome()
        {
            return "Welcome - HomePage";
        }

        public ActionResult Form()
        {
            string name = Request.QueryString["name"];
            string surname = Request.QueryString["surname"];
            string class_name = Request.QueryString["class_name"];
            int[] point = new int[10];
            ViewData["name"] = name;
            ViewData["surname"] = surname;
            ViewData["class_name"] = class_name;
            for(int i = 0; i < 10; i++)
            {
                string p;
                p = Request.QueryString["Z" + (i+1).ToString()];
                if(p == "")
                {
                    p = "0";
                }
                bool result = Int32.TryParse(p, out point[i]);
                if(!result)
                {
                    return RedirectToAction("Index", "HomePage");
                }
            }
            if(name == "" || surname == "" || class_name == "")
            {
                return RedirectToAction("Index", "HomePage");
            }
            ViewData["Z"] = point;
            return View();
        }
    }
}