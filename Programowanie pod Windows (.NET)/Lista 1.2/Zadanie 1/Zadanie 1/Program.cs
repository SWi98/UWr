using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace Zadanie_1
{
    class Program
    {
        static void Main(string[] args)
        {
            DateTime Start, End; TimeSpan TestTime;
            for (int k = 0; k < 5; k++)
            {
                ArrayList arr = new ArrayList();
                List<string> list = new List<string>();
                int liczbaProb = 1000000;

                Start = DateTime.Now;
                for (int i = 0; i < liczbaProb; i++)
                {
                    arr.Add("abc");
                }
                End = DateTime.Now;
                TestTime = End - Start;
                Console.WriteLine("Czas dodania " + liczbaProb + " elementow do ArrayList: " + TestTime);

                Start = DateTime.Now;
                for (int i = 0; i < liczbaProb; i++)
                {
                    list.Add("abc");
                }
                End = DateTime.Now;
                TestTime = End - Start;

                Console.WriteLine("Czas dodania " + liczbaProb + " elementow do List<>: " + TestTime);

                liczbaProb = 100;
                Start = DateTime.Now;
                for (int i = 0; i < liczbaProb; i++)
                {
                    foreach (var elem in arr)
                    {
                        //var x = elem;
                    }
                }
                End = DateTime.Now;
                TestTime = End - Start;

                Console.WriteLine("Czas przejrzenia wszystkich elementow ArrayList " + liczbaProb +
                    " razy: " + TestTime);

                Start = DateTime.Now;
                for (int i = 0; i < liczbaProb; i++)
                {
                    foreach(var elem in list)
                    {
                        //var x = elem;
                    }
                }
                End = DateTime.Now;
                TestTime = End - Start;

                Console.WriteLine("Czas przejrzenia wszystkich elementow List<> " + liczbaProb +
                    " razy: " + TestTime);

                liczbaProb = 1000;
                Start = DateTime.Now;
                for (int i = 0; i < liczbaProb; i++)
                {
                    arr.RemoveAt(i);
                }
                End = DateTime.Now;
                TestTime = End - Start;
                Console.WriteLine("Czas usuniecia " + liczbaProb +
                    " elementow z ArrayList: " + TestTime);

                Start = DateTime.Now;
                for (int i = 0; i < liczbaProb; i++)
                {
                    list.RemoveAt(i);
                }
                End = DateTime.Now;
                TestTime = End - Start;
                Console.WriteLine("Czas usuniecia " + liczbaProb +
                    " elementow z List<>: " + TestTime);

                Console.Write("\n");
            }

            Console.WriteLine("\n---------------------------------------------\n");

            for(int k = 0; k < 5; k++)
            {
                int liczbaProb = 1000000;
                Hashtable htable = new Hashtable();
                Dictionary<int, int> dict = new Dictionary<int, int>();

                Start = DateTime.Now;
                for (int i = 0; i < liczbaProb; i++)
                {
                    htable.Add(i, i);
                }
                End = DateTime.Now;
                TestTime = End - Start;
                Console.WriteLine("Czas dodania " + liczbaProb + " elementow do Hashtable: " +
                    TestTime);

                Start = DateTime.Now;
                for (int i = 0; i < liczbaProb; i++)
                {
                    dict.Add(i, i);
                }
                End = DateTime.Now;
                TestTime = End - Start;
                Console.WriteLine("Czas dodania " + liczbaProb + " elementow do Dictionary: " +
                    TestTime);

                Start = DateTime.Now;
                for (int i = 0; i < liczbaProb; i++)
                {
                    htable.Remove(i);
                }
                End = DateTime.Now;
                TestTime = End - Start;
                Console.WriteLine("Czas usuniecia " + liczbaProb + " elementow z Hashtable: " +
                    TestTime);

                Start = DateTime.Now;
                for (int i = 0; i < liczbaProb; i++)
                {
                    dict.Remove(i);
                }
                End = DateTime.Now;
                TestTime = End - Start;
                Console.WriteLine("Czas usuniecia " + liczbaProb + " elementow z Dictionary: " +
                    TestTime);

                Start = DateTime.Now;
                foreach(var elem in htable)
                {
                    var x = elem;
                }
                End = DateTime.Now;
                TestTime = End - Start;
                Console.WriteLine("Czas przejrzenia " + liczbaProb + " elementow z Hashtable: " +
                    TestTime);

                Start = DateTime.Now;
                foreach(var elem in dict)
                {
                    var x = elem;
                }
                End = DateTime.Now;
                TestTime = End - Start;
                Console.WriteLine("Czas przejrzenia " + liczbaProb + " elementow z Dictionary: " +
                    TestTime);

                Console.Write("\n");
            }
            Console.ReadKey();
        }
    }
}
