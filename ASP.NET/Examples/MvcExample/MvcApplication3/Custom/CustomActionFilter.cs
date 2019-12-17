using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace MvcApplication3.Custom
{
    public class CustomActionFilter : ActionFilterAttribute, IActionFilter
    {
        #region IActionFilter Members

        void IActionFilter.OnActionExecuted( ActionExecutedContext filterContext )
        {
            //throw new NotImplementedException();
        }

        void IActionFilter.OnActionExecuting( ActionExecutingContext filterContext )
        {
            string controllerName = filterContext.ActionDescriptor.ControllerDescriptor.ControllerName;
            string actionName = filterContext.ActionDescriptor.ActionName;
        }

        #endregion
    }
}