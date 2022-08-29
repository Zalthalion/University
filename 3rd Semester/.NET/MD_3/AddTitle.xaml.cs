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
    public partial class Window2 : Window
    {
        public Window2()
        {
            InitializeComponent();
            
            List<string> pubDown = new List<string>(); //string kolekcija, kurā glabāsies visi publishers
            List<string> typeDown = new List<string>(); //String kolekcija, kurā glabāsies visi title type

            for (int i = 0; i < 6; i++)
            {
                typeDown.Add(Enum.GetName(typeof(TitleType), i));
            }
            TitleType.ItemsSource = typeDown;



            try
            {
                //Definē savienojumu ar datubāzi
                SqlConnection con = new SqlConnection(DataManager.conString);
                //Sql vaicājumi, kuri vaicā izvēlēties datus no tabulām (tos, kurus vajag)
                SqlCommand cmd = new SqlCommand("select * from publishers", con);
                //Izveido savienojumu ar datubāzi
                con.Open();
                SqlDataAdapter adapter = new SqlDataAdapter(cmd);
                //Izveido datatable kolekciju, kurā tiks ievadīti atlasītie dati
                DataTable dt = new DataTable();
                //Aizpilda iepriekš izveidoto kolekciju
                adapter.Fill(dt);

                //Aizpilda pubDown kolekciju ar publisher nosaukumuem
                string item;
                foreach (DataRow rin in dt.Rows)
                {
                    item = rin.Field<string>("pub_name");
                    pubDown.Add(item);
                }
                //Un izmanto kolekciju kā itemsource priekš dropdown
                TitlePublisher.ItemsSource = pubDown;
                //Izmet iepriekš izveidoto vaicājumu
                cmd.Dispose();
                //Beidz savienojumu ar datubāzi
                con.Close();
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

        }


        private void AddAuthorsToTitle_click(object sender, RoutedEventArgs e)
        {
            
            int errorCnt = 0; //Palīgskaitītājs, kurš skaita, cik kļūdas ir sastaptas
            string errorMsg = "Cannot create Author: \n Error List: \n"; //default error message

            //Pārbauda, vai nav atstāti tukši lauki
            if (TitleTitle.Text == "") { errorCnt++; errorMsg += " - Title Name is required!\n"; };
            
            if (TitlePublishDate.SelectedDate.ToString() == "") { errorCnt++; errorMsg += " - Title Date is required!\n"; };
            if (TitleType.SelectedItem == null) { errorCnt++; errorMsg += " - Title Type is required!\n"; };
            if (TitlePublisher.SelectedItem == null) { errorCnt++; errorMsg += " - Title Publisher is required!\n"; };
            //Ja ir bijušas kļūdas, tad tiek apstādināta darbība un izmests attiecīgs kļūdas paziņojums

            var price = Convert.DBNull;
            //svarīgs solis, pareizi padotu cenu datubāzei (decimal nevar būt null
            try
            {
                if (TitlePrice.Text == "") { price = Convert.DBNull; } else { price = Convert.ToDecimal(TitlePrice.Text); };
            }
            catch (ArgumentOutOfRangeException aoofrex)
            {
                MessageBox.Show(errorMsg + "Wrong input data - " + aoofrex.Message);
            }


            if (errorCnt > 0)
            {
                MessageBox.Show(errorMsg);
                return;
            }
            //Ja kļūdu nav, tad varam mēģināt saglabāt ievadītos Title datus datubāzē
            else
            {
                try
                {
                    string selPububName = TitlePublisher.SelectedItem.ToString();
                    
                    //Definē savienojumu ar datubāzi
                    SqlConnection con = new SqlConnection(DataManager.conString);
                    //Atver savienojumu ar datubāzi
                    con.Open();

                    //vaicājuma string, kurš prasa ievietot konkrētas vērtības tabulā
                    string query = "INSERT INTO titles (title, titleType, price, pubdate, pubID)";
                    query += " VALUES (@Title, @TitleType, @TitlePrice, @TitlePubDate, @TitlePubID)";

                    //Vaicājuma string, kurš atgriež izvēlētā publisher ID
                    string getPubID = "SELECT (ID) FROM publishers where pub_name = '" + selPububName + "'";

                    //https://docs.microsoft.com/en-us/dotnet/api/system.data.sqlclient.sqlcommand?view=netframework-4.8
                    //Reprezentē SQL paziņojumu vai glabāto procedūru izpildei pret SQL datu bāzi
                    //Cik es sapratu, satur instrukcijas, kas jādara un savienojumu, kur jādara
                    SqlCommand GetPubID = new SqlCommand(getPubID, con);
                    SqlCommand myCommand = new SqlCommand(query, con);

                    //Iegūst atgriezto ID
                    int pubID = Convert.ToInt32(GetPubID.ExecuteScalar());

                    //Pievieno parametrus konkrētajam vaicājumam
                    //Nozaudēju atsauci, bet man liekas, ka šādi ir jādara, lai nevarētu ierakstīt sql vaicājumus tīrā tekstā, piem., (DROP TABLE)
                    myCommand.Parameters.AddWithValue("@Title", TitleTitle.Text);
                    myCommand.Parameters.AddWithValue("@TitleType", TitleType.SelectedItem.ToString());
                    myCommand.Parameters.AddWithValue("@TitlePrice", price);
                    myCommand.Parameters.AddWithValue("@TitlePubDate", TitlePublishDate.SelectedDate);
                    myCommand.Parameters.AddWithValue("@TitlePubID", pubID);

                    //Izpilda iepriekš izveidoto vaicājumu (.ExequteNonQuerry() atgriež int vērtību, kas parāda cik rindas tika izmmainītas, bet tas netiks izmantots)
                    myCommand.ExecuteNonQuery();

                    //Lai pievienotu autorus ir vajadzīgs title ID, tāpēc āutoru pievienošana ir citā logā un tajā var tikt tikai, kad ir aizpildīti visi textbox.
                    //Lai varētu saglabāt Title


                    //vaicājuma string, kurš prasa atlasīt konkrētas vērtības tabulā
                    string strsSql = "SELECT MAX(ID) FROM titles";

                    //https://docs.microsoft.com/en-us/dotnet/api/system.data.sqlclient.sqlcommand?view=netframework-4.8
                    //Reprezentē SQL paziņojumu vai glabāto procedūru izpildei pret SQL datu bāzi
                    //Cik es sapratu, satur instrukcijas, kas jādara un savienojumu, kur jādara
                    SqlCommand cmd = new SqlCommand(strsSql, con);

                    //Iegūst tikko izveidotā Title ID
                    int returnedID = Convert.ToInt32(cmd.ExecuteScalar());

                    //Izment visus iepriekš izveidotos vaicājumus
                    myCommand.Dispose();
                    cmd.Dispose();
                    GetPubID.Dispose();
                    //Beidz savienojumu ar datubāzi
                    con.Close();

                    //Atver logu, kurā var pievienot autorus (logu aizverot aizveras arī šis logs)
                    var a = new Window5(returnedID);
                    a.Show();
                    a.Closed += (s, EventArgs) => { this.Close(); };

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


            }
        }
    }
}
