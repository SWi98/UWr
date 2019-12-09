<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Cart.aspx.cs" Inherits="Shop.Cart" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <table style="width: 100%">
            <tr>
                <td style="text-align: center; padding-bottom: 4px">
                    <a href="MainPage.aspx">Strona główna</a>
                </td>
            </tr>
        </table>
        <div>
            <asp:ListView runat="server" ID="ListView2" DataSourceID="ObjectDataSource2">
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
