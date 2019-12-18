<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="MainPage.aspx.cs" Inherits="Shop.MainPage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style>
        img {
            border: 1px solid #ddd;
            border-radius: 4px;
            padding: 5px;
            width: 305px;
           }
        img:hover {
            box-shadow: 0 0 2px 1px rgba(0, 140, 186, 0.5);
        }
        .price{
            font-size: 23px; 
        }
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
                        <a href="NewItem.aspx">Dodaj nowy przedmiot</a>
                    <%} %>
                </td>
            </tr>
        </table>
        </div>
        <asp:ListView runat="server" ID="ListView1" 
            DataSourceID="ObjectDataSource1" 
            OnItemCommand="ListView1_ItemCommand"
            DataKeyNames="id">
            <LayoutTemplate>
                <div style="margin-left: 20px; margin-bottom: 10px; margin-top: 10px" id="LTdiv">
                <div>
                    <table style="margin-bottom: 8px">
                        <tr>
                            <td>
                                Sortuj według:
                            </td>
                            <td>
                                <asp:Button runat="server" ID="price" CommandName="Sort" CommandArgument="price" 
                                    Text="Ceny" OnClick="Sort1_Click"/>
                            </td>
                            <td>
                                <asp:Button runat="server" ID="name" CommandName="Sort" CommandArgument="name" 
                                    Text="Nazwy" OnClick="Sort1_Click"/>
                            </td>
                        </tr>
                        <%--<tr>
                            <td>
                                <asp:RadioButtonList ID="SortingParam" runat="server">
                                    <asp:ListItem Value="A">Rosnąco</asp:ListItem>
                                    <asp:ListItem Value="D">Malejąco</asp:ListItem>
                                </asp:RadioButtonList>
                            </td>
                        </tr>--%>
                    </table>
                </div>
                <div id="itemPlaceholderContainer" runat="server" style="margin-top: 6px">
                    <span runat="server" id="itemPlaceholder" />
                </div>
                <div style="margin-bottom: 10px; margin-left: 10px">
                    <asp:DataPager ID="DataPager1" runat="server" PageSize="8">
                        <Fields>
                            <asp:NextPreviousPagerField ButtonType="Button" ShowFirstPageButton="True" 
                                ShowLastPageButton="True" />
                        </Fields>
                    </asp:DataPager>
                </div>
                </div>
            </LayoutTemplate>
            <ItemTemplate>
                <div style="margin-bottom: 25px">
                <a href='<%# ((Shop.Item)Container.DataItem).image %>' target="_blank">
                    <img src='<%# ((Shop.Item)Container.DataItem).image %>' />
                </a>
                <table runat="server" style="margin-left: 5px; background-color: gainsboro; width: 310px">
                    <tr>
                        <td>
                            <b><asp:Label CssClass="content" ID="nameLabel" runat="server" 
                                Text='<%# ((Shop.Item)Container.DataItem).name %>' /></b>
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <asp:Label CssClass="price" ID="Label1" runat="server" 
                                Text='<%# ((Shop.Item)Container.DataItem).price.ToString() + " zł" %>' />
                        </td>
                    </tr>
                    <tr>
                        <td style="word-wrap: break-word; overflow-wrap: break-word; width: 300px" colspan="2">
                            <asp:Label CssClass="content" ID="Label2" runat="server"  
                                Text='<%# ((Shop.Item)Container.DataItem).description.Replace(Environment.NewLine, "<br />") %>' />
                        </td>
                    </tr>
<%--                    <tr>
                        <td>
                            <asp:Label CssClass="content" ID="Label3" runat="server">
                                <a href='<%# ((Shop.Item)Container.DataItem).image %>'>
                                    Zdjęcie
                                </a>
                            </asp:Label>
                        </td>
                    </tr>--%>
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
                        <td>
                            <%if (User.IsInRole("Admin")){ %>
                                <asp:Button ID="Button2" runat="server" Text="Usuń przedmiot"
                                CommandName="Delete" />
                            <%} %>
                        </td>
                    </tr>
                </table>
                </div>
            </ItemTemplate>
            <EditItemTemplate>
                <table runat="server" style="margin-left: 5px; background-color:cornsilk; width: 30%" border="0">
                    <tr>
                        <td style="width: 60%"  colspan="2">
                            <asp:TextBox ID="EditNameTextBox" runat="server"
                                Text='<%# ((Shop.Item)Container.DataItem).name %>'></asp:TextBox>
                        </td>
                    </tr>
                    <tr>
                        <td colspan="2">
                            <asp:TextBox ID="EditPriceTextBox" runat="server" 
                                Text='<%# ((Shop.Item)Container.DataItem).price.ToString()%>' />
                        </td>
                    </tr>
                    <tr>
                        <td colspan="2">
                            <asp:TextBox ID="EditDescTextBox" runat="server" Width="95%"
                                Text='<%# ((Shop.Item)Container.DataItem).description %>' />
                        </td>
                    </tr>
                    <tr>
                        <td style="word-wrap: break-word; overflow-wrap: break-word;" colspan="2">
                            <asp:TextBox ID="EditImageTextBox" runat="server" Width="95%"
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
            SortParameterName="OrderBy" SelectCountMethod="SelectItemsCount" UpdateMethod="Update"
             OnUpdating="ObjectDataSource1_Updating" OnUpdated="ObjectDataSource1_Updated" 
             OnDeleting="ObjectDataSource1_Deleting" DeleteMethod="Delete">
        </asp:ObjectDataSource>

    </form>
</body>
</html>
