using System;
using System.Collections.Generic;
using System.Configuration;
using System.Configuration.Internal;
using System.Linq;
using System.Web;

namespace MvcApplication3.Custom
{
    /// <summary>
    /// Konfiguracja dostawcy informacji o konfiguracji dla System.Configuration
    /// </summary>
    public static class ConfigurationManagerConfigurator
    {
        public static void SetConfigurationSystem( IInternalConfigSystem configSystem )
        {
            Type configurationManagerType = typeof( ConfigurationManager );

            // this does the magic. calls the internal method
            // which allows me to inject a provider
            // why, oh why this is not public?        

            configurationManagerType.InvokeMember(
                "s_initState",
                  System.Reflection.BindingFlags.SetField |
                  System.Reflection.BindingFlags.Static |
                  System.Reflection.BindingFlags.NonPublic,
                  null,
                  configurationManagerType, new object[] { 0 } );

            configurationManagerType.InvokeMember(
                "SetConfigurationSystem",
                 System.Reflection.BindingFlags.InvokeMethod |
                 System.Reflection.BindingFlags.Static |
                 System.Reflection.BindingFlags.NonPublic,
                 null,
                configurationManagerType, new object[] { configSystem, true } );
        }
    }

}