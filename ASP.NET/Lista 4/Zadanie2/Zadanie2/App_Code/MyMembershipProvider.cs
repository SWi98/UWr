using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Security.Cryptography;
using System.Configuration;
using Zadanie2;

public class MyMembershipProvider : MembershipProvider
{
    public MyMembershipProvider()
    {

    }
    public override bool EnablePasswordRetrieval => throw new NotImplementedException();

    public override bool EnablePasswordReset => throw new NotImplementedException();

    public override bool RequiresQuestionAndAnswer => throw new NotImplementedException();

    public override string ApplicationName { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }

    public override int MaxInvalidPasswordAttempts => throw new NotImplementedException();

    public override int PasswordAttemptWindow => throw new NotImplementedException();

    public override bool RequiresUniqueEmail => throw new NotImplementedException();

    public override MembershipPasswordFormat PasswordFormat => throw new NotImplementedException();

    public override int MinRequiredPasswordLength => throw new NotImplementedException();

    public override int MinRequiredNonAlphanumericCharacters => throw new NotImplementedException();

    public override string PasswordStrengthRegularExpression => throw new NotImplementedException();

    public override bool ChangePassword(string username, string oldPassword, string newPassword)
    {
        throw new NotImplementedException();
    }

    public override bool ChangePasswordQuestionAndAnswer(string username, string password, string newPasswordQuestion, string newPasswordAnswer)
    {
        throw new NotImplementedException();
    }

    public override MembershipUser CreateUser(string username, string password, string email, string passwordQuestion, string passwordAnswer, bool isApproved, object providerUserKey, out MembershipCreateStatus status)
    {
        throw new NotImplementedException();
    }

    public override bool DeleteUser(string username, bool deleteAllRelatedData)
    {
        throw new NotImplementedException();
    }

    public override MembershipUserCollection FindUsersByEmail(string emailToMatch, int pageIndex, int pageSize, out int totalRecords)
    {
        throw new NotImplementedException();
    }

    public override MembershipUserCollection FindUsersByName(string usernameToMatch, int pageIndex, int pageSize, out int totalRecords)
    {
        throw new NotImplementedException();
    }

    public override MembershipUserCollection GetAllUsers(int pageIndex, int pageSize, out int totalRecords)
    {
        throw new NotImplementedException();
    }

    public override int GetNumberOfUsersOnline()
    {
        throw new NotImplementedException();
    }

    public override string GetPassword(string username, string answer)
    {
        throw new NotImplementedException();
    }

    public override MembershipUser GetUser(object providerUserKey, bool userIsOnline)
    {
        throw new NotImplementedException();
    }

    public override MembershipUser GetUser(string username, bool userIsOnline)
    {
        throw new NotImplementedException();
    }

    public override string GetUserNameByEmail(string email)
    {
        throw new NotImplementedException();
    }

    public override string ResetPassword(string username, string answer)
    {
        throw new NotImplementedException();
    }

    public override bool UnlockUser(string userName)
    {
        throw new NotImplementedException();
    }

    public override void UpdateUser(MembershipUser user)
    {
        throw new NotImplementedException();
    }

    public override bool ValidateUser(string username, string password)
    {

        var cs = ConfigurationManager.AppSettings["UDB"];
        using (var UDB = new UserDataContext(cs))
        using (var PDB = new PasswordDataContext(cs))
        {
            var users = UDB.UserInfos.ToList();
            var passwords = PDB.Passwords.ToList();
            var id = (from u in users
                      where u.Username == username
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
                if (EncryptedPassword == userPassword.First())
                {
                    return true;
                }

            }
            return false;
        }
    }
}
