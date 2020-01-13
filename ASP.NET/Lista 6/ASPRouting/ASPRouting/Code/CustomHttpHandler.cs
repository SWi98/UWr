using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ASPRouting.Code
{
    public class CustomHttpHandler : IHttpHandler
    {
        #region IHttpHandler Members

        public bool IsReusable
        {
            get { return true; }
        }

        public void ProcessRequest( HttpContext context )
        {
            string response =
                string.Format( "response from {0}", context.Request.RawUrl );

            context.Response.Write( response );

            /*
            var routeData = context.Request.RequestContext.RouteData.Values;

            string response =
                ( string.Format( "{0} {1} {2}", routeData["tenant"], routeData["siteName"], routeData["pageName"] ) );

            context.Response.Write( response );
             */

        }

        #endregion
    }
}