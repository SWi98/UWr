using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Xml;
using System.Xml.Linq;
using System.IO;

namespace Zadanie7
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        public void SubmitFile(object sender, EventArgs e)
        {
            HttpPostedFile file = Request.Files["File1"];

            if(file != null)
            {
                byte[] bytes;
                BinaryReader binaryReader = new BinaryReader(file.InputStream);
                bytes = binaryReader.ReadBytes(file.ContentLength);
                int sum = 0;
                foreach(var x in bytes)
                {
                    sum += x % 0xFFFF;
                }

                XDocument doc = new XDocument(
                    new XElement("opis",
                        new XElement("nazwa", file.FileName),
                        new XElement("rozmiar", file.ContentLength),
                        new XElement("sygnatura", sum)));

                string name = "UTF - 8''" + DateTime.Now + ".xml";
                string nameIE = DateTime.Now + ".xml";
                Response.Clear();
                Response.ContentType = "text/xml";
                //Response.AppendHeader("Content-Disposition", "attachment;FileName=" + DateTime.Now + ".xml");
                //Response.AppendHeader("Content-Disposition", "attachment;filename*=UTF-8''Na%C3%AFve%20.xml");
                if (Request.Browser.Browser == "Safari")
                {
                    Response.AppendHeader("Content-Disposition", "attachment;filename=" + nameIE);
                }
                else
                {
                    Response.AppendHeader("Content-Disposition", "attachment;filename*=" + name);
                }
                //attachment - downloaded and saved locally, inline - displayed in the browser
                Response.Write(doc.ToString());
                Response.End(); //Response.Flush() ??

            }
        }
        protected void Page_Load(object sender, EventArgs e)
        {
        }
    }
}