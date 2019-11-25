using System;
using System.Collections;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;

public partial class Default2 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!this.IsPostBack)
            ListView1.DataBind();
    }

    protected void ListView1_ItemCommand(object sender, ListViewCommandEventArgs e)
    {
        switch (e.CommandName)
        {
            case "ShowInsertTemplate":

                ListView1.InsertItemPosition = InsertItemPosition.FirstItem;
                ListView1.DataBind();
                ListView1.InsertItem.DataBind();

                break;

            case "HideInsertTemplate":

                ListView1.InsertItemPosition = InsertItemPosition.None;

                break;

            case "DownloadXml":

                int osobaId = Convert.ToInt32(e.CommandArgument);
                Osoba o = Model.Instance.Osoby[osobaId];

                Response.Clear();
                Response.AppendHeader("Content-Type", "text/xml");
                Response.AppendHeader("Content-Disposition", "attachment; filename=kartoteka.xml");

                Response.Write(o.Xml);

                Response.Flush();
                Response.End();

                break;

        }
    }

    protected void ObjectDataSource1_Updating(object sender, ObjectDataSourceMethodEventArgs e)
    {
        // do metody biznesowej trzeba w e przekazać to, czego spodziewa się sygnatura metody Update

        // najpierw muszę dostać ID

        // metoda 1. 
        int ID = (int)e.InputParameters["ID"];

        // metoda 2.
        int ID2 = (int)ListView1.DataKeys[ListView1.EditIndex].Value;

        // czytanie nowych wartości 
        string Nazwisko = ((TextBox)ListView1.EditItem.FindControl( "NazwiskoEdit" )).Text;
        string Imie = ((TextBox)ListView1.EditItem.FindControl("ImieEdit")).Text;
        int ID_MSC_UR = Convert.ToInt32(((DropDownList)ListView1.EditItem.FindControl("MiejscowoscEdit")).SelectedValue);

        // wpisanie nowych wartości do obiektu
        Osoba Osoba = Model.Instance.Osoby[ID];
        Osoba.Imie = Imie;
        Osoba.Nazwisko = Nazwisko;
        Osoba.ID_MIEJSCOWOSC = ID_MSC_UR;

        // wpisanie parametrów do metody biznesowej
        e.InputParameters.Clear();
        e.InputParameters.Add("Osoba", Osoba);
    }
    protected void ObjectDataSource1_Deleting(object sender, ObjectDataSourceMethodEventArgs e)
    {
        // do metody biznesowej trzeba w e przekazać to, czego spodziewa się sygnatura metody Update
        // jw, do uzupełnienia
    }
    protected void ObjectDataSource1_Updated(object sender, ObjectDataSourceStatusEventArgs e)
    {
        ListView1.DataBind();
    }
    protected void ObjectDataSource1_Inserting(object sender, ObjectDataSourceMethodEventArgs e)
    {
        Osoba Osoba = new Osoba();

        // czytanie nowych wartości 
        string Nazwisko = ((TextBox)ListView1.InsertItem.FindControl("NazwiskoInsert")).Text;
        string Imie = ((TextBox)ListView1.InsertItem.FindControl("ImieInsert")).Text;
        int ID_MSC_UR = Convert.ToInt32(((DropDownList)ListView1.InsertItem.FindControl("MiejscowoscInsert")).SelectedValue);

        // wpisanie nowych wartości do obiektu
        Osoba.Imie = Imie;
        Osoba.Nazwisko = Nazwisko;
        Osoba.ID_MIEJSCOWOSC = ID_MSC_UR;

        // wpisanie parametrów do metody biznesowej
        e.InputParameters.Clear();
        e.InputParameters.Add("Osoba", Osoba);
    }
    protected void ObjectDataSource1_Inserted(object sender, ObjectDataSourceStatusEventArgs e)
    {
        ListView1.InsertItemPosition = InsertItemPosition.None;
        ListView1.DataBind();
    }
}
