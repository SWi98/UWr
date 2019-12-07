using Shop;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Security.Cryptography;

public class MyMembershipProvider : MembershipProvider
{
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
        var cs = ConfigurationManager.AppSettings["ShopDB"];

        using (var PasswordDC = new PasswordDataContext(cs))
        using (var UserDC = new UserDataContext(cs))
        {
            var UserRecords = UserDC.Users.ToList();
            var PasswordRecords = PasswordDC.Passwords.ToList();
            var CurrentUserID = (from u in UserRecords
                                 where u.username == username
                                 select u.id);
            if (CurrentUserID.Any())
            {
                var passwordRecord = (from p in PasswordRecords
                                      where p.id == CurrentUserID.First()
                                      select p).First();

                RIPEMD160 ripemd160 = RIPEMD160.Create();
                int Iterations = passwordRecord.iterations;
                string Salt = passwordRecord.salt;

                byte[] passwordBytes = System.Text.ASCIIEncoding.ASCII.GetBytes(password + Salt);
                byte[] encryptedBytes = passwordBytes;
                for (int i = 0; i < Iterations; i++)
                {
                    encryptedBytes = ripemd160.ComputeHash(encryptedBytes);
                }

                return System.Text.ASCIIEncoding.ASCII.GetString(encryptedBytes) == passwordRecord.hash;
            }

            return false;
        }
    }
        
}