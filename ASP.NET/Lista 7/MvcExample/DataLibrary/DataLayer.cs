using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;

namespace DataLibrary
{
    public class DataLayer
    {
        const string key = "__dataprovider";

        public static UserDataContext Current
        {
            get
            {
                if ( HttpContext.Current.Items[key] == null )
                {
                    HttpContext.Current.Items[key] = new UserDataContext();
                }

                return (UserDataContext)HttpContext.Current.Items[key];
            }
        }
    }
}
