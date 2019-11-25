﻿<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        Databinding formantu DropDownList:<br />
        <asp:DropDownList ID="DropDownList1" runat="server" DataSource='<%# Model.Instance.Osoby %>' DataValueField="ID" DataTextField="This" DataTextFormatString="{0:u}">
        </asp:DropDownList>
        <asp:Button ID="Button1" runat="server" Text="Button" /><br />
        <br />
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
        <br />
        Databinding formantu DetailsView ze stronicowaniem i ObjectDataSource<br />
        <asp:DetailsView ID="DetailsView1" runat="server" Height="50px" Width="100%" AutoGenerateDeleteButton="True" AutoGenerateEditButton="True" AutoGenerateInsertButton="True" AutoGenerateRows="False" CellPadding="4" DataSourceID="ObjectDataSource2" ForeColor="#333333" GridLines="None" AllowPaging="True">
            <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
            <CommandRowStyle BackColor="#E2DED6" Font-Bold="True" />
            <EditRowStyle BackColor="#999999" />
            <RowStyle BackColor="#F7F6F3" ForeColor="#333333" />
            <PagerStyle BackColor="#284775" ForeColor="White" HorizontalAlign="Center" />
            <Fields>
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
                <asp:TemplateField HeaderText="Miejscowoś ur.">
                    <ItemTemplate>
                        <%# ((Osoba)Container.DataItem).MiejscowoscUr.Nazwa %>
                    </ItemTemplate>
                </asp:TemplateField>
            </Fields>
            <FieldHeaderStyle BackColor="#E9ECF1" Font-Bold="True" Width="20%" />
            <HeaderStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
            <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
        </asp:DetailsView>
        <asp:ObjectDataSource ID="ObjectDataSource2" runat="server" SelectMethod="Retrieve" TypeName="Osoba_DataProvider" EnablePaging="True" MaximumRowsParameterName="StartRow" StartRowIndexParameterName="RowCount" SelectCountMethod="SelectCount" SortParameterName="OrderBy"></asp:ObjectDataSource>
        <br />
        Databinding formantu DetailsView bez stronicowania ale ze wskazaniem konkretnego
        rekordu z ObjectDatasource&nbsp;<br />
        &nbsp;ID rekordu: <asp:TextBox ID="TextBox1" runat="server">5</asp:TextBox>&nbsp;
        <br />
        <asp:DetailsView ID="DetailsView2" runat="server" Height="50px" Width="100%" AutoGenerateDeleteButton="True" AutoGenerateEditButton="True" AutoGenerateInsertButton="True" AutoGenerateRows="False" CellPadding="4" DataSourceID="ObjectDataSource3" ForeColor="#333333" GridLines="None" AllowPaging="True">
            <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
            <CommandRowStyle BackColor="#E2DED6" Font-Bold="True" />
            <EditRowStyle BackColor="#999999" />
            <RowStyle BackColor="#F7F6F3" ForeColor="#333333" />
            <PagerStyle BackColor="#284775" ForeColor="White" HorizontalAlign="Center" />
            <Fields>
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
                <asp:TemplateField HeaderText="Miejscowoś ur.">
                    <ItemTemplate>
                        <%# ((Osoba)Container.DataItem).MiejscowoscUr.Nazwa %>
                    </ItemTemplate>
                </asp:TemplateField>
            </Fields>
            <FieldHeaderStyle BackColor="#E9ECF1" Font-Bold="True" Width="20%" />
            <HeaderStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
            <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
        </asp:DetailsView>
        <asp:ObjectDataSource ID="ObjectDataSource3" runat="server" SelectMethod="Retrieve" TypeName="Osoba_DataProvider" MaximumRowsParameterName="" StartRowIndexParameterName="">
            <SelectParameters>
                <asp:ControlParameter ControlID="TextBox1" Name="ID" />
            </SelectParameters>
        </asp:ObjectDataSource>
    </div>
    </form>
</body>
</html>
