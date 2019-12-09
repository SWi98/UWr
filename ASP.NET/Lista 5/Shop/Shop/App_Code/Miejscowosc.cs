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
/// Summary description for Miejscowosc
/// </summary>
public class Miejscowosc
{
	public Miejscowosc()
	{
		//
		// TODO: Add constructor logic here
		//
	}

    public int iD;
    public int ID
    {
        get { return iD; }
        set { iD = value; }

    }
    public string nazwa;
    public string Nazwa
    {
        get { return nazwa; }
        set { nazwa = value; }

    }
}
