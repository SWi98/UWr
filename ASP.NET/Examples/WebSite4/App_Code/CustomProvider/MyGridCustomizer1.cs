using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

/// <summary>
/// Konkretny dostawca
/// </summary>
public class MyGridCustomizer1 : GridCustomizerProvider
{
	public MyGridCustomizer1()
	{
	}

    public override void CustomizeGridView(System.Web.UI.WebControls.GridView Grid)
    {
        // 1. alternating row style - "dark"
        Grid.AlternatingRowStyle.CssClass = "dark";

        // 2. pager only on bottom
        Grid.PagerSettings.Position = PagerPosition.Bottom;
    }

}
