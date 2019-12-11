<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="MainPage.aspx.cs" Inherits="Shop.MainPage" %>

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
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <table style="width: 100%">
            <tr style="padding-bottom: 20px">                
                <td style="width: 25%; padding-bottom: 20px">
                    <a href ="Login.aspx">Strona logowania</a>
                </td>
                <td style="width: 25%">
                    <%if (User.IsInRole("Admin")){ %>
                        <a href="NewItem.aspx">Dodaj nowy przedmiot</a>
                    <%} %>
                </td>
                <td style="width: 25%">
                    <%if (User.Identity.IsAuthenticated){ %>
                        <a href ="Cart.aspx">Koszyk</a>
                    <%} %>
                </td>
                <td style="width: 25%">
                    <%if (User.Identity.IsAuthenticated){ %>
                        Zalogowany użytkownik: <%=User.Identity.Name%>
                    <%} %>
                </td>
            </tr>
        </table>
        <asp:ListView runat="server" ID="ListView1" 
            DataSourceID="ObjectDataSource1" 
            OnItemCommand="ListView1_ItemCommand">
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
                <table runat="server" style="margin-left: 5px; background-color: aliceblue">
                    <tr>
                        <td>
                            <b><asp:Label CssClass="content" ID="nameLabel" runat="server" 
                                Text='<%# ((Shop.Item)Container.DataItem).name %>' /></b>
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <asp:Label CssClass="content" ID="Label1" runat="server" 
                                Text='<%# ((Shop.Item)Container.DataItem).price.ToString() + " zł" %>' />
                        </td>
                    </tr>
                    <tr>
                        <td style="word-wrap: break-word; overflow-wrap: break-word; width: 300px" colspan="2">
                            <asp:Label CssClass="content" ID="Label2" runat="server" 
                                Text='<%# ((Shop.Item)Container.DataItem).description %>' />
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <asp:Label CssClass="content" ID="Label3" runat="server">
                                <a href='<%# ((Shop.Item)Container.DataItem).image %>'>
                                    Zdjęcie
                                </a>
                            </asp:Label>
                        </td>
                    </tr>
                    <tr style="padding-top: 2px;">
                        <td>
                            <%if (User.Identity.IsAuthenticated){%>
                                <asp:Button ID="AddToCartButton" runat="server" Text="Dodaj do koszyka"
                                    CommandArgument="<%# ((Shop.Item)Container.DataItem).id %>" CommandName="AddToCart"/>
                            <%} %>
                        </td>
                        <td>
                            <%if (User.IsInRole("Admin")){ %>
                                <asp:Button ID="EditButton" runat="server" Text="Edytuj przedmiot"
                                CommandName="Edit" />
                            <%} %>
                        </td>
                    </tr>
                </table>
                <br />
            </ItemTemplate>
            <EditItemTemplate>
                <table runat="server" style="margin-left: 5px; background-color: aquamarine; width: 30%" border="0">
                    <tr>
                        <td style="width: 30%">
                            <asp:TextBox ID="NameTextBox" runat="server"
                                Text='<%# ((Shop.Item)Container.DataItem).name %>'></asp:TextBox>
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <asp:TextBox ID="PriceTextBox" runat="server" 
                                Text='<%# ((Shop.Item)Container.DataItem).price.ToString() + " zł" %>' />
                        </td>
                    </tr>
                    <tr>
                        <td colspan="2">
                            <asp:TextBox ID="DescTextBox" runat="server" Width="95%"
                                Text='<%# ((Shop.Item)Container.DataItem).description %>' />
                        </td>
                    </tr>
                    <tr>
                        <td style="word-wrap: break-word; overflow-wrap: break-word;" colspan="2">
                            <asp:TextBox ID="ImageTextBox" runat="server" Width="95%"
                                Text='<%# ((Shop.Item)Container.DataItem).image %>'></asp:TextBox>
                        </td>
                    </tr>
                    <tr>
                        <td style="align-content: center">
                            <asp:Button ID="UpdateButton" runat="server" CommandName="Update" 
                                Text="  Edytuj  "/>
                        </td>
                        <td>
                            <asp:Button ID="CancelButton" runat="server" CommandName="Cancel" 
                                Text="  Anuluj  " />
                        </td>
                    </tr>
                </table>
                <br />
            </EditItemTemplate>
        </asp:ListView>
        <asp:ObjectDataSource runat="server" ID="ObjectDataSource1" TypeName="Item_DataProvider" EnablePaging="true"
            SelectMethod="Retrieve" StartRowIndexParameterName="StartRow" MaximumRowsParameterName="RowCount"
            SortParameterName="OrderBy" SelectCountMethod="SelectItemsCount" UpdateMethod="Update">
            <UpdateParameters>
                <asp:FormParameter Name="OldID" DefaultValue="<%((Shop.Item)Container.DataItem).id.ToString() %>"/>
                <asp:FormParameter Name="OldName" DefaultValue="<%((Shop.Item)Container.DataItem).name.ToString() %>"/>
                <asp:FormParameter Name="NewName" FormField="NameTextBox"/>
                <asp:FormParameter Name="NewPrice" FormField="PriceTextBox"/>
                <asp:FormParameter Name="NewDesc" FormField="DescTextBox"/>
                <asp:FormParameter Name="NewUrl" FormField="ImageTextBox"/>
            </UpdateParameters>
        </asp:ObjectDataSource>
    </form>
</body>
</html>
