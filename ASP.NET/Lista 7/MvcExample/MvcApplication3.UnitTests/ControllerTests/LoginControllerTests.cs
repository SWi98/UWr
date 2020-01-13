using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;
using System.Web.Mvc;
using MvcApplication3.Controllers;
using MvcApplication3.Custom;
using MvcApplication3.Models.Account;
using NUnit.Framework;

namespace MvcApplication3.UnitTests.ControllerTests
{
    [TestFixture]
    public class LoginControllerTests : TestBase
    {
        [Test]
        public void LogOnNotAuthenticated()
        {
            AccountController c = new AccountController();

            var result = c.LogOn();

            Assert.IsInstanceOf<ViewResult>( result );
        }

        [Test]
        public void LogOnAuthenticateWrongCredentials()
        {
            AccountController c = new AccountController();

            StringBuilder sb = new StringBuilder();
            this.BuildUpController( c, "http://foo.bar.com/Account/LogOn", null, sb );

            LogOnModel model = new LogOnModel();
            model.UserName = "foo";
            model.Password = "bar";

            var result = c.LogOn( model, "foo" );

            Assert.IsInstanceOf<ViewResult>( result );

            // testujemy obecność błędu walidacji
            Assert.That( c.ModelState.ContainsKey( "logon" ) );
        }

        [Test]
        public void LogOnAuthenticateCorrectCredentials()
        {
            AccountController c = new AccountController();

            StringBuilder sb = new StringBuilder();
            this.BuildUpController( c, null, null, sb );

            LogOnModel model = new LogOnModel();
            model.UserName = "foo";
            model.Password = "foo";

            var result = c.LogOn( model, "ret" );

            Assert.IsInstanceOf<RedirectResult>( result );

            RedirectResult redirect = (RedirectResult)result;
            redirect.ExecuteResult( c.ControllerContext );

            Assert.AreEqual( redirect.Url, "ret" );
        }
    }

    public class CustomHttpContext : HttpContextBase
    {

    }
}
