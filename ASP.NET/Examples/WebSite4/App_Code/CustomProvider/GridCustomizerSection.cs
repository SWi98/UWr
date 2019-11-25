using System;
using System.Collections.Generic;
using System.Text;
using System.Configuration;

/// <summary>
/// Definicja sekcji pliku konfiguracyjnego odnosz¹cego siê do w³asnego dostawcy
/// </summary>
    public class GridCustomizerSection : ConfigurationSection
    {
        [ConfigurationProperty( "providers" )]
        public ProviderSettingsCollection Providers
        {
            get { return (ProviderSettingsCollection)base["providers"]; }
        }

        [StringValidator( MinLength = 1 )]
        [ConfigurationProperty( "defaultProvider",
            DefaultValue = "ONOGridCustomizerProvider" )]

        public string DefaultProvider
        {
            get { return (string)base["defaultProvider"]; }
            set { base["defaultProvider"] = value; }
        }
    }
