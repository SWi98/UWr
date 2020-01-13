using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Security;
using MvcApplication3.Custom;
using MvcApplication3.Models.Account;

namespace MvcApplication3.Controllers
{
    public class AccountController : Controller
    {
        [CustomActionFilter]
        [HttpGet]
        public ActionResult LogOn()
        {
            LogOnModel model = new LogOnModel();

            return View( model );
        }

        [HttpPost]
        public ActionResult LogOn( LogOnModel model, string ReturnUrl )
        {
            if ( this.ModelState.IsValid )
            {
                if ( Membership.ValidateUser( model.UserName, model.Password ) )
                {
                    FormsAuthenticationTicket ticket = new FormsAuthenticationTicket( model.UserName, false, 20 );

                    HttpCookie cookie = new HttpCookie( FormsAuthentication.FormsCookieName );
                    cookie.Value = FormsAuthentication.Encrypt( ticket );
                    this.Response.AppendCookie( cookie );

                    return Redirect( ReturnUrl );
                }
                else
                    this.ModelState.AddModelError( "logon", "Zła nazwa użytkownika lub hasło" );
            }

            return View( model );
        }

    }
}
