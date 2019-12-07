using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Security.Cryptography;

namespace Shop
{
    public partial class SignUp : System.Web.UI.Page
    {
        private string RandomString(int length)
        {
            var AllChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-=_+[]{}|;:'\"/?.>,<";
            StringBuilder Res = new StringBuilder();
            var random = new Random();
            for(int i = 0; i < length; i++)
            {
                Res.Append(AllChars[random.Next(0, AllChars.Length)]);
            }
            return Res.ToString();
        }

        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void SignUpButton_Click(object sender, EventArgs e)
        {
            // TO DO - Checking if username/email is already taken
            string username = NewUsername.Text;
            string email = NewEmail.Text;
            string password = NewPassword.Text;

            var cs = ConfigurationManager.AppSettings["ShopDB"];

            using(var PasswordDC = new PasswordDataContext(cs))
            using(var UserDC = new UserDataContext(cs))
            using(var UserRolesDC = new UserRolesDataContext(cs))
            using(var RolesDC = new RolesDataContext(cs))
            {
                User newUser = new User();
                Password newPassword = new Password();

                newUser.username = username;
                newUser.email_address = email;
                UserDC.Users.InsertOnSubmit(newUser);
                UserDC.SubmitChanges();

                RIPEMD160 ripemd160 = RIPEMD160.Create();
                int Iterations = 20;
                string Salt = RandomString(20);

                byte[] passwordBytes = System.Text.ASCIIEncoding.ASCII.GetBytes(password + Salt);
                byte[] encryptedBytes = passwordBytes;
                for (int i = 0; i < Iterations; i++)
                {
                    encryptedBytes = ripemd160.ComputeHash(encryptedBytes);
                }

                newPassword.id = newUser.id;
                newPassword.salt = Salt;
                newPassword.iterations = Iterations;
                newPassword.date = DateTime.Now;
                newPassword.hash = System.Text.ASCIIEncoding.ASCII.GetString(encryptedBytes);
                PasswordDC.Passwords.InsertOnSubmit(newPassword);
                PasswordDC.SubmitChanges();

                string RoleName = "User";
                var RoleNameID = (from u in RolesDC.Roles.ToList()
                                  where u.name == RoleName
                                  select u.id).First();

                UserRole newUserRole = new UserRole();
                newUserRole.user_id = newUser.id;
                newUserRole.role_id = RoleNameID;
                UserRolesDC.UserRoles.InsertOnSubmit(newUserRole);
                UserRolesDC.SubmitChanges();
            }

            Response.Redirect("Login.aspx");
        }
    }
}