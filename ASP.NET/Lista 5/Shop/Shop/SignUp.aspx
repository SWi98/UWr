<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="SignUp.aspx.cs" Inherits="Shop.SignUp" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <table>
                <tr>
                    <td>Nazwa użytkownika: </td>
                    <td>
                        <asp:TextBox ID="NewUsername" runat="server"/>
                        <asp:RequiredFieldValidator ID="UsernameValidator" runat="server" 
                            ControlToValidate="NewUsername" ForeColor="red" ErrorMessage="Wymagane pole" />
                    </td>
                </tr>
                <tr>
                    <td>E-mail: </td>
                    <td>
                        <asp:TextBox ID="NewEmail" runat="server" TextMode="Email"/>
                        <asp:RequiredFieldValidator ID="EmailValidator" runat="server"
                            ControlToValidate="NewEmail" ForeColor="Red" ErrorMessage="Wymagane pole" />
                    </td>
                </tr>
                <tr>
                    <td>Hasło: </td>
                    <td>
                        <asp:TextBox ID="NewPassword" runat="server" TextMode="Password" />
                        <asp:RequiredFieldValidator ID="PasswordValidator" runat="server"
                            ControlToValidate="NewPassword" ForeColor="Red" ErrorMessage="Wymagane pole" />
                    </td>
                </tr>
                <tr>
                    <td>
                        <asp:Button ID="SignUpButton" runat="server" Text="Załóż konto" OnClick="SignUpButton_Click"/>
                    </td>
                </tr>
            </table>
        </div>
    </form>
</body>
</html>
