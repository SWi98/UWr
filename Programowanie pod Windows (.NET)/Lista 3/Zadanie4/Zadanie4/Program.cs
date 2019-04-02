using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie4
{
    class Program
    {
        static void FileLen()
        {
            string path = @"D:\Documents\GitHub\UWr\Programowanie pod Windows (.NET)\Lista 3";
            IEnumerable<string> AllFiles = System.IO.Directory.GetFiles(path);
            var FilesLength = from file in AllFiles
                              select new System.IO.FileInfo(file).Length;
            int TotalLength = FilesLength.Aggregate(0, (result, element) => (int)(result + element));
            Console.WriteLine(TotalLength);
        }
        static void Main(string[] args)
        {
            FileLen();
            Console.ReadKey();
        }
    }
}
