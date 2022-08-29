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
   
    public partial class Window8 : Window
    {
        //Izvēlētā Title indeks

        //ObservableCollection, kurā ir ievadīti izvēlētā Title Autori
        private static ObservableCollection<Author> titleAuthors = new ObservableCollection<Author>();
        public Window8()
        {
            InitializeComponent();
            int indeks = FormManager.i;
            //Aizpilda visus textbox ar izvēlētā Title datiem
            TitName.Text = FormManager.allTitles[indeks].name;
            FormManager.tempAuthors.Clear();
            foreach (Author a in FormManager.authors)
            {

                FormManager.tempAuthors.Add(a);
            }

            ListAuthors.ItemsSource = FormManager.tempAuthors;
            //Aizpilda observablecollection ar visiem Title autoriem
            titleAuthors.Clear();
            foreach(Author a in FormManager.allTitles[indeks].authors)
            {
                titleAuthors.Add(a);
                FormManager.tempAuthors.Remove(a);
            }
            TitPubDate.SelectedDate = FormManager.allTitles[indeks].pubDate;
            
            

            FormManager.ComboBoxPublishers.Clear();
            FormManager.ComboBoxPublishers.Add(new Publisher("-New Publisher-"));
            //Aizpilda ComboBox ar visiem Publisher
            foreach (Publisher box in FormManager.publishers)
            {
                FormManager.ComboBoxPublishers.Add(box);
            }
            CombPub.ItemsSource = FormManager.ComboBoxPublishers;

            //List kolekcija, lai uzglabātu visus TitleType
            List<string> dropDown = new List<string>();

            //Aizpilda kolekciju ar TitleType
            for (int i = 0; i < 6; i++)
            {
                dropDown.Add(Enum.GetName(typeof(TitleType), i));
            }

            //Aizpilda combobox ar visiem TitleType
            foreach (string fill in dropDown)
            {
                TitType.Items.Add(fill);
            }

            //Izmantojot data binding aizpilda abus autoru izvēles listbox
            ListAuthors.ItemsSource = FormManager.tempAuthors;
            TitleAuthors.ItemsSource = titleAuthors;
            CombPub.SelectedItem = FormManager.allTitles[indeks].publisher;
            TitType.SelectedItem = FormManager.allTitles[indeks].titleType.ToString();
        }

        //Metode NewComboBoxItem_Click, kura pievieno jaunu publisher izvēles combobox
        

        //Metode NewAuthor_Click, kura izsauc jauna autora pievienošanas logu
        private void NewAuthor_Click(object sender, RoutedEventArgs e)
        {
            var newAuthor = new Window1();
            newAuthor.Show();
            newAuthor.Closed += (s, EventArgs) => { ListAuthors.Items.Refresh(); };
        }

        //Metode AddTitleAuthors_Click, kura pievieno autoru no viena listbox uz otru
        //Lai vēlāk varētu pievienot vairākus autorus Tite
        private void AddTitleAuthors_Click(object sender, RoutedEventArgs e)
        {
            titleAuthors.Add((Author)ListAuthors.SelectedItem);
            FormManager.tempAuthors.Remove((Author)ListAuthors.SelectedItem);
        }

        //Metode RemoveTitle_Click, kura no pievieno autoru no otra lsitbox uz pirmo
        //Lai noņemtu no Title autoru
        private void RemoveTitle_Click(object sender, RoutedEventArgs e)
        {
            FormManager.tempAuthors.Add((Author)TitleAuthors.SelectedItem);
            titleAuthors.Remove((Author)TitleAuthors.SelectedItem);
        }

        private void CombPub_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (CombPub.SelectedIndex == 0)
            {
                var x = new Window3();
                x.Show();
                x.Closed += (s, EventArgs) => { CombPub.Items.Refresh(); };
            }
            else return;
            CombPub.SelectedIndex = FormManager.ComboBoxPublishers.Count;
        }

        //Title autoru masīvs
        Author[] auth;


        //Metode SaveTitle_Click, kura saglabā visas mainītās vērtības izvēlētajā Tile
        private void SaveTitle_Click(object sender, RoutedEventArgs e)
        {
            int errorCnt = 0;
            string errorMsg = "Can't update Title!\n Error list:\n";
            if (TitName.Text == "") { errorCnt++; errorMsg += "  - Title Name is Required\n"; };
            if (TitPubDate.SelectedDate.ToString() == "") { errorCnt++; errorMsg += "  - Title Publish Date is required\n"; };
            if (CombPub.SelectedItem == null) { errorCnt++; errorMsg += "  - Title Publsiher is required\n"; };
            if (titleAuthors.Count == 0) { errorCnt++; errorMsg += "  - Atleast one Author is required\n"; };
            if (TitType.SelectedItem == null) { errorCnt++; errorMsg += "  - Title Type is required\n"; };

            if (errorCnt > 0)
            {
                MessageBox.Show(errorMsg);
                return;
            }

            try
            {
                int indeks = FormManager.i;
                int i = titleAuthors.Count; //Nosaka masīva izmēru
                auth = new Author[i];       //izveido masīvu
                int j = 0;
                //Aizpilda masīvu
                foreach (Author aut in titleAuthors)
                {
                    auth[j] = aut;
                    j++;
                }

                FormManager.allTitles[indeks].name = TitName.Text;
                FormManager.allTitles[indeks].pubDate = (DateTime)TitPubDate.SelectedDate;
                //Ja tike izvēlēts cits Publisher un ir izvēlēts kāds cits Publisher
                
                FormManager.allTitles[indeks].authors = auth;
                //Ja tike izvēlēts cits Publisher un ir izvēlēts kāds cits Publisher
                if (TitType.SelectedItem.ToString() != FormManager.allTitles[indeks].titleType.ToString() && TitType.SelectedIndex.ToString() != null)
                {
                    //Tad tiek Title pievienots cits TitleType
                    TitleType type = (TitleType)TitType.SelectedIndex;
                    FormManager.allTitles[indeks].titleType = type;
                }
            }
            catch (ArgumentOutOfRangeException aoofrex)
            {
                MessageBox.Show("Nekorekti ieejas dati: " + aoofrex.Message);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            
            //Aizver labošanas logu
            this.Close();
            //Paziņo, ka ir veiktas izmaiņas
            MessageBox.Show("Title has been updated!");
             

        }

        
    }

}
