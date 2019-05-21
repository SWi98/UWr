using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie2
{
    public class Set : IEnumerable
    {
        public class SetEnumerator : IEnumerator
        {
            int index;
            Set set = null;

            public bool MoveNext()
            {
                index++;
                if (index >= set.GetSize())
                    return false;
                else
                    return true;
            }

            public object Current {
                get { return set.GetAtIndex(index); }
            }

            public void Reset()
            {
                index = -1;
            }

            public SetEnumerator(Set mySet)
            {
                this.set = mySet;
                Reset();
            }
        }

        private ArrayList InnerList = new ArrayList();

        private bool InCollection(object E)
        {
            foreach(object elem in InnerList)
            {
                if (E.Equals(1000000))
                {
                    Console.WriteLine("E = {0}, type: {1}; elem = {2}, type: {3}; elem.Equals(E) = {4}, E.Equals(elem) = {5}, ", 
                           E, E.GetType(), elem, elem.GetType(), elem.Equals(E), E.Equals(elem));
                    //Console.WriteLine(elem.Equals(1000000));
                }
                if (elem.Equals(E) || E.Equals(elem))
                {
                    return true;
                }
            }
            return false;
        }

        public IEnumerator GetEnumerator()
        {
            return new SetEnumerator(this);
        }

        public Set() { }

        public void AddElement(object E)
        {
            if (!InCollection(E))
            {
                InnerList.Add(E);
            }
        }

        public int GetSize()
        {
            return InnerList.Count;
        }

        public object GetAtIndex(int index)
        {
            return InnerList[index];
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            Set mySet = new Set();
            mySet.AddElement(1);
            mySet.AddElement(2);
            mySet.AddElement(2);
            mySet.AddElement("2");
            mySet.AddElement("element");
            mySet.AddElement("el");
            mySet.AddElement("element");
            long x = 1000000;
            int y = 1000000;
            mySet.AddElement(x);
            mySet.AddElement(y);
            mySet.AddElement(2);
            Console.WriteLine("\nLiczba elementow: {0}", mySet.GetSize());
            Console.WriteLine("Elementy:");
            foreach(object e in mySet)
            {
                Console.WriteLine("{0, -7}, typ: {1}", e, e.GetType());
            }
            Console.WriteLine();
            Console.WriteLine("x = {0}, typ: {1}; y = {2}, typ: {3}", x, x.GetType(), y, y.GetType());
            Console.WriteLine("x.Equals(y) = {0}", x.Equals(y));
            Console.WriteLine("y.Equals(x) = {0}", y.Equals(x));


            object x = 1;
            object y = 1;

            x.Equals(y)

            Console.ReadKey();
        }
    }
}
