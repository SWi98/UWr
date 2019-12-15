<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Cart.aspx.cs" Inherits="Shop.Cart" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style>
        body{
            margin: 0;
        }
        .content{
            /*background-color: #E0FFFF;*/ 
            color: #000000;
        }
        p.table{
            white-space: pre;
        }
        .desc-field{
            width: 300px;
        }
        .long-text{
            word-wrap: break-word; 
            overflow-wrap: break-word; 
        }
        .button-style{
            align-self: center;
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
                        <a href ="MainPage.aspx">Wróć do strony głównej</a>
                    <%} %>
                </td>
                <td style="width: 25%">
                    <%if (User.Identity.IsAuthenticated){ %>
                        <p>Zalogowany użytkownik: <%=User.Identity.Name%></p>
                    <%} %>
                </td>
                <td style="width: 25%">
                    <%if (User.IsInRole("Admin")){ %>
                    <a href="NewItem.aspx">Dodaj nowy przedmiot</a>
                    <%} %>
                </td>
            </tr>
        </table>
        </div>
        <div>
            <asp:ListView runat="server" ID="ListView2" DataSourceID="ObjectDataSource2">
            <LayoutTemplate>
                <div style="margin-left: 10px; margin-bottom: 10px; margin-top: 10px">
                <div id="itemPlaceholderContainer" runat="server" >
                    <span runat="server" id="itemPlaceholder" />
                </div>
                <div style="margin-bottom: 10px; margin-left: 10px">
                    <asp:DataPager ID="DataPager1" runat="server">
                        <Fields>
                            <asp:NextPreviousPagerField ButtonType="Button" ShowFirstPageButton="True" ShowLastPageButton="True" />
                        </Fields>
                    </asp:DataPager>
                </div>
                </div>
            </LayoutTemplate>
            <ItemTemplate>
                <table runat="server" style="margin-left: 5px;">
                    <tr>
                        <td></td>
                        <td>
                            <asp:Label CssClass="content" ID="nameLabel" runat="server" 
                                Text='<%# ((Shop.Item)Container.DataItem).name %>' />
                        </td>
                    </tr>
                    <tr>
                        <td></td>
                        <td>
                            <asp:Label CssClass="content" ID="Label1" runat="server" 
                                Text='<%# ((Shop.Item)Container.DataItem).price.ToString() + " zł" %>' />
                        </td>
                    </tr>
                    <tr>
                        <td></td>
                        <td style="word-wrap: break-word; overflow-wrap: break-word; width: 300px">
                            <asp:Label CssClass="content" ID="Label2" runat="server" 
                                Text='<%# ((Shop.Item)Container.DataItem).description %>' />
                        </td>
                    </tr>
                    <tr>
                        <td></td>
                        <td>
                            <asp:Label CssClass="content" ID="Label3" runat="server">
                                <a href='<%# ((Shop.Item)Container.DataItem).image %>'>
                                    Zdjęcie
                                </a>
                            </asp:Label>
                        </td>
                    </tr>
                </table>
                <br />
            </ItemTemplate>
        </asp:ListView>
        <asp:ObjectDataSource runat="server" ID="ObjectDataSource2" TypeName="ShoppingCart_DataProvider" EnablePaging="true"
            SelectMethod="Retrieve" StartRowIndexParameterName="StartRow" MaximumRowsParameterName="RowCount"
            SortParameterName="OrderBy" SelectCountMethod="SelectItemsCount">
        </asp:ObjectDataSource>
            
        </div>
    </form>
</body>
</html>
