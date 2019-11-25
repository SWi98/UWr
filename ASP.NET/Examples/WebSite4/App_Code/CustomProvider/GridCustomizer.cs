using System;
using System.Collections.Generic;
using System.Configuration.Provider;
using System.Text;

using System.Web.UI.WebControls;
using System.Web.Configuration;

/// <summary>
/// Klasa udostêpniaj¹ca statyczne metody opakowuj¹ce wywo³ania
/// ze skonfigurowanego w web.config dostawcy
/// 
/// Proszê zajrzec do web.config jak konkretny dostawca jest skonfigurowany
/// </summary>
    public class GridCustomizer
    {
        static GridCustomizer()
        {
            // Make sure a provider is loaded
            LoadProviders();
        }

        private static GridCustomizerProvider _provider = null;
        private static GridCustomizerProviderCollection _providers = null;
        private static object _lock = new object();

        public GridCustomizerProvider Provider
        {
            get { return _provider; }
        }

        public GridCustomizerProviderCollection Providers
        {
            get { return _providers; }
        }

        public static void CustomizeGridView( GridView Grid )
        {
            // Delegate to the provider
            _provider.CustomizeGridView( Grid );
        }

        private static void LoadProviders()
        {
            // Avoid claiming lock if providers are already loaded
            if ( _provider == null )
            {
                lock ( _lock )
                {
                    // Do this again to make sure _provider is still null
                    if ( _provider == null )
                    {
                        // Get a reference to the <imageService> section
                        GridCustomizerSection section = (GridCustomizerSection)
                            WebConfigurationManager.GetSection
                            ( "system.web/gridCustomizer" );

                        // Load registered providers and point _provider
                        // to the default provider
                        _providers = new GridCustomizerProviderCollection();

                        ProvidersHelper.InstantiateProviders
                            ( section.Providers, _providers,
                            typeof( GridCustomizerProvider ) );
                        _provider = _providers[section.DefaultProvider];

                        if ( _provider == null )
                            throw new ProviderException
                                ( "Unable to load default GridCustomizerProvider" );
                    }
                }
            }
        }
    }
