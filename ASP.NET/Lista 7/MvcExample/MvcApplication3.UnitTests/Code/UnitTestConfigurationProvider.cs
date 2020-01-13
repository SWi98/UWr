using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Configuration;
using System.Configuration.Internal;
using System.Linq;
using System.Web;
using System.Web.Configuration;

namespace MvcApplication3.Custom
{
    internal class UnitTestConfigurationProvider : IInternalConfigSystem
    {
        #region IInternalConfigSystem Members

        public object GetSection( string configKey )
        {
            switch ( configKey )
            {
                case "appSettings" :
                    return AppSettings();
                case "system.web/caching/cache" :
                    return GetCacheSection();
                case "system.web/compilation" :
                    return new CompilationSection();
                case "system.web/authentication" :
                    return GetAuthenticationSection();
                case "system.web/globalization" :
                    return new GlobalizationSection();
                case "system.web/httpCookies" :
                    return GetCookiesSection();
                case "system.web/httpModules" :
                    return new HttpModulesSection();
                case "system.web/httpRuntime" :
                    return new HttpRuntimeSection();
                case "system.web/machineKey" :
                    return new MachineKeySection();
                case "system.web/membership" :
                    return GetMembershipSection();
                case "system.web/urlMappings" :
                    return new UrlMappingsSection();
                default :
                    return null;
            }
        }

        public void RefreshConfig( string sectionName )
        {
            
        }

        public bool SupportsUserConfig
        {
            get 
            {
                return true;
            }
        }



        #endregion

        private NameValueCollection AppSettings()
        {
            NameValueCollection section = new NameValueCollection();

            return section;
        }

        private AuthenticationSection GetAuthenticationSection()
        {
            AuthenticationSection section = new AuthenticationSection();

            section.Mode = AuthenticationMode.Forms;

            return section;
        }

        private CacheSection GetCacheSection()
        {
            CacheSection section = new CacheSection();

            return section;
        }

        private MembershipSection GetMembershipSection()
        {
            MembershipSection section = new MembershipSection();
            section.DefaultProvider = "default";

            ConfigurationProperty _propProviders =
                (ConfigurationProperty)typeof( MembershipSection ).InvokeMember( "_propProviders", System.Reflection.BindingFlags.Static | System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.GetField, null, typeof( MembershipSection ), null );

            var collection = new System.Configuration.ProviderSettingsCollection();
            collection.Add( new System.Configuration.ProviderSettings()
                {
                    Name = "default",
                    Type = "MvcApplication3.Custom.CustomMembershipProvider, MvcApplication3"
                } );

            // section[_propProviders] = collection;
            typeof( ConfigurationElement ).InvokeMember( "SetPropertyValue", System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.InvokeMethod, null, section, new object[] { _propProviders, collection, false } );

            return section;
        }

        private HttpCookiesSection GetCookiesSection()
        {
            HttpCookiesSection section = new HttpCookiesSection();

            return section;
        }
    }
}
