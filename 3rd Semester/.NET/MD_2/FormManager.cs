using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace MD_2
{
   public static class FormManager
    {
        //Faila atrašānās vieta
        const string BinFileName = @"..\..\data.bin";

        //Visas nepieciešamās kolekcijas
        public static ObservableCollection<Title> allTitles = new ObservableCollection<Title>();
        public static ObservableCollection<Publisher> publishers = new ObservableCollection<Publisher>();
        public static ObservableCollection<Author> authors = new ObservableCollection<Author>();
        public static ObservableCollection<Author> tempAuthors = new ObservableCollection<Author>();
        public static ObservableCollection<Author> titleAut = new ObservableCollection<Author>();
        public static ObservableCollection<Employee> employees = new ObservableCollection<Employee>();
        public static ObservableCollection<Publisher> ComboBoxPublishers = new ObservableCollection<Publisher>();
        
        public static int i = 0;

        //Funkcija, kura izveido testa datus
        public static void createTestData()
        {

            //Izveido 3 autorus
            Author second = new Author("Juris", "Freidenfelds", "Raiņa bulvāris 19", "Rīga", "Latvija", "Rīga", "LV-1050");
            Author fourth = new Author("Juris", "Kociņš", "Nekurienes iela 13", "Ventspils", "Latvija", "Centrs", "LV-1060");
            Author fifth = new Author("Juris", "Zariņš", "Martas Rinkas iela 3", "Rīga", "Latvija", "Vecmīlgrāvis", "LV-1015");

            //Divus autoru masīvus
            Author[] jauns = new Author[] { second };

            Author[] autori = new Author[]
            {
                second,
                fourth,
                fifth,
            };

            //Izveido 5 publisher, 3 title un 2 employe
            Publisher pub1 = new Publisher("Couple of geniuses");
            Publisher pub2 = new Publisher("Kind people");
            Publisher pub3 = new Publisher("Very kind people");

            Title sixth = new Title("Shrek", DateTime.Now, pub1 , autori, TitleType.psychology);
            Title seventh = new Title("Shrek 2", new DateTime(1999, 01, 07), pub2, jauns, TitleType.business);
            Title eight = new Title("Shrek 3 - happily ever after", new DateTime(1999, 01, 07), pub3 , jauns, TitleType.business);
            Publisher nineth = new Publisher("Zvaigzne ABC");
            Publisher tenth = new Publisher("Jāņa Rozes Grāmatnīca");
            Employee first = new Employee("Juris", "Freidenfelds", DateTime.Now, nineth);
            Employee third = new Employee("Juris", "Freidenfelds", DateTime.Now, tenth);

            //pievieno izveidotās vērtības globālajai kolekcijām

            employees.Add(first);
            authors.Add(second);
            employees.Add(third);
            authors.Add(fourth);
            authors.Add(fifth);
            allTitles.Add(sixth);
            allTitles.Add(seventh);
            allTitles.Add(eight);
            publishers.Add(nineth);
            publishers.Add(tenth);
            publishers.Add(pub1);
            publishers.Add(pub2);
            publishers.Add(pub3);

        }

        public static void saveToFile(string fileName = BinFileName)
        {
            Stream TestFileStream = File.Create(fileName);      //izveido bināro failu, ja tāda nav norādītajā direktorijā
            BinaryFormatter serializer = new BinaryFormatter();
            //serializer.Serialize(TestFileStream, person);       //Sirealizē person globālo kolekciju
            serializer.Serialize(TestFileStream, authors);
            serializer.Serialize(TestFileStream, employees);
            serializer.Serialize(TestFileStream, allTitles);    //Sirealizē allTitle globālo kolekciju
            serializer.Serialize(TestFileStream, publishers);
            TestFileStream.Close();
        }
        //Metode readFromFile, kura desirealizē datus no binārā faila
        public static void readFromFile(string fileName = BinFileName)
        {
            if (File.Exists(fileName))
            {
                Stream TestFileStream = File.OpenRead(fileName);    //Atver failu
                BinaryFormatter deserializer = new BinaryFormatter();
                ObservableCollection<Author> fileAuthors = (ObservableCollection<Author>)deserializer.Deserialize(TestFileStream);
                ObservableCollection<Employee> fileEmployees = (ObservableCollection<Employee>)deserializer.Deserialize(TestFileStream);
                ObservableCollection<Title> fileTitles = (ObservableCollection<Title>)deserializer.Deserialize(TestFileStream);
                ObservableCollection<Publisher> filePublishers = (ObservableCollection<Publisher>)deserializer.Deserialize(TestFileStream);
                TestFileStream.Close();

                authors = fileAuthors;
                employees = fileEmployees;
                allTitles = fileTitles;
                publishers = filePublishers;
                MessageBox.Show("Data read from a file succsesfully!");
            }
            else
            {
                MessageBox.Show("The file does not exist! :(");
                return;
            }
        }



    }
}



