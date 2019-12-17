using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MvcApplication3.Models.CustomHelperBinder;

namespace MvcApplication3.Custom
{
    public class CustomBinder : IModelBinder
    {
        #region IModelBinder Members

        public object BindModel( 
            ControllerContext controllerContext, 
            ModelBindingContext bindingContext )
        {
            // nazwa zmiennej modelu (parametr metody akcji)
            string name = bindingContext.ModelName;

            var result = bindingContext.ValueProvider.GetValue( name );
            if ( result != null )
            {
                string value = result.AttemptedValue;

                return value.Split( new[] { ',' } );
            }
            else
                return Enumerable.Empty<string>();
        }

        #endregion
    }
}