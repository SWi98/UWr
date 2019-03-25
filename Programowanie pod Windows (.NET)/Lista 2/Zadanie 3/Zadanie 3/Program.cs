using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// Zademnostrować metody ConvertAll, FindAll, ForEach, RemoveAll i Sort z klasy List<T>
// korzystając z anonimowych delegacji
namespace Zadanie_3
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> test_list = new List<int>();

            Console.WriteLine("Domyslna lista:");
            for (int i = 0; i < 10; i++)
            {
                test_list.Add(i * 4);
            }
            writeList(test_list);

            List<string> test_list_string = test_list.ConvertAll(
                new Converter<int, string>(delegate (int x)
                {
                    return x.ToString() + " string";
                }));

            Console.Write("\n");
            Console.WriteLine("Przekonwertowana na typ string:");

            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine(test_list_string[i]);
            }

            List<int> test_findall = test_list.FindAll(delegate (int x)
            {
                return x % 6 == 0;
            });

            Console.Write("\n");
            Console.WriteLine("Nowa lista, zlozona z elementow " +
                "podzielnych przez 6 (FindAll):");
            writeList(test_findall);
            Console.Write("\n");
            Console.WriteLine("Wypisanie elementow podzielonych przez 10 korzystajac" +
                " z ForEach:");

            test_list.ForEach(delegate (int x)
            {
                if(x % 10 == 0)
                    Console.WriteLine(x);
            });

            test_list.RemoveAll(delegate (int x)
            {
                return x > 10;
            });

            Console.Write("\n");
            Console.WriteLine("Usuniecie elementow wiekszych niz 10 uzywajac DeleteAll:");
            writeList(test_list);
            Console.WriteLine("\nPosortowanie malejaco uzywajac .Sort():");

            test_list.Sort(delegate (int x, int y)
            {
                if (x == y)
                    return 0;
                else if (x > y)
                    return -1;
                else
                    return 1;
            });

            writeList(test_list);
            Console.ReadKey();
        }
        
        static void writeList(List<int> list)
        {
            for (int i = 0; i < list.Count(); i++)
                Console.WriteLine(list[i]);
        }
    }
}
