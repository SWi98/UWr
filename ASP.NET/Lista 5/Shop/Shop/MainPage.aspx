﻿<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="MainPage.aspx.cs" Inherits="Shop.MainPage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style>
        .content{
            /*background-color: #E0FFFF;*/ 
            color: #000000;
        }
        p.table{
            white-space: pre;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <table style="width: 100%">
            <tr style="padding-bottom: 5px">
                <td style="width: 25%">
                    <%if (User.IsInRole("Admin")){ %>
                        <a href="NewItem.aspx">Dodaj nowy przedmiot</a>
                    <%} %>
                </td>
                <td style="width: 25%">
                    <a href ="Cart.aspx">Koszyk</a>
                </td>
                <td style="width: 25%">
                    <a href ="Login.aspx">Strona logowania</a>
                </td>
                <td style="width: 25%">
                    <%if (User.Identity.IsAuthenticated){ %>
                        Zalogowany użytkownik: <%=User.Identity.Name%>
                    <%} %>
                </td>
            </tr>
        </table>
        <asp:ListView runat="server" ID="ListView1" DataSourceID="ObjectDataSource1" OnItemCommand="ListView1_ItemCommand">
            <LayoutTemplate>
                <div id="itemPlaceholderContainer" runat="server" >
                    <span runat="server" id="itemPlaceholder" />
                </div>
                <div>
                    <asp:DataPager ID="DataPager1" runat="server">
                        <Fields>
                            <asp:NextPreviousPagerField ButtonType="Button" ShowFirstPageButton="True" ShowLastPageButton="True" />
                        </Fields>
                    </asp:DataPager>
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
                    <tr>
                        <td></td>
                        <td style="padding-top: 2px;">
                            <asp:Button ID="AddToCartButton" runat="server" Text="Dodaj do koszyka"
                                CommandArgument="<%# ((Shop.Item)Container.DataItem).id %>" CommandName="AddToCart"/>
                        </td>
                    </tr>
                </table>
                <br />
            </ItemTemplate>
        </asp:ListView>
        <asp:ObjectDataSource runat="server" ID="ObjectDataSource1" TypeName="Item_DataProvider" EnablePaging="true"
            SelectMethod="Retrieve" StartRowIndexParameterName="StartRow" MaximumRowsParameterName="RowCount"
            SortParameterName="OrderBy" SelectCountMethod="SelectItemsCount">
            <%--<SelectParameters>
                <asp:Parameter Name="OrderBy" Type="String" />
                <asp:Parameter Name="StartRow" Type="Int32" />
                <asp:Parameter Name="RowCount" Type="Int32" />
            </SelectParameters>--%>
        </asp:ObjectDataSource>
    </form>
</body>
</html>
