<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Login.aspx.cs" Inherits="Zadanie8.Login" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Email address:
            <asp:TextBox ID="UserEmail" runat="server" />
            <asp:RequiredFieldValidator ID="RequiredFieldValidator1" 
                ErrorMessage="Enter e-mail address" 
                ControlToValidate ="UserEmail"
                runat="server" />
            <br /><br />
            Password:                   
            <asp:TextBox ID="UserPassword" TextMode="Password" runat="server"/>
            <asp:RequiredFieldValidator ID="RequiredFieldValidator2"
                ErrorMessage="Enter password"
                ControlToValidate="UserPassword"
                runat ="server" />
            <br /><br />
            <asp:Button runat="server" ID="Button1" text="Submit" OnClick="SubmitUser"/>
        </div>
    </form>
</body>
</html>
