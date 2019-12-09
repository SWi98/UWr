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
///// Summary description for Model
///// </summary>
//public class Model
//{
//    public List<Osoba> Osoby = new List<Osoba>();
//    public List<Miejscowosc> Miejscowosci = new List<Miejscowosc>();

//	public Model()
//	{
//        for (int i = 0; i < 100; i++)
//        {
//            Osoba o = new Osoba();
            
//            o.ID = i;
//            o.ID_MIEJSCOWOSC = i % 25;

//            o.Imie = "Imie " + i.ToString();
//            o.Nazwisko = "Nazwisko " + i.ToString();

//            Osoby.Add(o);
//        }

//        for (int j = 0; j < 25; j++)
//        {
//            Miejscowosc m = new Miejscowosc();

//            m.ID = j;

//            m.Nazwa = "Miejscowosc " + j.ToString();

//            Miejscowosci.Add(m);
//        }
//	}

//    public static Model Instance
//    {
//        get
//        {
//            if (HttpContext.Current.Application["model"] == null)
//            {
//                Model model = new Model();
//                HttpContext.Current.Application["model"] = model;
//            }

//            return (Model)HttpContext.Current.Application["model"];
//        }
//    }
//}
