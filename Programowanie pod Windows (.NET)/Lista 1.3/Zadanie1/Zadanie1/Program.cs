using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Zadanie1
{
    public static class StringExtension
        {
        public static bool IsPalindrome(this string S)
        {
            string helper = "";
            for(int i = 0; i < S.Count(); i++)
            {
                if (S[i] != 32)
                    helper += S[i];
            }
            helper = helper.ToLower();
            for(int i = 0; i < helper.Count() / 2; i++)
            {
                if (helper[i] != helper[helper.Count() - 1 - i])
                    return false;
            }
            return true;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            string test = " teStowy STring ";
            string test2 = "kajak";
            string test3 = "Kobyła ma mały bok ";
            Console.WriteLine(test.IsPalindrome());
            Console.WriteLine(test2.IsPalindrome());
            Console.WriteLine(test3.IsPalindrome());
            Console.ReadKey();
        }
    }
}
