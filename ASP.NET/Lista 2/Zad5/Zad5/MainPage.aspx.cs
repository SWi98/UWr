using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Zad5
{
    public partial class MainPage : System.Web.UI.Page
    {   
        private bool ValidateName()
        {
            if (Name.Text.Length == 0)
                return false;
            foreach(char c in Name.Text)
            {
                if (!Char.IsLetter(c) && c != ' ')
                    return false;
            }
            return true;
        }

        private bool ValidateSurname()
        {
            if (Surname.Text.Length == 0)
                return false;
            foreach(char c in Surname.Text)
            {
                if (!Char.IsLetter(c) && c != ' ')
                    return false;
            }
            return true;
        }

        private bool ValidateDate()
        {
            if (Date.Text.Length == 0)
                return false;
            return true;
        }

        private bool Valid(string val)
        {
            foreach(char c in val)
            {
                if (!Char.IsDigit(c))
                    return false;
            }
            return true;
        }
        private bool ValidatePoints()
        {
            if(!Valid(Z1.Text) || !Valid(Z2.Text) || !Valid(Z3.Text) || !Valid(Z4.Text) || !Valid(Z5.Text)
                || !Valid(Z6.Text) || !Valid(Z7.Text) || !Valid(Z8.Text) || !Valid(Z9.Text) || !Valid(Z10.Text))
            {
                return false;
            }
            return true;
        }

        public void SubmitData(object sender, EventArgs e)
        {
            bool n = ValidateName(), s = ValidateSurname(),
                p = ValidatePoints(), d = ValidateDate();
            if (!n)
            {
                Response.Write("<font color = \"red\">Błędne imię </font><br/>");
            }
            if (!s)
            {
                Response.Write("<font color = \"red\">Błędne nazwisko </font><br/>");
            }
            if (!p)
            {
                Response.Write("<font color = \"red\">Niepoprawne punkty </font><br/>");
            }
            if (!d)
            {
                Response.Write("<font color = \"red\">Nie wybrano daty </font><br/>");
            }
            else if(n && s && p)
            {
                Response.Redirect("Table.aspx?N=" + Name.Text + "&S=" +Surname.Text + "&C=" + Class.Text + 
                    "&D=" + Date.Text +  "&Z1=" + Z1.Text + "&Z2=" + Z2.Text + "&Z3=" + Z3.Text + 
                    "&Z4=" + Z4.Text + "&Z5=" + Z5.Text + "&Z6=" + Z6.Text + "&Z7=" + Z7.Text + "&Z8=" + 
                    Z8.Text + "&Z9=" + Z9.Text + "&Z10=" + Z10.Text);

            }
        }

        protected void Page_Load(object sender, EventArgs e)
        {

        }
    }
}