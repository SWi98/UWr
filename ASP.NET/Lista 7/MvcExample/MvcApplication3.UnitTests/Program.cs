using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MvcApplication3.UnitTests
{
    class Program
    {
        [STAThread]
        static void Main( string[] args )
        {
            NUnit.Gui.AppEntry.Main( new [] { typeof( Program ).Assembly.Location } );
        }
    }
}
