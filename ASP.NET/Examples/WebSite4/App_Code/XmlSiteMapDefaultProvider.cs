using System;
using System.Collections.Generic;
using System.Text;
using System.Web;
using System.Web.Security;

    public class XmlSiteMapDefaultProvider : XmlSiteMapProvider
    {
        public override bool IsAccessibleToUser( HttpContext context, SiteMapNode node )
        {
            if ( node.Roles.Count > 0 )
            {
                foreach ( string role in node.Roles )
                    if ( role == "*" &&
                         context.User != null &&
                         context.User.Identity != null &&
                         context.User.Identity.IsAuthenticated
                         )
                        return true;
                    else
                    {
                        if ( context.User != null )
                            if ( context.User.IsInRole( role ) )
                                return true;
                    }

                return false;
            }

            return true;
        }
    }
