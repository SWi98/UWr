using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

/// <summary>
/// Summary description for MyRoleProvider
/// </summary>
public class MyRoleProvider : RoleProvider
{
	public MyRoleProvider()
	{
		//
		// TODO: Add constructor logic here
		//
	}

    public override void AddUsersToRoles(string[] usernames, string[] roleNames)
    {
        throw new Exception("The method or operation is not implemented.");
    }

    public override string ApplicationName
    {
        get
        {
            throw new Exception("The method or operation is not implemented.");
        }
        set
        {
            throw new Exception("The method or operation is not implemented.");
        }
    }

    public override void CreateRole(string roleName)
    {
        throw new Exception("The method or operation is not implemented.");
    }

    public override bool DeleteRole(string roleName, bool throwOnPopulatedRole)
    {
        throw new Exception("The method or operation is not implemented.");
    }

    public override string[] FindUsersInRole(string roleName, string usernameToMatch)
    {
        throw new Exception("The method or operation is not implemented.");
    }

    public override string[] GetAllRoles()
    {
        throw new Exception("The method or operation is not implemented.");
    }

    public override string[] GetRolesForUser(string username)
    {
        return new string[] { username };
    }

    public override string[] GetUsersInRole(string roleName)
    {
        throw new Exception("The method or operation is not implemented.");
    }

    public override bool IsUserInRole(string username, string roleName)
    {
        throw new Exception("The method or operation is not implemented.");
    }

    public override void RemoveUsersFromRoles(string[] usernames, string[] roleNames)
    {
        throw new Exception("The method or operation is not implemented.");
    }

    public override bool RoleExists(string roleName)
    {
        throw new Exception("The method or operation is not implemented.");
    }
}
