<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="NewItem.aspx.cs" Inherits="Shop.NewItem" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style>
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
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <table class="table1">
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
        <div>
            <asp:Button runat="server" ID="SubmitItemButton" OnClick="SubmitItemButton_Click" Text="Dodaj przedmiot"/>
        </div>
    </form>
</body>
</html>
