using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie2
{
    class Program
    {
        static void ShowNumber()
        {
            string path = @"D:\Documents\GitHub\UWr\Programowanie pod Windows (.NET)" 
                            +@"\Lista 3\DoZadania2.txt";

            int[] IntData = Array.ConvertAll<string, int>(System.IO.File.ReadAllLines(path), int.Parse);

            IEnumerable<int> subset = from number 
                                      in IntData
                                      where number > 100
                                      orderby number
                                      select number;

            foreach (int x in subset)
                Console.WriteLine(x);
            Console.WriteLine("-------------------");

            IEnumerable<int> NewSubset = IntData.Where<int>(x => x > 100).OrderBy(x => x).Select(x => x);
            foreach (int x in NewSubset)
                Console.WriteLine(x);
        }

        static void Main(string[] args)
        {
            ShowNumber();
            Console.ReadKey();
        }
    }
}
