using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Web;
using System.Web.Security;
using Zadanie2;

public class MyRoleProvider : RoleProvider
{
    public MyRoleProvider()
    {

    }
    public override string ApplicationName { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }

    public override void AddUsersToRoles(string[] usernames, string[] roleNames)
    {
        if (usernames.Length == 1 && roleNames.Length == 1)
        {
            string username = usernames[0];
            string roleName = roleNames[0];
            var cs = ConfigurationManager.AppSettings["UDB"];
            using (var UserRolesDB = new UserRolesDataContext(cs))
            using (var RolesDB = new RolesDataContext(cs))
            {
                UserRole userRole = new UserRole();
                userRole.Username = username;

                var AllRoles = RolesDB.Roles.ToList();
                var RoleID = (from r in AllRoles
                              where r.Role1 == roleName
                              select r.ID);

                if (!RoleID.Any())
                {
                    throw new Exception("Role " + roleName + " does not exist");
                }

                UserRolesDB.ExecuteCommand("INSERT INTO UserCatalog.dbo.UserRoles " +
                    "(Username, Role_ID) VALUES ({0}, {1})", username, RoleID.First());
            }
        }
        else
        {
            throw new NotImplementedException();
        }
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
        var cs = ConfigurationManager.AppSettings["UDB"];
        using (var UserRolesDB = new UserRolesDataContext(cs))
        using (var RolesDB = new RolesDataContext(cs))
        {
            var AllRoles = RolesDB.Roles.ToList();
            var AllUserRoles = UserRolesDB.UserRoles.ToList();
            var RoleID = (from ur in AllUserRoles
                          where ur.Username == username
                          select ur.Role_ID);
            if (!RoleID.Any())
            {
                throw new Exception("User with no role");
            }

            var RoleName = (from r in AllRoles
                            where r.ID == RoleID.First()
                            select r.Role1).First();            //Role1? 

            string[] res = { RoleName };
            return res;
        }
    }

    public override string[] GetUsersInRole(string roleName)
    {
        throw new NotImplementedException();
    }

    public override bool IsUserInRole(string username, string roleName)
    {
        var cs = ConfigurationManager.AppSettings["UDB"];
        using(var UserRolesDB = new UserRolesDataContext(cs))
        using(var RolesDB = new RolesDataContext(cs))
        {
            var AllRoles = RolesDB.Roles.ToList();
            var AllUserRoles = UserRolesDB.UserRoles.ToList();
            var RoleID = (from ur in AllUserRoles
                          where ur.Username == username
                          select ur.ID);
            if(!RoleID.Any())
            {
                throw new Exception("User with no role");
            }

            var CorrectRoleName = (from r in AllRoles
                            where r.ID == RoleID.First()
                            select r.Role1).First();            //Role1? 

            return roleName == CorrectRoleName;
        }

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
