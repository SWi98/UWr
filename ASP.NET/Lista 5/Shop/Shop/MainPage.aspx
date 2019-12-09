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
        <asp:ListView runat="server" ID="ListView1" DataSourceID="ObjectDataSource1">
            <ItemTemplate>
                <%# ((Shop.Item)Container.DataItem).name %>
            </ItemTemplate>
        </asp:ListView>
        <asp:ObjectDataSource runat="server" ID="ObjectDataSource1" TypeName="Item_DataProvider"
            SelectMethod="Retrieve" StartRowIndexParameterName="StartRow" MaximumRowsParameterName="RowCount"
            SortParameterName="OrderBy">
            <SelectParameters>
                <asp:Parameter Name="OrderBy" Type="String" />
                <asp:Parameter Name="StartRow" Type="Int32" />
                <asp:Parameter Name="RowCount" Type="Int32" />
            </SelectParameters>
        </asp:ObjectDataSource>
    </form>
</body>
</html>
