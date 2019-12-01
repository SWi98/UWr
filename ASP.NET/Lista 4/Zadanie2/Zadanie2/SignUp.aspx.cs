using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Security.Cryptography;

namespace Zadanie2
{
    public partial class SignUp : System.Web.UI.Page
    {
        private string RandomString(int length)
        {
            var AllChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-=_+[]{}|;:'\"/?.>,<";
            var RandomChars = new char[length];
            var random = new Random();
            for (int i = 0; i < length; i++)
            {
                RandomChars[i] = AllChars[random.Next(length)];
            }
            return new string(RandomChars);
        }

        private void CreateUser(string name, string password)
        {
            var cs = ConfigurationManager.AppSettings["UDB"];
            using (var UDB = new UserDataContext(cs))
            using (var PDB = new PasswordDataContext(cs))
            {
                var users = UDB.UserInfos.ToList();
                var passwords = PDB.Passwords.ToList();
                int? newID;

                if (users.Any())
                {
                    var lastRecord = (from u in users
                                      orderby u.ID descending
                                      select u).First();
                    newID = lastRecord.ID + 1;
                    UDB.ExecuteCommand("INSERT INTO UserCatalog.dbo.UserInfo (ID, Username)" +
                        "VALUES ({0}, {1})", newID, name);
                }

                else        // If there are no users, new ID must be 1
                {
                    newID = 1;
                    UDB.ExecuteCommand("INSERT INTO UserCatalog.dbo.UserInfo (ID, Username)" +
                        "VALUES ({0}, {1})", newID, name);
                }
                int Iterations = 1;
                RIPEMD160 ripemd160 = RIPEMD160.Create();
                string Salt = RandomString(15);
                byte[] PasswordBytes = System.Text.Encoding.ASCII.GetBytes(password + Salt);
                byte[] EncryptedBites = ripemd160.ComputeHash(PasswordBytes);
                string EncryptedPassword = System.Text.Encoding.ASCII.GetString(EncryptedBites);
                for (int i = 2; i <= Iterations; i++)
                {
                    EncryptedBites = ripemd160.ComputeHash(System.Text.Encoding.ASCII.GetBytes(EncryptedPassword));
                    EncryptedPassword = System.Text.Encoding.ASCII.GetString(EncryptedBites);
                }

                PDB.ExecuteCommand("INSERT INTO UserCatalog.dbo.Password (ID, Salt, Value, Iterations, Date)" +
                    "VALUES ({0}, {1}, {2}, {3}, {4})", newID, Salt, EncryptedPassword, Iterations,
                    DateTime.Now);
            }

        }

        private void Check(string name, string password)
        {
            var cs = ConfigurationManager.AppSettings["UDB"];
            using (var UDB = new UserDataContext(cs))
            using (var PDB = new PasswordDataContext(cs))
            {
                var users = UDB.UserInfos.ToList();
                var passwords = PDB.Passwords.ToList();
                var id = (from u in users
                          where u.Username == name
                          select u.ID);
                if (id.Any())
                {
                    RIPEMD160 ripemd160 = RIPEMD160.Create();

                    var salt = (from p in passwords
                                where p.ID == id.First()
                                select p.Salt);
                    var iterations = (from p in passwords
                                      where p.ID == id.First()
                                      select p.Iterations);
                    var userPassword = (from p in passwords
                                        where p.ID == id.First()
                                        select p.Value);
                    byte[] PasswordBytes = System.Text.Encoding.ASCII.GetBytes(password + salt.First());
                    byte[] EncryptedBites = ripemd160.ComputeHash(PasswordBytes);
                    string EncryptedPassword = System.Text.Encoding.ASCII.GetString(EncryptedBites);
                    for (int i = 2; i <= iterations.First(); i++)
                    {
                        EncryptedBites = ripemd160.ComputeHash(System.Text.Encoding.ASCII.GetBytes(EncryptedPassword));
                        EncryptedPassword = System.Text.Encoding.ASCII.GetString(EncryptedBites);
                    }
                    Response.Write(EncryptedPassword);
                    Response.Write("<br/>");
                    Response.Write(userPassword.First());
                    Response.Write("<br/>");
                    if (EncryptedPassword == userPassword.First())
                    {
                        Response.Write("TRUE");
                    }

                }
                Response.Write("FALSE");
            }
        }

        public void CreateNewUser(object sender, EventArgs e)
        {
            CreateUser(NewUsername1.Text, NewPassword1.Text);
            Response.Redirect("LoginPage.aspx");
        }
        protected void Page_Load(object sender, EventArgs e)
        {
        }
    }
}