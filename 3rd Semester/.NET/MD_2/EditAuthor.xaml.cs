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
   
    public partial class Window7 : Window
    {
        public Window7()
        {
            
            InitializeComponent();
            int indeks = FormManager.i;

            //Loga atvēršanās brīdī ievada visos textbox, konkrētā Author vērtības
            AutName.Text = FormManager.authors[indeks].name;
            AutSurname.Text = FormManager.authors[indeks].surname;
            AutAdress.Text = FormManager.authors[indeks].adress;
            AutCity.Text = FormManager.authors[indeks].city;
            AutCountry.Text = FormManager.authors[indeks].country;
            AutState.Text = FormManager.authors[indeks].state;
            AutZip.Text = FormManager.authors[indeks].zip;

            
        }

        //Izlabotās vērtības saglabā atiiecīgajos laukos
        private void SaveAuthor_Click(object sender, RoutedEventArgs e)
        {
            int indeks = FormManager.i;
            int errorCnt = 0; //Kļūdu skaitītājs
            string errorMsg = "Cannot update Author: \n Error List: \n"; //Default error message

            //Pārbauda, vai ir aizpildīti lauki, ja nav tad kļūdu skaitītājam +1 un paziņojumam attiecīgi tiek pievienots ziņojums kurš lauks nav aizpildīts
            if(AutName.Text == "") { errorCnt++; errorMsg += "   - Author Name is required! \n"; };
            if (AutSurname.Text == "") { errorCnt++; errorMsg += "   - Author Surname is required! \n"; };
            if (AutAdress.Text == "") { errorCnt++; errorMsg += "   - Author Adress is required! \n"; };
            if (AutCity.Text == "") { errorCnt++; errorMsg += "   - Author City is required! \n"; };
            if (AutCountry.Text == "") { errorCnt++; errorMsg += "   - Author Country is required! \n"; };
            if (AutState.Text == "") { errorCnt++; errorMsg += "   - Author State is required! \n"; };
            if (AutZip.Text == "") { errorCnt++; errorMsg += "   - Author Text is required! \n"; };

            //Ja ir vismaz 1 kļūda, tad tiek apstādināta rediģēšana un izmests kļūdu paziņojums
            if(errorCnt > 0)
            {
                MessageBox.Show(errorMsg);
                return;
            }
            else
            {
                //Ja viss kārtībā, tad saglabā veiktās izmaiņas
                FormManager.authors[indeks].name = AutName.Text;
                FormManager.authors[indeks].surname = AutSurname.Text;
                FormManager.authors[indeks].adress = AutAdress.Text;
                FormManager.authors[indeks].city = AutCity.Text;
                FormManager.authors[indeks].country = AutCountry.Text;
                FormManager.authors[indeks].state = AutState.Text;
                FormManager.authors[indeks].zip = AutZip.Text;

                //Aizver logu
                this.Close();
                //Paziņo, ka ir veiktas izmaiņas
                MessageBox.Show("Author has been updated!");
            }
            
        }
    }
}
