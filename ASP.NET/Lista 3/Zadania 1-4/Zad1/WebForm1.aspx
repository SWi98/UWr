<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Zad1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    Zadanie 1:
    <br />
    <form action = "http://ap1.myserver.com/" method = "get">
        <input type ="text" name ="1"/>
        <input type ="submit" value ="GET instead of POST" />
    </form>
    <form id="form1" runat="server">
        <asp:TextBox ID ="TestBox1" Text ="Enter POST value" runat ="server"></asp:TextBox>
        <asp:LinkButton ID ="LinkButton2" runat ="server" Text="post" PostBackUrl ="http://ap1.myserver.com/" />
        <br />
        <!-- <asp:LinkButton ID ="LinkButton1" OnClick ="LinkButton1_Click" runat ="server">POSTInsteadOfGET
            </asp:LinkButton>-->
        <br />
        <a href ="WebForm2.aspx">Zadanie 2, 3</a>
        <br />
    </form>
</body>
</html>
