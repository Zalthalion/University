using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
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

//Šeit tiek izveidots jauns Publisher

namespace MD_3
{
    public partial class Window3 : Window
    {
        public Window3()
        {
            InitializeComponent();
        }

        private void CreatePublisher_Click(object sender, RoutedEventArgs e)
        {
            int errorCnt = 0; //Palīgskaitītājs, kurš skaita, cik kļūdas ir sastaptas
            string errorMsg = "Cannot create Author: \n Error List: \n";   //default error message

            //Pārbauda vai nav tukši laukumi
            if (PublisherName.Text == "") { errorCnt++; errorMsg += " - Publisher Name is required!\n"; }
            if (PublisherCity.Text == "") { errorCnt++; errorMsg += " - Publisher City is required!\n"; }
            if (PublisherCountry.Text == "") { errorCnt++; errorMsg += " - Publisher Country is required!\n"; }
            
            //Ja ir bijušas kļūdas, tad tiek apstādināta darbība un izmests attiecīgs kļūdas paziņojums
            if (errorCnt > 0)
            {
                MessageBox.Show(errorMsg);
                return;
            }
            //Ja kļūdu nav, tad varam mēģināt saglabāt ievadītos Publisher datus datubāzē
            else
            {
                try
                { 
                    //Definē savienojuma ceļu, kuru izmantos, lai savienotos ar datubāzi
                    SqlConnection con = new SqlConnection(DataManager.conString);
                    //atver savienojumu ar datubāzi
                    con.Open();

                    //Vaicājuma string, kurš prasa ievietot vērtības tabulā
                    string query = "INSERT INTO publishers (pub_name, city, country)";
                    query += " VALUES (@PublisherName, @PublisherCity, @PublisherCountry)";

                    //https://docs.microsoft.com/en-us/dotnet/api/system.data.sqlclient.sqlcommand?view=netframework-4.8
                    //Reprezentē SQL paziņojumu vai glabāto procedūru izpildei pret SQL datu bāzi
                    //Cik es sapratu, satur instrukcijas, kas jādara un savienojumu, kur jādara
                    SqlCommand myCommand = new SqlCommand(query, con);

                    //Pievieno parametrus konkrētajam vaicājumam
                    //Nozaudēju atsauci, bet man liekas, ka šādi ir jādara, lai nevarētu ierakstīt sql vaicājumus tīrā tekstā, piem., (DROP TABLE)
                    myCommand.Parameters.AddWithValue("@PublisherName", PublisherName.Text);
                    myCommand.Parameters.AddWithValue("@PublisherCity", PublisherCity.Text);
                    myCommand.Parameters.AddWithValue("@PublisherCountry", PublisherCountry.Text);

                    //Izpilda iepriekš izveidoto vaicājumu (.ExequteNonQuerry() atgriež int vērtību, kas parāda cik rindas tika izmmainītas, bet tas netiks izmantots)
                    myCommand.ExecuteNonQuery();
                    //Izmet iepriekš izveidoto vaicājumu
                    myCommand.Dispose();
                    //Aizver savienojumu
                    con.Close();
                }
                catch (ArgumentOutOfRangeException aoofrex)
                {
                    MessageBox.Show("Wrong input data: " + aoofrex.Message);
                }
                catch (SqlException ex)
                {
                    MessageBox.Show(ex.Message);
                }
                catch (InvalidOperationException XcpInvOP)
                {
                    MessageBox.Show(XcpInvOP.Message);
                }
                catch (Exception Xcp)
                {
                    MessageBox.Show(Xcp.Message);
                }
                
             //Aizver logu
             this.Close();
             //Un paziņo, ka ir izveidots jauns Author
             MessageBox.Show("Added a new Publisher!");
                
            }
        }
    }
}
