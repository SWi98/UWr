using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie3
{
    class Program
    {
        static void GroupNames()
        {
            string path = @"D:\Documents\GitHub\UWr\Programowanie pod Windows (.NET)"
                            + @"\Lista 3\DoZadania3.txt";
            
            string[] data = System.IO.File.ReadAllLines(path);
            var subset =               from name in data 
                                       group name[0] by name[0] into nameGroup
                                       orderby nameGroup.Key
                                       select nameGroup;

            foreach (IGrouping<char, char> x in subset)
            {
                var DistinctSubset = x.Distinct();
                foreach(char name in DistinctSubset)
                {
                    Console.WriteLine(name);
                }
            }


        }
        static void Main(string[] args)
        {
            GroupNames();
            Console.ReadKey();
        }
    }
}
