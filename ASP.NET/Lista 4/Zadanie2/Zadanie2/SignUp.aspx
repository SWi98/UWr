<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="SignUp.aspx.cs" Inherits="Zadanie2.SignUp" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Zarejestruj nowe konto:
            <br />
            Nazwa użytkownika:
            <asp:Textbox ID="NewUsername1" runat="server" />
            <asp:RequiredFieldValidator ID="UsernameValidator" runat="server" 
                ControlToValidate="NewUsername1" ForeColor="red" ErrorMessage="Wymagane pole" />
            <br />
            Hasło:
            <asp:TextBox ID="NewPassword1" runat="server" TextMode="Password" />
            <asp:RequiredFieldValidator ID="PasswordValidator" runat="server"
                ControlToValidate="NewPassword1" ForeColor="red" ErrorMessage="Wymagane pole" />
            <br />
            <asp:Button ID="Submit1" runat="server" OnClick="CreateNewUser" />
        </div>
    </form>
</body>
</html>
