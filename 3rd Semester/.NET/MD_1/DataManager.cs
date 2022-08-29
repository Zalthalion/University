using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;

namespace MD_1
{
    public static class DataManager
    {
        //Divas globālas kolekcijas, vienā tiek glabāti autori un darbinieki, bet otrā titles, 
        private static List<Person> person = new List<Person>();
        //private static List<Object> AuthEmp = new List<Object>();
        private static List<Title> allTitles = new List<Title>();

        //Izveido 3 author un 2 Employee
        public static void createPerosns()
        {
            Employee first = new Employee("Juris", "Freidenfelds", DateTime.Now, new Publisher("Zvaignzne ABc"));
            Author second = new Author("Juris", "Freidenfelds", "Raiņa bulvāris 19", "Rīga", "Latvija", "Rīga", "LV-1050");
            Employee third = new Employee("Juris", "Freidenfelds", DateTime.Now, new Publisher("Diena"));
            Author fourth = new Author("Juris", "Freidenfelds", "Raiņa bulvāris 19", "Rīga", "Latvija", "Rīga", "LV-1050");
            Author fifth = new Author("Juris", "Freidenfelds", "Raiņa bulvāris 19", "Rīga", "Latvija", "Rīga", "LV-1050");

            //pievieno izveidotās vērtības globālajai kolekcijai

            person.Add(first);
            person.Add(second);
            person.Add(third);
            person.Add(fourth);
            person.Add(fifth);
        }
        public static void createTitles()
        {
            //Autoru masīvs, lai Title būtu vairāk Author
            Author[] autori = new Author[]
            {
                new Author("Juris", "Kociņš", "Raiņa bulvāris 19", "Rīga", "Latvija", "Rīga", "LV-1050"),
                new Author("Juris", "Kalniņš", "Raiņa bulvāris 19", "Rīga", "Latvija", "Rīga", "LV-1050"),
                new Author("Juris", "Kociņš", "Raiņa bulvāris 19", "Rīga", "Latvija", "Rīga", "LV-1050"),
        };

            Author[] jauns = new Author[] { new Author("Juris", "Kociņš", "Raiņa bulvāris 19", "Rīga", "Latvija", "Rīga", "LV-1050") };
            //Izveido 3 title
            Title first = new Title("Shrek", DateTime.Now, new Publisher("Couple of geniuses"), autori, TitleType.psychology);
            Title second = new Title("Shrek 2", new DateTime(1999, 01, 07), new Publisher("Kind people"), jauns, TitleType.business);
            Title third = new Title("Shrek 3 - happily ever after", new DateTime(1999, 01, 07), new Publisher("Kind people"), jauns, TitleType.business);

            //Pievieno izveidotos title globālajai kolekcijai
            allTitles.Add(first);
            allTitles.Add(second);
            allTitles.Add(third);
        }

        //Metode print(), kura izdrukā visas vērtības no globālajām kolekcijām
        public static void print()
        {
            //Foreach cikls, kurš pārstaigā visu person masīvu
            foreach (Person a in person)
            {
                //Ja objkts ir Employee tad tiek izsaukta Employee asText metode
                if (a.GetType().ToString() == "MD_1.Employee")
                {
                    Employee b = new Employee();
                    b = (Employee)a;
                    Console.WriteLine(b.asText());
                }
                //Ja nē tad tiek izsaukta Author asText metode
                else
                {
                    Author b = new Author();
                    b = (Author)a;
                    Console.WriteLine(b.asText());
                }
            }

            foreach (Title c in allTitles)
            {
                //Izdrukā visus title
                Title b = new Title();
                b = (Title)c;
                Console.Write(b.asText() + " Authors: ");
                //Izdrukā visus Title saturošos autorus
                foreach (Author aut in b.authors) { Console.Write(aut.name + " " + aut.surname + "; "); }
                Console.WriteLine();

            }


        }
        //deklarē jaunizveidotā faila atrašanās vietu
        const string BinFileName = @"..\..\data.bin";

        //metode save to file, kura sirealizē datus binārajā failā
        public static void saveToFile(string fileName = BinFileName)
        {
            Stream TestFileStream = File.Create(fileName);      //izveido bināro failu, ja tāda nav norādītajā direktorijā
            BinaryFormatter serializer = new BinaryFormatter();
            serializer.Serialize(TestFileStream, person);       //Sirealizē person globālo kolekciju
            serializer.Serialize(TestFileStream, allTitles);    //Sirealizē allTitle globālo kolekciju
            TestFileStream.Close();
        }

        //Metode readFromFile, kura desirealizē datus no binārā faila
        public static void readFromFile(string fileName = BinFileName)
        {
            if (File.Exists(fileName))
            {
                Stream TestFileStream = File.OpenRead(fileName);    //Atver failu
                BinaryFormatter deserializer = new BinaryFormatter();
                List<Person> filePersons = (List<Person>)deserializer.Deserialize(TestFileStream);
                List<Title> fileTitles = (List<Title>)deserializer.Deserialize(TestFileStream);
                TestFileStream.Close();
                allTitles = fileTitles;
                person = filePersons;

            }
        }

    }
}


/*  7. Izveidot statisku klasi “DataManager”, kas satur:
*       •	Globālu(as) kolekciju(as) vai masīvu(s), kas saturētu elementus ar tipiem Author un Employee.
*       •	Globālu kolekciju vai masīvu, kas saturētu elementus ar tipu Title.
*       •	Metodi “createPersons” testa datu radīšanai, kas kolekcijā/masīvā pievieno 5 Person (vismaz 1 Author un vismaz 1 Employee).
*       •	Metodi “createTitles” Testa datu radīšanai, kas rada vismaz 3 Title 1 Publisher un vismaz 1 Title, ar vismaz 2 autoriem;
*       •	Metodi “print”, kas izdrukā informāciju par visiem kolekcijās esošajiem elementiem.
*       •	Metodi “saveToFile”, kas visu Kolekciju datus saglabātu failā;
*       •	Metodi “readFromFile”, kas visu Kolekciju datus nolasītu no faila;
*/