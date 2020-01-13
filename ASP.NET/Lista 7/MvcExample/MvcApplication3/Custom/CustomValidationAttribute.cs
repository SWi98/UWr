using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace MvcApplication3.Custom
{
    [AttributeUsage( AttributeTargets.Property, AllowMultiple = true )]
    public class OurCustomValidationAttribute : ValidationAttribute
    {
        private string _value { get; set; }
        public OurCustomValidationAttribute( string value )
        {
            this._value = value;
        }

        protected override ValidationResult IsValid( object value, ValidationContext validationContext )
        {
            object property = validationContext.ObjectInstance.GetType().InvokeMember( validationContext.DisplayName, System.Reflection.BindingFlags.GetProperty | System.Reflection.BindingFlags.Public | System.Reflection.BindingFlags.Instance, null, validationContext.ObjectInstance, null );
            if ( property is string && ( (string)property ) == _value )
                return ValidationResult.Success;
            else
                return new ValidationResult( "wrong value" );
        }
    }
}