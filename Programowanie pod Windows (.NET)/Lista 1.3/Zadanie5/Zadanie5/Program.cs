using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie5
{
    class Program
    {
        static void JoinFiles()
        {
            string path_1 = @"D:\Documents\GitHub\UWr\Programowanie pod Windows (.NET)\Lista 3\DoZadania5_1.txt";
            string path_2 = @"D:\Documents\GitHub\UWr\Programowanie pod Windows (.NET)\Lista 3\DoZadania5_2.txt";
            string[] NamesAndNumbers = System.IO.File.ReadAllLines(path_1);
            string[] Numbers = System.IO.File.ReadAllLines(path_2);

            foreach (string d in NamesAndNumbers)
                Console.WriteLine(d);
            Console.WriteLine("---------------------");
            foreach (string d in Numbers)
                Console.WriteLine(d);
            Console.WriteLine("---------------------");

            IEnumerable<string> JoinedFiles =
                from name in NamesAndNumbers
                let nameFields = name.Split(',')
                from number in Numbers
                let numberFields = number.Split(',')
                where nameFields[2] == numberFields[0]
                select nameFields[0] + " " + nameFields[1] + " " + nameFields[2] + " " + numberFields[1];

            foreach (string d in JoinedFiles)
                Console.WriteLine(d);
            
        }
        static void Main(string[] args)
        {
            JoinFiles();
            Console.ReadKey();
        }
    }
}
