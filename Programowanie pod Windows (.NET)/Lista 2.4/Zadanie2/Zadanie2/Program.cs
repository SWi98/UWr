using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Schema;
using System.IO;

namespace Zadanie2
{
    class Program
    {
        static void Main(string[] args)
        {
            string xsdPath = @"D:\Documents\GitHub\UWr\Programowanie pod Windows (.NET)\Lista 2.4\Zadanie2\Zadanie2\Students.xsd";
            string xmlPath = @"D:\Documents\GitHub\UWr\Programowanie pod Windows (.NET)\Lista 2.4\Zadanie2\Zadanie2\XMLFile1.xml";

            XmlReaderSettings xmlSettings = new XmlReaderSettings();
            xmlSettings.Schemas.Add("http://www.w3.org/2001/XMLSchema", xsdPath);
            xmlSettings.ValidationType = ValidationType.Schema;
            xmlSettings.ValidationEventHandler += new ValidationEventHandler(xmlSettingsValidationEventHandler);

            XmlReader studentsReader = XmlReader.Create(xmlPath, xmlSettings);
            int i = 0;

            while(studentsReader.Read())
            {
                Console.WriteLine(i);
                i++;
            }

            Console.ReadKey();

            XmlDocument StudentsDoc = new XmlDocument();
            StudentsDoc.Load(xmlPath);
            StudentsDoc.Save(Console.Out);
            Console.ReadKey();
        }

        public static void xmlSettingsValidationEventHandler(object sender, ValidationEventArgs args)
        {
            if(args.Severity == XmlSeverityType.Warning)
            {
                Console.Write("WARNING: ");
                Console.WriteLine(args.Message);
            }
            else if(args.Severity == XmlSeverityType.Error)
            {
                Console.Write("ERROR: ");
                Console.WriteLine(args.Message);
            }
        }
    }
}
