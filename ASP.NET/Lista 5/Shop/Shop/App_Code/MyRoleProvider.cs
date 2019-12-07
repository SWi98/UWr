using Shop;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Web;
using System.Web.Security;

public class MyRoleProvider : RoleProvider
{
    public override string ApplicationName { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }

    public override void AddUsersToRoles(string[] usernames, string[] roleNames)
    {
        throw new NotImplementedException();
    }

    public override void CreateRole(string roleName)
    {
        throw new NotImplementedException();
    }

    public override bool DeleteRole(string roleName, bool throwOnPopulatedRole)
    {
        throw new NotImplementedException();
    }

    public override string[] FindUsersInRole(string roleName, string usernameToMatch)
    {
        throw new NotImplementedException();
    }

    public override string[] GetAllRoles()
    {
        throw new NotImplementedException();
    }

    public override string[] GetRolesForUser(string username)
    {
        List<string> res = new List<string>();
        var cs = ConfigurationManager.AppSettings["ShopDB"];
        using (var UserRolesDC = new UserRolesDataContext(cs))
        using (var RolesDC = new RolesDataContext(cs))
        using (var UserDC = new UserDataContext(cs))
        {
            var RolesRecords = RolesDC.Roles.ToList();
            var UserRolesRecords = UserRolesDC.UserRoles.ToList();
            var UserRecords = UserDC.Users.ToList();

            var CurrentUserID = (from u in UserRecords
                                 where u.username == username
                                 select u.id).First();

            var CurrentUserRolesIDs = (from ur in UserRolesRecords
                                       where ur.user_id == CurrentUserID
                                       select ur.role_id);

            if (!CurrentUserRolesIDs.Any())
                throw new Exception("Current user has no role!");

            var CurrentUserRoles = (from r in RolesRecords
                                    where CurrentUserRolesIDs.Contains(r.id)
                                    select r.name);

            return CurrentUserRoles.ToArray();
        }
    }

    public override string[] GetUsersInRole(string roleName)
    {
        throw new NotImplementedException();
    }

    public override bool IsUserInRole(string username, string roleName)
    {
        var cs = ConfigurationManager.AppSettings["ShopDB"];
        using (var UserRolesDC = new UserRolesDataContext(cs))
        using (var RolesDC = new RolesDataContext(cs))
        using (var UserDC = new UserDataContext(cs))
        {
            var RolesRecords = RolesDC.Roles.ToList();
            var UserRolesRecords = UserRolesDC.UserRoles.ToList();
            var UserRecords = UserDC.Users.ToList();

            var CurrentUserID = (from u in UserRecords
                                 where u.username == username
                                 select u.id).First();

            var CurrentUserRolesIDs = (from ur in UserRolesRecords
                                    where ur.user_id == CurrentUserID
                                    select ur.role_id);

            if (!CurrentUserRolesIDs.Any())
                throw new Exception("Current user has no role!");

            foreach(var ID in CurrentUserRolesIDs)
            {
                foreach(var RoleRecord in RolesRecords)
                {
                    if (RoleRecord.id == ID && RoleRecord.name == roleName)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    public override void RemoveUsersFromRoles(string[] usernames, string[] roleNames)
    {
        throw new NotImplementedException();
    }

    public override bool RoleExists(string roleName)
    {
        throw new NotImplementedException();
    }
}