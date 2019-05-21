using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;
using System.Reflection;
using System.Threading;
using System.IO;

namespace Zadanie8
{
    class Program
    {
        public static void DisplayAllCultures()
        {
            Console.WriteLine("CULTURE ISO ISO WIN DISPLAYNAME                              ENGLISHNAME");
            foreach (CultureInfo ci in CultureInfo.GetCultures(CultureTypes.NeutralCultures))
            {
                Console.Write("{0, -3}", ci.Name);
                Console.Write(" {0, -3}", ci.TwoLetterISOLanguageName);
                Console.Write(" {0, -3}", ci.ThreeLetterISOLanguageName);
                Console.Write(" {0, -3}", ci.ThreeLetterWindowsLanguageName);
                Console.Write(" {0,-40}", ci.DisplayName);
                Console.WriteLine(" {0, -40}", ci.EnglishName);
                Console.Write("\n");
            }
        }

        public static void DisplayDate(string name)
        {
            CultureInfo ci1 = new CultureInfo(name);
            Console.WriteLine(DateTime.Now.ToString(ci1.DateTimeFormat.LongDatePattern, ci1));
            for(int i = 1; i <= 12; i++)
            {
                string fullMonthName = new DateTime(2019, i, 1).ToString("MMMM", ci1);
                string shortMonthName = ci1.DateTimeFormat.GetAbbreviatedMonthName(i);
                Console.WriteLine("{0}. {1} {2}", i, fullMonthName, shortMonthName);
            }
            Console.WriteLine();

            string[] fullDayNames = ci1.DateTimeFormat.DayNames;
            string[] shortDayNames = ci1.DateTimeFormat.AbbreviatedDayNames;
            for(int i = 1; i <= 6; i++)
            {
                Console.WriteLine("{0}. {1} {2}", i, fullDayNames[i], shortDayNames[i]);
            }
            Console.WriteLine("{0}. {1} {2}", 0, fullDayNames[0], shortDayNames[0]);
            Console.WriteLine();

        }

        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            DisplayDate("en-US");
            DisplayDate("de-DE");
            DisplayDate("fr-FR");
            DisplayDate("ru-RU");
            DisplayDate("ar-AR");
            DisplayDate("cs-CZ");
            DisplayDate("pl-PL");
            Console.ReadKey();

        }
    }
}
