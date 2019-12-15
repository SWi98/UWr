<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="NewItem.aspx.cs" Inherits="Shop.NewItem" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style>
        body{
            margin: 0px;
        }
        .name-field{
            width: 280px;
        }
        .price-field{
            width: 60px;
        }
        .url-field{
            width: 280px;
        }
        .table1{
          border-collapse: collapse;
          border: 1px black solid;
        }
        .topbar{
            background-color: #333344;
            overflow: hidden;
        }
        .topbar a{
            color: #f2f2f2;
            text-align: center;
            padding: 14px 16px;
            text-decoration: none;
            font-size: 17px;
        }
        .topbar a:hover {
            background-color: #ddd;
            color: black;
        }
        .topbar p{
            color: #f2f2f2;
            text-align: center;
            text-decoration: none;
            font-size: 17px;
            display: inline;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div class="topbar">
        <table style="width: 100%; padding-bottom: 20px">
            <tr>                
                <td style="width: 25%">
                    <a href ="Login.aspx">Strona logowania</a>
                </td>
                <td style="width: 25%">
                    <%if (User.Identity.IsAuthenticated){ %>
                        <a href ="Cart.aspx">Koszyk</a>
                    <%} %>
                </td>
                <td style="width: 25%">
                    <%if (User.Identity.IsAuthenticated){ %>
                        <p>Zalogowany użytkownik: <%=User.Identity.Name%></p>
                    <%} %>
                </td>
                <td style="width: 25%">
                    <%if (User.IsInRole("Admin")){ %>
                    <a href="MainPage.aspx">Wróć do strony głównej</a>
                    <%} %>
                </td>
            </tr>
        </table>
        </div>
        <div>
            <table class="table1" style="margin-top: 10px; margin-left: 10px">
                <tr>
                    <td>Nazwa przedmiotu: </td>
                    <td>
                        <asp:TextBox runat="server" ID="ItemNameTextBox" CssClass="name-field" />
                    </td>
                </tr>
                <tr>
                    <td>Cena:</td>
                    <td>
                        <asp:TextBox runat="server" ID="ItemPriceTextBox" CssClass="price-field"/>
                        <asp:CompareValidator runat="server" ID="PriceValidator" Operator="DataTypeCheck"
                            Type="Double" ControlToValidate="ItemPriceTextBox" ErrorMessage="Wymagana liczba" />
                    </td>
                </tr>
                <tr>
                    <td>Opis:</td>
                    <td>
                        <asp:TextBox runat="server" ID="ItemDescTextBox" TextMode="MultiLine" rows="10" CssClass="name-field" />
                    </td>
                </tr>
                <tr>
                    <td>Adres URL zdjęcia:</td>
                    <td>
                        <asp:TextBox runat="server" ID="ItemImageURLTextBox" TextMode="Url" CssClass="url-field" />
                    </td>
                </tr>
            </table>
        </div>
        <br />
        <div style="margin-left: 10px;">
            <asp:Button runat="server" ID="SubmitItemButton" OnClick="SubmitItemButton_Click" Text="Dodaj przedmiot"/>
            <br />
            <asp:Label runat="server" ID="Label1"></asp:Label>
        </div>
    </form>
</body>
</html>
