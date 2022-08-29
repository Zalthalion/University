using System;
using System.Collections.Generic;
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
    /// Interaction logic for Window1.xaml
    /// </summary>
    public partial class Window1 : Window
    {
        public Window1()
        {
            InitializeComponent();
        }

        //Metode AddAuthor_Click, kura izveido jaunu Author un saglabā tajā attiecīgās vērtības
        private void AddAuthor_Click(object sender, RoutedEventArgs e)
        {

            int errorCnt = 0;
            string errorMsg = "Cannot create Author: \n Error List: \n";

            //Pārbaude, vai vispār kaut kas ir ievadīts iekš textbox, ja nav tad tiek pievienots attiecīgs kļūdas paziņojums.
            //Un autora izveide tiek apturēta
            if(AutName.Text == "") { errorCnt++; errorMsg += "  - Author Name is required \n"; };
            if(AutSurname.Text == "") { errorCnt++; errorMsg += "  - Author Surname is required \n"; };
            if (AutAdress.Text == "") { errorCnt++; errorMsg += "  - Author Adress is required \n"; };
            if (AutCity.Text == "") { errorCnt++; errorMsg += "  - Author City is required \n"; };
            if (AutCountry.Text == "") { errorCnt++; errorMsg += "  - Author Country is required \n"; };
            if (AutState.Text == "") { errorCnt++; errorMsg += "  - Author State is required \n"; };
            if (AutZip.Text == "") { errorCnt++; errorMsg += "  - Author Zip is required \n"; };

            if (errorCnt > 0)
            {
                MessageBox.Show(errorMsg);
                return;
            }
            else
            {
                string name = AutName.Text;
                string surname = AutSurname.Text;
                string adress = AutAdress.Text;
                string city = AutCity.Text;
                string country = AutCountry.Text;
                string state = AutState.Text;
                string zip = AutZip.Text;
                //Izveido jaunu Author
                Author t = new Author(name, surname, adress, city, country, state, zip);
                //Pievieno to globālajai autoru kolekcijai
                FormManager.authors.Add(t);
                //Un pievieno to arī pagaidu Autoru kolekcijai (priekš autoru izvēles izveidojot vai labojot Title)
                FormManager.tempAuthors.Add(t);

                //Aizver logu
                this.Close();
                //Un paziņo, ka ir izveidots jauns Author
                MessageBox.Show("Added a new Author!");
            }
        }
    }
}
