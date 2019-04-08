using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie1
{
    class Program
    {
        static void Main(string[] args)
        {
            int Foo(int x, int y)
            {
                return x * x * x * x * x * x * x * x * x * x * y * y + 2 * x + 2 * y / (x + 5 * y) +
                     x * x * x * x * x * x * x * x * x * x * y * y + 2 * x + 2 * y / (x + 5 * y) +
                     x * x * x * x * x * x * x * x * x * x * y * y + 2 * x + 2 * y * (x * x * x * x * x * x * x * x * x * x * y * y + 2 * x + 2 * y / (x + 5 * y) +
                     x * x * x * x * x * x * x * x * x * x * y * y + 2 * x + 2 * y / (x + 5 * y) +
                     x * x * x * x * x * x * x * x * x * x * y * y + 2 * x + 2 * y) / (x * x * x * x * x * x * x * x * x * x * y * y + 2 * x + 2 * y / (x + 5 * y) +
                     x * x * x * x * x * x * x * x * x * x * y * y + 2 * x + 2 * y / (x + 5 * y));
            }

            dynamic Foo2(dynamic x, dynamic y)
            {
                return x * x * x * x * x * x * x * x * x * x * y * y + 2 * x + 2 * y / (x + 5 * y) +
                     x * x * x * x * x * x * x * x * x * x * y * y + 2 * x + 2 * y / (x + 5 * y) +
                     x * x * x * x * x * x * x * x * x * x * y * y + 2 * x + 2 * y * (x * x * x * x * x * x * x * x * x * x * y * y + 2 * x + 2 * y / (x + 5 * y) +
                     x * x * x * x * x * x * x * x * x * x * y * y + 2 * x + 2 * y / (x + 5 * y) +
                     x * x * x * x * x * x * x * x * x * x * y * y + 2 * x + 2 * y) / (x * x * x * x * x * x * x * x * x * x * y * y + 2 * x + 2 * y / (x + 5 * y) +
                     x * x * x * x * x * x * x * x * x * x * y * y + 2 * x + 2 * y / (x + 5 * y));
            }


            for(int i = 0; i < 10; i++)
            {
                DateTime Start = DateTime.Now;
                for (int j = 0; j < 1000000; j++)
                {
                    Foo(2147483647, 2147483647);
                }
                DateTime End = DateTime.Now;
                Console.WriteLine(End - Start);

                Start = DateTime.Now;
                for (int j = 0; j < 1000000; j++)
                {
                    Foo2(2147483647, 2147483647);
                }
                End = DateTime.Now;
                Console.WriteLine(End - Start);

                Console.WriteLine("-------");
            }
            Console.ReadKey();
        }
    }
}
