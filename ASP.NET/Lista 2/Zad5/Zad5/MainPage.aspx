<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="MainPage.aspx.cs" Inherits="Zad5.MainPage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <b style ="display:inline; margin-right: 3em">Imię:   </b>
        <asp:TextBox ID ="Name" Columns ="20" runat ="server"></asp:TextBox>
        <br /><br />

        <b style = "display:inline; margin-right: 0.8em">Nazwisko:</b>
        <asp:TextBox ID ="Surname" Columns ="20" runat ="server"></asp:TextBox>
        <br /><br />

        <b style = "display:inline; margin-right: 1em">Nazwa przedmiotu:</b>
        <asp:TextBox ID ="Class" Columns ="40" runat ="server" ></asp:TextBox>
        <br /><br />

        <b style = "margin-right: 1em">Punkty za zadanie:</b>

        <p style = "display:inline; margin-right: 0.1em">1. </p>
        <asp:TextBox ID ="Z1" Columns ="1" runat ="server"></asp:TextBox>

        <p style = "display:inline; margin-right: 0.1em; margin-left: 0.4em">2. </p>
        <asp:TextBox ID ="Z2" Columns ="1" runat ="server"></asp:TextBox>

        <p style = "display:inline; margin-right: 0.1em; margin-left: 0.4em">3. </p>
        <asp:TextBox ID ="Z3" Columns ="1" runat ="server"></asp:TextBox>

        <p style = "display:inline; margin-right: 0.1em; margin-left: 0.4em">4. </p>
        <asp:TextBox ID ="Z4" Columns ="1" runat ="server"></asp:TextBox>

        <p style = "display:inline; margin-right: 0.1em; margin-left: 0.4em">5. </p>
        <asp:TextBox ID ="Z5" Columns ="1" runat ="server"></asp:TextBox>

        <p style = "display:inline; margin-right: 0.1em; margin-left: 0.4em">6. </p>
        <asp:TextBox ID ="Z6" Columns ="1" runat ="server"></asp:TextBox>

        <p style = "display:inline; margin-right: 0.1em; margin-left: 0.4em">7. </p>
        <asp:TextBox ID ="Z7" Columns ="1" runat ="server"></asp:TextBox>

        <p style = "display:inline; margin-right: 0.1em; margin-left: 0.4em">8. </p>
        <asp:TextBox ID ="Z8" Columns ="1" runat ="server"></asp:TextBox>

        <p style = "display:inline; margin-right: 0.1em; margin-left: 0.4em">9. </p>
        <asp:TextBox ID ="Z9" Columns ="1" runat ="server"></asp:TextBox>

        <p style = "display:inline; margin-right: 0.1em; margin-left: 0.4em">10. </p>
        <asp:TextBox ID ="Z10" Columns="1" runat ="server"></asp:TextBox>
        <br /><br />

        <p style = "display:inline; margin-right: 1em">Data:</p>
        <asp:TextBox ID="Date" runat="server" TextMode ="Date"></asp:TextBox>
        <br /><br />

        <asp:Button ID ="Submit" Text ="Wyślij" OnClick ="SubmitData" runat ="server" />
    </form>
</body>
</html>
