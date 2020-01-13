using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Web;
using System.Web.Mvc;

namespace MvcApplication3.Custom
{
    public static class CustomHtmlHelper
    {
        /// <summary>
        /// Usage Html.CustomTextBox( "foo" )
        /// </summary>
        /// <param name="htmlHelper"></param>
        /// <param name="name"></param>
        /// <returns></returns>
        public static HtmlString CustomTextBox( this HtmlHelper htmlHelper, string name, object value )
        {
            TagBuilder tb = new TagBuilder( "input" );

            tb.MergeAttribute( "type", "text" );
            tb.MergeAttribute( "name", name );
            tb.MergeAttribute( "value", value.ToString() );

            return new HtmlString( tb.ToString() );
        }

        public static HtmlString CustomTextBoxFor<TModel, TProperty>( 
            this HtmlHelper<TModel> htmlHelper, 
            Expression<Func<TModel, TProperty>> Property )
        {
            TagBuilder tb = new TagBuilder( "input" );

            tb.MergeAttribute( "type", "text" );

            string name = ExpressionHelper.GetExpressionText( Property );

            tb.MergeAttribute( "name", name );
            
            object value = ModelMetadata.FromLambdaExpression( Property, htmlHelper.ViewData ).Model;

            tb.MergeAttribute( "value", value.ToString() );

            return new HtmlString( tb.ToString() );
        }
    }
}