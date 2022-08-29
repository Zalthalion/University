using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace MD_2
{
    /// <summary>
    /// Interaction logic for Window4.xaml
    /// </summary>
    public partial class Window4 : Window
    {

  
        public Window4()
        {
            InitializeComponent();

            //Izveido globālu kolekciju, kura būs kā informācijas avots combobox'am
            //No kura var izvēlēties TitleType
            List<string> dropDown = new List<string>();
            //Aizpilda kolekciju
            for (int i = 0; i < 6; i++)
            {
                dropDown.Add(Enum.GetName(typeof(TitleType), i));
            }
            foreach (string fill in dropDown)
            {
                TitType.Items.Add(fill);
            }

            //Notīra combobox items, lai nedublētos
            FormManager.ComboBoxPublishers.Clear();

            //Pirmo elementu pievieno "New publisher", kas tiks izmantots jauna publisher izveidei
            FormManager.ComboBoxPublishers.Add(new Publisher("-New Publisher-"));

            //Aizpilda combobox ar visiem publisher, kuri ir publisher kolekcijā
            foreach(Publisher pub in FormManager.publishers)
            {
                FormManager.ComboBoxPublishers.Add(pub);
            }
            CombPub.ItemsSource = FormManager.ComboBoxPublishers;


            //Principā nokopē authors kolekciju, lai netiktu sabojāta oriģinālā kolekcija ar turpmākām darbībām
            FormManager.tempAuthors.Clear();
            foreach(Author aut in FormManager.authors)
            {
                FormManager.tempAuthors.Add(aut);
            }
            
            //Aizpilda listbox ar attiecīgajām kolekcijām
            ListAuthors.ItemsSource = FormManager.tempAuthors;
            TitleAuthors.ItemsSource = FormManager.titleAut;
        }


        
         
        //Funkcija, kura izsauc "New Author" logu, lai izveidotu jaunu autoru, ja tas nav sarakstā
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            var x = new Window1();
            x.Show();
            x.Closed += (s, EventArgs) => { ListAuthors.Items.Refresh(); };
        }

        //Vizuāli - pārvieto no visu autoru list box uz title autoru list box
        //Funkcionāli - izvēlēto autoru pārvieto no vienas kolekcijas uz otru
        private void AddTitleAuthors_Click(object sender, RoutedEventArgs e)
        {
            FormManager.titleAut.Add((Author)ListAuthors.SelectedItem);
            FormManager.tempAuthors.Remove((Author)ListAuthors.SelectedItem);          
        }

        //Vizuāli - pārvieto no title autoru list box uz visu autoru list box
        //Funkcionāli - izvēlēto autoru pārvieto no vienas kolekcijas uz otru
        private void RemoveTitle_Click(object sender, RoutedEventArgs e)
        {
            FormManager.tempAuthors.Add((Author)TitleAuthors.SelectedItem);
            FormManager.titleAut.Remove((Author)TitleAuthors.SelectedItem);
        }

        //Autoru masīvs, lai varētu izveidot jaunu Title
        Author[] auth;
     
        private void AddTitle_Click(object sender, RoutedEventArgs e)
        {
            


            int errorCnt = 0; //Error skaitītājs
            string errorMsg = "Can't create a Title!\n Error list:\n"; //Default error message texts
            
            //Pārbauda vai lauki nav atstāti tukši, ja ir, tad tiek pieskaitīts +1 pie kļūdu skaitītāja un pievienots kļūdas teksts 
            if (TitName.Text == "") { errorCnt++; errorMsg += "  - Title Name is Required\n"; };
            if (TitPubDate.SelectedDate.ToString() == "") { errorCnt++; errorMsg += "  - Title Publish Date is required\n"; };
            if (CombPub.SelectedItem == null) { errorCnt++; errorMsg += "  - Title Publsiher is required\n"; };
            if (FormManager.titleAut.Count == 0) { errorCnt++; errorMsg += "  - Atleast one Author is required\n"; };
            if (TitType.SelectedItem == null) { errorCnt++;errorMsg += "  - Title Type is required\n"; };
            

            //Ja kļūdu skaitītājs ir lielāks par 0, tad tiek izmests kļūdas paziņojums un netiek izveidots jauns Title
            if (errorCnt > 0)
            {
                MessageBox.Show(errorMsg);
                return;
            }
            //Ja kļūdu skaitītājs nav 0, tad var izveidot jaunu titile
            else
            {
                //No iepriekš aizpildītā titleAut kolekcijas datus pārliek uz autoru masīvu
                //Gan jau ir ērtāks veids kā šo izdarīt
                int i = FormManager.titleAut.Count;
                auth = new Author[i];
                int j = 0;
                foreach (Author aut in FormManager.titleAut)
                {
                    auth[j] = aut;
                    j++;
                }

                string name = TitName.Text;
                DateTime date = (DateTime)TitPubDate.SelectedDate;
                Publisher p = new Publisher(CombPub.Text);

                TitleType type = (TitleType)TitType.SelectedIndex;
                Title t = new Title(name, date, p, auth, type);
                FormManager.allTitles.Add(t);
                FormManager.i = CombPub.SelectedIndex;
            }
            FormManager.titleAut.Clear();
            this.Close();
            MessageBox.Show("Pievienots jauns Title!");
        }

        //Funkcija, kura izsauc jauna Publisher izveides logu, ja tiek izvēlēts 0-tais combobox item ("-New Publisher-")
        private void CombPub_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (CombPub.SelectedIndex == 0)
            {
                var n = new Window3();
                n.Show();
                n.Closed += (s, EventArgs) =>
                {
                    CombPub.Items.Refresh();
                };
                CombPub.SelectedIndex = FormManager.ComboBoxPublishers.Count;
            }
            else return;
        }
    }
}
