using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Web;
using System.Web.Configuration;
using System.Web.Mvc;
using System.Web.Routing;
using MvcApplication3.Custom;

namespace MvcApplication3.UnitTests.ControllerTests
{
    public class TestBase
    {
        public const string APPBASEADDRESS = "http://test.controller.address/"; // musi mieć / na końcu (testy tworzenia kontekstu WS-Fed!)


        /// <summary>
        /// Tworzy kontekst wywołania kontrolera
        /// </summary>
        public void BuildUpController(
            Controller controller,
            string RequestUri,
            string QueryString,
            StringBuilder responseBuilder
            )
        {
            // ustawienie adresu żądania
            RequestUri = string.IsNullOrEmpty( RequestUri ) ? "http://foo.bar" : RequestUri;
            RequestUri = RequestUri + ( !string.IsNullOrEmpty( QueryString ) ? "?" + QueryString : string.Empty );

            HttpRequest httpRequest     = new HttpRequest( "", RequestUri, QueryString );
            httpRequest.Browser         = this.BrowserCaps;
            httpRequest.ContentEncoding = Encoding.UTF8;
            StringBuilder sb            = responseBuilder != null ? responseBuilder : new StringBuilder();
            StringWriter stringWriter   = new StringWriter( sb );
            HttpResponse httpResponse   = new HttpResponse( stringWriter );

            HttpContext context = new HttpContext( httpRequest, httpResponse );
            HttpContext.Current = context;

            ConfigurationManagerConfigurator.SetConfigurationSystem( new UnitTestConfigurationProvider() );

            RouteTable.Routes.Clear();
            RouteConfig.RegisterRoutes( RouteTable.Routes );

            var routeData                 = new RouteData();
            routeData.Values.Add( "controller", controller.GetType().Name.ToLower().Replace( "controller", "" ) );
            routeData.Route               = RouteTable.Routes[0];

            var contextBase = new HttpContextWrapper( context );
            var requestContext            = new RequestContext( contextBase, routeData );
            var controllerContext         = new ControllerContext( requestContext, controller );
            controllerContext.HttpContext = new HttpContextWrapper( context );
            controller.ControllerContext  = controllerContext;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <remarks>
        /// http://stackoverflow.com/questions/3891640/is-it-possible-to-use-httpbrowsercapabilities-from-a-c-sharp-console-application
        /// </remarks>
        private HttpBrowserCapabilities BrowserCaps
        {
            get
            {
                var userAgent = "Mozilla/5.0 (Windows; U; Windows NT 6.1)";
                var browser = new HttpBrowserCapabilities
                {
                    Capabilities = new Hashtable { { string.Empty, userAgent } }
                };

                var factory = new BrowserCapabilitiesFactory();
                factory.ConfigureBrowserCapabilities( new NameValueCollection(), browser );

                return browser;
            }
        }
    }
}
