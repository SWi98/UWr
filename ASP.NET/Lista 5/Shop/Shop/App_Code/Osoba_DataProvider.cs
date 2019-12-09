//using System;
//using System.Collections.Generic;
//using System.Data;
//using System.Configuration;
//using System.Web;
//using System.Web.Security;
//using System.Web.UI;
//using System.Web.UI.WebControls;
//using System.Web.UI.WebControls.WebParts;
//using System.Web.UI.HtmlControls;

///// <summary>
///// Summary description for Osoba_DataProvider
///// </summary>
//public class Osoba_DataProvider
//{
//	public Osoba_DataProvider()
//	{
//		//
//		// TODO: Add constructor logic here
//		//
//	}

//    /// <summary>
//    /// Metoda dla źródła danych GridView
//    /// 
//    /// Parametry OrderBy, StartRow i RowCount zdefiniowane są
//    /// w odpowiednich właściwościach źródła danych
//    /// </summary>
//    /// <param name="OrderBy"></param>
//    /// <param name="StartRow"></param>
//    /// <param name="RowCount"></param>
//    /// <returns></returns>
//    public List<Osoba> Retrieve( string OrderBy, int StartRow, int RowCount)
//    {
//        if (RowCount > 0)
//            return Model.Instance.Osoby.GetRange(StartRow, RowCount);
//        else
//            return new List<Osoba>(new Osoba[] { Model.Instance.Osoby[StartRow] } );
//    }

//    /// <summary>
//    /// jw
//    /// </summary>
//    /// <returns></returns>
//    public int SelectCount()
//    {
//        return Model.Instance.Osoby.Count;
//    }

//    /// <summary>
//    /// Metoda dla źródła danych DetailsView
//    /// 
//    /// Parametr ID zdefiniowany jest w sekcji SelectParameters źródła danych
//    /// </summary>
//    /// <param name="ID"></param>
//    /// <returns></returns>
//    public Osoba Retrieve( int ID )
//    {
//        return Model.Instance.Osoby
//            .Find( delegate ( Osoba osoba ) { return osoba.ID == ID; } );
//    }
//}
