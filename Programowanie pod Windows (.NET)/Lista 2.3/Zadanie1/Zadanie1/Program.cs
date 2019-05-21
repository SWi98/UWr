using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie1
{
    public class Complex: IFormattable
    {
        double r, z;

        public Complex(double a, double b)
        {
            r = a;
            z = b;
        }

        public string ToString(string format, IFormatProvider provider)
        {
            if (String.IsNullOrEmpty(format))
            {
                format = "W";
            }
            if(format.ToUpperInvariant() ==  "W")
            {
                return "[" + r.ToString() + ", " + z.ToString() + "]";
            }
            else
            {
                return r.ToString() + " " + z.ToString() + "i";
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Complex z = new Complex(4, 3);
            Console.WriteLine(String.Format("{0}", z));
            Console.WriteLine(String.Format("{0:d}", z));
            Console.WriteLine(String.Format("{0:w}", z));
            Console.ReadKey();
        }
    }
}
