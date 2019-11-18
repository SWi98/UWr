<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Zadanie7.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <input type="file" id ="File1" runat="server" />
            <br />
            <asp:Button id="Submit1" runat ="server" text ="Upload" OnClick ="SubmitFile"/>
        </div>
    </form>
</body>
</html>
