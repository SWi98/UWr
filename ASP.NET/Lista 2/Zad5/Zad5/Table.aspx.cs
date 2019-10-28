using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

namespace Zad5
{
    public partial class Table : System.Web.UI.Page
    {
        private string Name, Surname, Class, Date; 
        private string[] Vals = new string[10];
        protected void Page_Load(object sender, EventArgs e)
        {
            Name = Request.QueryString["N"];
            Surname = Request.QueryString["S"];
            Class = Request.QueryString["C"];
            Date = Request.QueryString["D"];
            for(int i = 0; i < 10; i++)
            {
                string val = Request.QueryString["Z" + (i+1).ToString()];
                if (val.Length != 0)
                    Vals[i] = val;
                else
                    Vals[i] = "0";
            }

            HtmlTable table = new HtmlTable();
            table.CellPadding = 4;
            table.Border = 1;
            table.Width = "580";


            HtmlTableRow firstRow = new HtmlTableRow();

            HtmlTableCell NameCell = new HtmlTableCell();
            NameCell.Width = "80";
            NameCell.ColSpan = 4;
            NameCell.InnerHtml = Name;

            HtmlTableCell SurnameCell = new HtmlTableCell();
            SurnameCell.Width = "100";
            SurnameCell.ColSpan = 5;
            SurnameCell.InnerHtml = Surname;

            HtmlTableCell ClassCell = new HtmlTableCell();
            ClassCell.Width = "300";
            ClassCell.ColSpan = 15;
            ClassCell.InnerHtml = Class;

            HtmlTableCell DateCell = new HtmlTableCell();
            DateCell.Width = "100";
            DateCell.ColSpan = 5;
            DateCell.InnerHtml = Date;

            firstRow.Cells.Add(NameCell); firstRow.Cells.Add(SurnameCell); 
            firstRow.Cells.Add(ClassCell); firstRow.Cells.Add(DateCell);
            table.Rows.Add(firstRow);


            HtmlTableRow secondRow = new HtmlTableRow();
            HtmlTableCell tasks = new HtmlTableCell();
            tasks.Width = "80";
            tasks.ColSpan = 4;
            tasks.InnerHtml = "Zadania:";
            secondRow.Cells.Add(tasks);

            for(int i = 0; i < 10; i++)
            {
                HtmlTableCell pointCell = new HtmlTableCell();
                pointCell.Width = "40";
                pointCell.ColSpan = 2;
                pointCell.InnerHtml = (i + 1).ToString() +".";

                secondRow.Cells.Add(pointCell);
            }

            table.Rows.Add(secondRow);


            HtmlTableRow thirdRow = new HtmlTableRow();
            HtmlTableCell points = new HtmlTableCell();

            points.Width = "80";
            points.ColSpan = 4;
            points.InnerHtml = "Punkty:";
            thirdRow.Cells.Add(points);

            for (int i = 0; i < 10; i++)
            {
                HtmlTableCell pointCell = new HtmlTableCell();
                pointCell.Width = "40";
                pointCell.ColSpan = 2;
                pointCell.InnerHtml = Vals[i];

                thirdRow.Cells.Add(pointCell);
            }

            table.Rows.Add(thirdRow);


            this.Controls.Add(table);
        }
    }
}