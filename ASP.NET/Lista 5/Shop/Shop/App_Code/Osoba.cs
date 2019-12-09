//using System;
//using System.Data;
//using System.Configuration;
//using System.Web;
//using System.Web.Security;
//using System.Web.UI;
//using System.Web.UI.WebControls;
//using System.Web.UI.WebControls.WebParts;
//using System.Web.UI.HtmlControls;

///// <summary>
///// Summary description for Osoba
///// </summary>
//public class Osoba : IFormattable
//{
//    public Osoba()
//    {
//    }

//    public int iD;
//    public int ID
//    {
//        get { return iD; }
//        set { iD = value; }

//    }
//    public int iD_MIEJSCOWOSC;
//    public int ID_MIEJSCOWOSC
//    {
//        get { return iD_MIEJSCOWOSC; }
//        set { iD_MIEJSCOWOSC = value; }

//    }
//    public string nazwisko;
//    public string Nazwisko
//    {
//        get { return nazwisko; }
//        set { nazwisko = value; }

//    }
//    public string imie;
//    public string Imie
//    {
//        get { return imie; }
//        set { imie = value; }

//    }

//    public Miejscowosc MiejscowoscUr
//    {
//        get
//        {
//            foreach (Miejscowosc m in Model.Instance.Miejscowosci)
//                if (m.ID == this.ID_MIEJSCOWOSC)
//                    return m;

//            return null;
//        }
//        set
//        {
//            ID_MIEJSCOWOSC = value.ID;
//        }
//    }

//    public Osoba This
//    {
//        get
//        {
//            return this;
//        }
//    }

//    #region IFormattable Members

//    public string ToString(string format, IFormatProvider formatProvider)
//    {
//        switch (format)
//        {
//            case "u" :
//                return string.Format("{0} {1} [ur. {2}]", Nazwisko, Imie, MiejscowoscUr.Nazwa );
//            default :
//                return string.Format("{0} {1}", Nazwisko, Imie);
//        }
//    }

//    #endregion
//}
