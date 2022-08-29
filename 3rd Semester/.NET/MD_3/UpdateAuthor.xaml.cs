using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
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

namespace MD_3
{
    public partial class UpdateAuthor : Window
    {
        public static int ID;
        public UpdateAuthor(DataRow row)
        {
            InitializeComponent();

            //Aizpilda attiecīgos textbox'us ar izvēlētā Author vērtībām
            AutName.Text = row.Field<string>("fname");
            AutSurname.Text = row.Field<string>("lname");
            AutPhone.Text = row.Field<string>("phone");
            AutAdress.Text = row.Field<string>("address");
            AutCity.Text = row.Field<string>("city");
            AutState.Text = row.Field<string>("state");
            AutZip.Text = row.Field<string>("zip");
            AutContract.IsChecked = row.Field<bool>("contract");
            ID = row.Field<int>("ID");
        }

        private void UpdateAuthor_Click(object sender, RoutedEventArgs e)
        {
            
            int errorCnt = 0; //Palīgskaitītājs, kurš skaita, cik kļūdas ir sastaptas
            string errorMsg = "Cannot update Author: \n Error List: \n";    //Default error message

            //Pārbauda vai Nav atstāti pilnīgi tukši laukumi
            if (AutName.Text == "") { errorCnt++; errorMsg += "  - Author Name is required \n"; };
            if (AutSurname.Text == "") { errorCnt++; errorMsg += "  - Author Surname is required \n"; };
            if (AutPhone.Text == "") { errorCnt++; errorMsg += "  - Author Phone Number is required \n"; };
            if (AutAdress.Text == "") { errorCnt++; errorMsg += "  - Author Adress is required \n"; };
            if (AutCity.Text == "") { errorCnt++; errorMsg += "  - Author City is required \n"; };
            if (AutState.Text == "") { errorCnt++; errorMsg += "  - Author State is required \n"; };
            if (AutZip.Text == "") { errorCnt++; errorMsg += "  - Author Zip is required \n"; };

            //Pārbauda vai ievadītie dati ir īstajā garumā
            if (AutState.Text.Length != 2) { errorCnt++; errorMsg += " - Author State has to be 2 symbols long\n"; };
            if (AutZip.Text.Length != 5) { errorCnt++; errorMsg += " - Author zip has to be 5 symbols long\n"; };
            if (AutPhone.Text.Length > 12) { errorCnt++; errorMsg += " - Author phone number can't be longer than 12 symbols\n"; };

            //Ja ir bijušas kļūdas, tad tiek apstādināta darbība un izmests attiecīgs kļūdas 
            if (errorCnt > 0)
            {
                MessageBox.Show(errorMsg);
                return;
            }
            //Ja kļūdu nav, tad varam mēģināt saglabāt ievadītos Author datus datubāzē
            else
            {
                try
                {
                    //Definē savienjojumu ar datubāzi
                    SqlConnection con = new SqlConnection(DataManager.conString);
                    //Izveido savienojumu ar datubāzi
                    con.Open();

                    //Vaicājuma string, kurš prasa atjaunot vērtības tabulā
                    string query = "UPDATE author SET phone = @AuthorPhone, address = @AuthorAddress, city = @AuthorCity, " +
                        "state = @AuthorState, zip = @AuthorZip, contract = @AuthorContract, fname = @AuthorName, lname = @AuthorSurename Where ID = '" + ID + "'";

                    //https://docs.microsoft.com/en-us/dotnet/api/system.data.sqlclient.sqlcommand?view=netframework-4.8
                    //Reprezentē SQL paziņojumu vai glabāto procedūru izpildei pret SQL datu bāzi
                    //Cik es sapratu, satur instrukcijas, kas jādara un savienojumu, kur jādara
                    SqlCommand myCommand = new SqlCommand(query, con);

                    //Pievieno parametrus konkrētajam vaicājumam
                    //Nozaudēju atsauci, bet man liekas, ka šādi ir jādara, lai nevarētu ierakstīt sql vaicājumus tīrā tekstā, piem., (DROP TABLE)
                    myCommand.Parameters.AddWithValue("@AuthorPhone",  AutPhone.Text);
                    myCommand.Parameters.AddWithValue("@AuthorAddress", AutAdress.Text);
                    myCommand.Parameters.AddWithValue("@AuthorCity", AutCity.Text);
                    myCommand.Parameters.AddWithValue("@AuthorState", AutState.Text);
                    myCommand.Parameters.AddWithValue("@AuthorZip", AutZip.Text);
                    myCommand.Parameters.AddWithValue("@AuthorContract", AutContract.IsChecked);
                    myCommand.Parameters.AddWithValue("@AuthorName", AutName.Text);
                    myCommand.Parameters.AddWithValue("@AuthorSurename", AutSurname.Text);

                    //Izpilda iepriekš izveidoto vaicājumu (.ExequteNonQuerry() atgriež int vērtību, kas parāda cik rindas tika izmmainītas, bet tas netiks izmantots)
                    myCommand.ExecuteNonQuery();
                    //Izmet iepriekš izveidoto vaicājumu
                    myCommand.Dispose();
                    //Aizver savienojumu ar datubāzi
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
                MessageBox.Show("Author updated successfully!");
            }
        }
    }
}
