<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        Databinding formantu GridView ze stronicowaniem i ObjectDataSource:<br />
        <asp:GridView ID="GridView1" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataSourceID="ObjectDataSource1" ForeColor="#333333" GridLines="None">
            <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
            <RowStyle BackColor="#F7F6F3" ForeColor="#333333" />
            <EditRowStyle BackColor="#999999" />
            <SelectedRowStyle BackColor="#E2DED6" Font-Bold="True" ForeColor="#333333" />
            <PagerStyle BackColor="#284775" ForeColor="White" HorizontalAlign="Center" />
            <HeaderStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
            <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
            <Columns>
                <asp:TemplateField HeaderText="Nazwisko">
                    <ItemTemplate>
                        <%# ((Osoba)Container.DataItem).Nazwisko %>
                    </ItemTemplate>
                </asp:TemplateField>
                <asp:TemplateField HeaderText="Imie">
                    <ItemTemplate>
                        <%# ((Osoba)Container.DataItem).Imie %>
                    </ItemTemplate>
                </asp:TemplateField>
                <asp:TemplateField HeaderText="Miejscowoś ur." SortExpression="MSCUR">
                    <ItemTemplate>
                        <%# ((Osoba)Container.DataItem).MiejscowoscUr.Nazwa %>
                    </ItemTemplate>
                </asp:TemplateField>
            </Columns>
        </asp:GridView>
        <asp:ObjectDataSource ID="ObjectDataSource1" runat="server" EnablePaging="True" InsertMethod="Insert"
            MaximumRowsParameterName="RowCount" SelectCountMethod="SelectCount" SelectMethod="Retrieve"
            SortParameterName="OrderBy" StartRowIndexParameterName="StartRow" TypeName="Osoba_DataProvider"
            UpdateMethod="Update"></asp:ObjectDataSource>
    </div>
    </form>
</body>
</html>
