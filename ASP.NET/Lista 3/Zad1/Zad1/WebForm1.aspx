<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Zad1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form action = "http://ap1.myserver.com/" method = "get">
        <input type ="text" name ="1"/>
        <input type ="submit" value ="GET instead of POST" />
    </form>
    <br />
    <form id="form1" runat="server">
        <div>
            <asp:LinkButton ID ="LinkButton1" OnClick ="LinkButton1_Click" runat ="server">POSTInsteadOfGET</asp:LinkButton>
        </div>
        <br />
        <div>
            <a href ="WebForm2.aspx">WebForm2</a>
        </div>
        <br />
    </form>
</body>
</html>
