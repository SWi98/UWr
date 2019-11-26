<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Zadanie1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <%=User.Identity.Name%>
            <br />
            <%=User.Identity.AuthenticationType %>
            <br />
            <%=User.IsInRole("Administrator") %>
        </div>
    </form>
</body>
</html>
