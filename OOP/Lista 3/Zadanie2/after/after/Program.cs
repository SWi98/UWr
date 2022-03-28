using System; 

namespace after
{

    public class DataProvider
    {
        public string GetData()
        {
            string data = @"Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
            + "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
            + "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. "
            + "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. "
            + "Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
            return data;
        }
    }

    public class DataFormatter
    {
        public string FormatData(string data)
        {
            return data.Replace(". ", ".\n");
        }
    }

    public class ReportPrinter
    {
        public void PrintReport(string data)
        {
            Console.Write(data);
        }
    }

    public class Program
    {
        public static void Main(string[] args)
        {
            string data = new DataProvider().GetData();
            data = new DataFormatter().FormatData(data);
            new ReportPrinter().PrintReport(data);
        }
    }
}