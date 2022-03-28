using System;

namespace before
{
    public class ReportPrinter
    {
        private string data;

        public string GetData()
        {
            string data = @"Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
            + "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
            + "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. "
            + "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. "
            + "Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
            return data;
        }

        public void FormatDocument()
        {
            this.data = data.Replace(". ", ".\n");
        }

        public void PrintReport()
        {
            this.data = this.GetData();
            this.FormatDocument();
            Console.Write(this.data);
        }
    }

    public class Program
    {
        static void Main(string[] args)
        {
            ReportPrinter printer = new ReportPrinter();
            printer.PrintReport();
        }
    }
}
