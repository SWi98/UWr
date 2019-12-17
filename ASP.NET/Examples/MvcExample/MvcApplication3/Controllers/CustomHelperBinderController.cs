using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MvcApplication3.Custom;
using MvcApplication3.Models.CustomHelperBinder;

namespace MvcApplication3.Controllers
{
    public class CustomHelperBinderController : Controller
    {
        //
        // GET: /CustomHelperBinder/

        public ActionResult Index( 
            [ModelBinder(typeof(CustomBinder))] IEnumerable<string> foo,
            [ModelBinder(typeof(CustomBinder))] IEnumerable<string> bar )
        {
            IndexModel model = new IndexModel();
            model.Foo = "qux2";

            return View( model );
        }

    }
}
