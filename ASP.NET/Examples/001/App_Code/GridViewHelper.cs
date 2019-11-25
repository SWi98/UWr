using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

public class GridViewHelper
{
    public static void EnableTHeadTFooter( GridView grid )
    {
        if ( grid.Rows.Count > 0 )
        {
            //This replaces <td> with <th> and adds the scope attribute
            grid.UseAccessibleHeader = true;

            //This will add the <thead> and <tbody> elements
            if ( grid.ShowHeader )
                grid.HeaderRow.TableSection = TableRowSection.TableHeader;

            //This adds the <tfoot> element. Remove if you don't have a footer row
            //if ( grid.ShowFooter )
            //     grid.FooterRow.TableSection = TableRowSection.TableFooter;
        }
    }

    public static void InjectConfirm( GridView gridView )
    {
        InjectConfirm( gridView, "Czy na pewno usun¹æ element?" );
    }

    public static void InjectConfirm( GridView gridView, string message )
    {
        InjectConfirm( gridView, "Delete", message );
    }

    public static void InjectConfirm( GridView gridView, string commandName, string message )
    {
        foreach ( GridViewRow row in gridView.Rows )
            foreach ( Control cellControl in row.Controls )
                foreach ( Control control in cellControl.Controls )
                    if ( control is LinkButton )
                    {
                        LinkButton imageButton = (LinkButton)control;

                        if ( imageButton.CommandName.ToLower() == commandName.ToLower() )
                        {
                            string existingOnClick = imageButton.Attributes["onclick"];
                            if ( !string.IsNullOrEmpty( existingOnClick ) )
                                imageButton.Attributes["onclick"] = string.Format( "if ( !window.confirm('{0}') ) return false; {1}", message, existingOnClick );
                            else
                                imageButton.Attributes["onclick"] = string.Format( "if ( !window.confirm('{0}') ) return false", message );
                        }
                    }
    }

    public static void ShowButton( GridViewRow row, string commandName, bool visible )
    {
        foreach ( TableCell cell in row.Cells )
            foreach ( Control control in cell.Controls )
                if ( control is ImageButton )
                {
                    ImageButton imageButton = (ImageButton)control;

                    if ( imageButton.CommandName.ToLower() == commandName.ToLower() )
                        imageButton.Visible = visible;
                }
    }

    public static void EnableButton( GridViewRow row, string commandName, bool enabled )
    {
        foreach ( TableCell cell in row.Cells )
            foreach ( Control control in cell.Controls )
                if ( control is ImageButton )
                {
                    ImageButton imageButton = (ImageButton)control;

                    if ( imageButton.CommandName.ToLower() == commandName.ToLower() )
                        imageButton.Enabled = enabled;
                }
    }
}
