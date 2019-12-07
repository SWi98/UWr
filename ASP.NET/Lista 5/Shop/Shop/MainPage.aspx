<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="MainPage.aspx.cs" Inherits="Shop.MainPage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <%if (User.IsInRole("Admin")){ %>
            <div>
                <a href="NewItem.aspx">Dodaj nowy przedmiot</a>
            </div>
        <%} %>
        <div>

        </div>

    </form>
</body>
</html>
