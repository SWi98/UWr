<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default2.aspx.cs" Inherits="Default2" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        ListView tabelaryczny<br />
        <asp:ListView ID="ListView1" runat="server" DataSourceID="ObjectDataSource1" DataKeyNames="ID"
            ItemPlaceholderID="ListPlaceholder" OnItemCommand="ListView1_ItemCommand">
            <LayoutTemplate>
                <table>
                    <tr>
                        <td>
                            Imię
                        </td>
                        <td>
                            Nazwisko
                        </td>
                        <td>
                            <asp:LinkButton ID="MiejscowoscTh" runat="server" Text="Miejscowosć" CommandName="Sort"
                                CommandArgument="MSCUR" />
                        </td>
                        <td>
                            &nbsp;
                        </td>
                        <td>
                            &nbsp;
                        </td>
                    </tr>
                    <tr>
                        <asp:PlaceHolder ID="ListPlaceholder" runat="server"></asp:PlaceHolder>
                    </tr>
                    <tr>
                        <td>
                            <asp:DataPager ID="DataPager" runat="server" PagedControlID="ListView1" PageSize="10">
                                <Fields>
                                    <asp:NumericPagerField ButtonCount="8" ButtonType="Link" />
                                </Fields>
                            </asp:DataPager>
                        </td>
                    </tr>
                    <tr>
                        <td colspan="5">
                            <asp:LinkButton ID="btDodaj" runat="server" CommandName="ShowInsertTemplate" Text="Dodaj nowy" />
                        </td>
                    </tr>
                </table>
            </LayoutTemplate>
            <ItemTemplate>
                <tr>
                    <td>
                        <%# ((Osoba)Container.DataItem).Imie %>
                    </td>
                    <td>
                        <%# ((Osoba)Container.DataItem).Nazwisko %>
                    </td>
                    <td>
                        <%# ((Osoba)Container.DataItem).MiejscowoscUr.Nazwa %>
                    </td>
                    <td>
                        <asp:LinkButton ID="EditButton" CommandName="Edit" CommandArgument='<%# ((Osoba)Container.DataItem).ID %>'
                            Text="Edytuj" runat="server" />
                        <asp:LinkButton ID="DeleteButton" CommandName="Delete" CommandArgument='<%# ((Osoba)Container.DataItem).ID %>'
                            Text="Usuń" runat="server" />
                    </td>
                    <td>
                        <asp:LinkButton ID="DownloadXmlButton" CommandName="DownloadXml" CommandArgument='<%# ((Osoba)Container.DataItem).ID %>'
                            Text="Pobierz XML" runat="server" />
                    </td>
                </tr>
            </ItemTemplate>
            <InsertItemTemplate>
                <tr>
                    <td colspan="5">
                        <table width="60%">
                            <tr>
                                <td>
                                    Imię
                                </td>
                                <td width="100%">
                                    <asp:TextBox runat="server" ID="NazwiskoInsert" Width="60%"></asp:TextBox>
                                </td>
                            </tr>
                            <tr>
                                <td>
                                    Nazwisko
                                </td>
                                <td width="100%">
                                    <asp:TextBox runat="server" ID="ImieInsert" Width="60%"></asp:TextBox>
                                </td>
                            </tr>
                            <tr>
                                <td>
                                    Miejscowość
                                </td>
                                <td>
                                    <asp:DropDownList ID="MiejscowoscInsert" runat="server" DataSource='<%# Model.Instance.Miejscowosci %>'
                                        DataTextField="Nazwa" DataValueField="ID">
                                    </asp:DropDownList>
                                </td>
                            </tr>
                            <tr>
                                <td colspan="2">
                                    <asp:LinkButton ID="Akceptuj" runat="server" Text="Akceptuj" CommandName="Insert" />
                                    <asp:LinkButton ID="Anuluj" runat="server" Text="Anuluj" CommandName="HideInsertTemplate" />
                                </td>
                            </tr>
                        </table>
                    </td>
                </tr>
            </InsertItemTemplate>
            <EditItemTemplate>
                <tr>
                    <td colspan="5">
                        <table>
                            <tr>
                                <td>
                                    Imię
                                </td>
                                <td>
                                    <asp:TextBox runat="server" ID="NazwiskoEdit" Width="60%" Text='<%# ((Osoba)Container.DataItem).Nazwisko %>'></asp:TextBox>
                                </td>
                            </tr>
                            <tr>
                                <td>
                                    Nazwisko
                                </td>
                                <td>
                                    <asp:TextBox runat="server" ID="ImieEdit" Width="60%" Text='<%# ((Osoba)Container.DataItem).Imie %>'></asp:TextBox>
                                </td>
                            </tr>
                            <tr>
                                <td>
                                    Miejscowość
                                </td>
                                <td>
                                    <asp:DropDownList ID="MiejscowoscEdit" runat="server" DataSource='<%# Model.Instance.Miejscowosci %>'
                                        DataTextField="Nazwa" DataValueField="ID" SelectedValue='<%# ((Osoba)Container.DataItem).MiejscowoscUr.ID.ToString() %>'>
                                    </asp:DropDownList>
                                </td>
                            </tr>
                            <tr>
                                <td colspan="2">
                                    <asp:LinkButton ID="Akceptuj" runat="server" Text="Akceptuj" CommandName="Update" />
                                    <asp:LinkButton ID="Anuluj" runat="server" Text="Anuluj" CommandName="Cancel" />
                                </td>
                            </tr>
                        </table>
                    </td>
                </tr>
            </EditItemTemplate>
        </asp:ListView>
        <asp:ObjectDataSource ID="ObjectDataSource1" runat="server" EnablePaging="True" InsertMethod="Insert"
            MaximumRowsParameterName="RowCount" SelectCountMethod="SelectCount" SelectMethod="Retrieve"
            SortParameterName="OrderBy" StartRowIndexParameterName="StartRow" TypeName="Osoba_DataProvider"
            UpdateMethod="Update" OnDeleting="ObjectDataSource1_Deleting" OnUpdating="ObjectDataSource1_Updating"
            OnUpdated="ObjectDataSource1_Updated" OnInserted="ObjectDataSource1_Inserted"
            OnInserting="ObjectDataSource1_Inserting"></asp:ObjectDataSource>
        <br />
        ListView w postaci listy wypunktowanej<br />
        ListView w postaci siatki szczegółów jednego elementu<br />
    </div>
    </form>
</body>
</html>
