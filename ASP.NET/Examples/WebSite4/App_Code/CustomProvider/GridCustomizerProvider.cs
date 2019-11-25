using System;
using System.Collections.Generic;
using System.Text;

using System.Web;
using System.Web.UI.WebControls;
using System.Configuration.Provider;

/// <summary>
/// Abstrakcyjna specyfikacja dostawcy
/// 
/// Ten dostawca ma jedn¹ metodê, s³u¿¹c¹ do kustomizacji siatki
/// </summary>
    public abstract class GridCustomizerProvider : ProviderBase
    {
        public abstract void CustomizeGridView( GridView Grid );
    }

    public class GridCustomizerProviderCollection : ProviderCollection
    {
        public new GridCustomizerProvider this[string name]
        {
            get { return (GridCustomizerProvider)base[name]; }
        }

        public override void Add( ProviderBase provider )
        {
            if ( provider == null )
                throw new ArgumentNullException( "provider" );

            if ( !( provider is GridCustomizerProvider ) )
                throw new ArgumentException
                    ( "Invalid provider type", "provider" );

            base.Add( provider );
        }
    }
