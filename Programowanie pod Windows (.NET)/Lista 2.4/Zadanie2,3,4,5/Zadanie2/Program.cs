using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Schema;
using System.IO;
using System.Xml.Serialization;
using System.Xml.Linq;

namespace Zadanie2
{

    public class Register
    {
        public Register() { students = new List<student>(); }

        [XmlElement("student")]
        public List<student> students { get; set; }
    }

    [XmlRoot("register")]
    public class student
    {
        [XmlAttribute("Name")]
        public string Name;// { get; set; }

        [XmlAttribute("Surname")]
        public string Surname { get; set; }

        [XmlAttribute("BirthDate")]
        public string BirthDate { get; set; }

        [XmlElement("Address")]
        public Address address { get; set; }

        [XmlElement("TemporaryAddress")]
        public TemporaryAddress tempAddress { get; set;}

        [XmlElement("Classes")]
        public Classes classes { get; set; }
    }

    public class Address
    {
        [XmlAttribute("City")]
        public string City { get; set; }

        [XmlAttribute("Street")]
        public string Street { get; set; }
    }

    public class TemporaryAddress
    {
        [XmlAttribute("City")]
        public string City { get; set; }

        [XmlAttribute("Street")]
        public string Street { get; set; }
    }

    public class Classes
    {
        public Classes() { AllClasses = new List<SingleClass>(); }

        [XmlElement("SingleClass")]
        public List<SingleClass> AllClasses { get; set; }
    }

    public class SingleClass
    {
        [XmlAttribute("Name")]
        public string Name { get; set; }

        [XmlAttribute("Grade")]
        public float Grade { get; set; }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string xsdPath = @"D:\Documents\GitHub\UWr\Programowanie pod Windows (.NET)\Lista 2.4\Zadanie2\Zadanie2\Students.xsd";
            string xmlPath = @"D:\Documents\GitHub\UWr\Programowanie pod Windows (.NET)\Lista 2.4\Zadanie2\Zadanie2\XMLFile1.xml";
            string DocPath = @"D:\Documents\GitHub\UWr\Programowanie pod Windows (.NET)\Lista 2.4\Zadanie2\Zadanie2\test.xml";
            // VALIDACJA
            XmlReaderSettings xmlSettings = new XmlReaderSettings();
            xmlSettings.Schemas.Add("", xsdPath);
            xmlSettings.ValidationType = ValidationType.Schema;
            xmlSettings.ValidationEventHandler += new ValidationEventHandler(xmlSettingsValidationEventHandler);
            XmlReader studentsReader = XmlReader.Create(xmlPath, xmlSettings);

            while (studentsReader.Read()) { }

            Console.WriteLine("Koniec validacji");
            Console.ReadKey();  

            // DESERIALIZACJA DO LISTY OBIEKTÓW student
            XmlReader studentsReader2 = XmlReader.Create(xmlPath);
            XmlSerializer serializer = new XmlSerializer(typeof(List<student>), new XmlRootAttribute("register"));
            List<student> testlist = (List<student>)serializer.Deserialize(studentsReader2);
            WriteRegister(testlist);
            Console.ReadKey();


            //2.4.5
            XmlDocument StudentsDoc = new XmlDocument();
            StudentsDoc.Load(xmlPath);
            StudentsDoc.Save(Console.Out);
            //StudentsDoc.Save(DocPath);
            Console.ReadKey();


            /*char l;
            Console.WriteLine("Wpisz literę:");
            l = Convert.ToChar(Console.ReadLine());
            XElement register = XElement.Load(xmlPath);

             // Reszta, ale nie działa
            XmlTextWriter w = new XmlTextWriter("testy.xml", new UTF8Encoding());
            XmlTextReader r = new XmlTextReader(xmlPath);
            w.WriteStartElement("register");
            while (r.Read())
            {
                w.WriteNode(r, false);
               // Console.WriteLine(r.Name.ToString());
            }
            w.WriteEndElement();*/

            Console.ReadKey();
        }

        public static void WriteRegister(List<student> StudentList)
        {
            for(int i = 0; i < StudentList.Count(); i++)
            {
                string Name = StudentList[i].Name;
                string Surname = StudentList[i].Surname;
                string Birthdate = StudentList[i].BirthDate;
                string c1 = StudentList[i].address.City;
                string s1 = StudentList[i].address.Street;
                string c2 = StudentList[i].tempAddress.City;
                string s2 = StudentList[i].tempAddress.Street;
                Console.WriteLine("{0} {1}, Birthdate: {2}", Name, Surname, Birthdate);
                Console.WriteLine("Address: {0}, {1}; Temporary Address: {2}, {3}", c1, s1, c2, s2);
                Console.WriteLine("Classes:");
                WriteClasses(StudentList[i].classes.AllClasses);
                Console.Write("\n");
            }

            void WriteClasses(List<SingleClass> ClassList)
            {
                for(int i = 0; i < ClassList.Count(); i++)
                {
                    string Name = ClassList[i].Name;
                    float Grade = ClassList[i].Grade;
                    Console.WriteLine("{0}, Grade: {1}", Name, Grade);
                }
            }
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



