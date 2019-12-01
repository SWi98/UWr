using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Security.Cryptography;
using System.Web.UI.WebControls;

namespace Zadanie2
{
    public partial class Login : System.Web.UI.Page
    {
        private string RandomString(int length)
        {
            var AllChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-=_+[]{}|;:'\"/?.>,<";
            var RandomChars = new char[length];
            var random = new Random();
            for(int i = 0; i < length; i++)
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
                for(int i = 2; i <= Iterations; i++)
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
                int? newID;
            }
        }

        protected void Page_Load(object sender, EventArgs e)
        {
            //CreateUser("testowa nazwa", "test");

        }
    }
}