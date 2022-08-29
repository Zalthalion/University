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
  
    public partial class Window5 : Window
    {
        //Pataisa izvēlēto rinu un tās ID pieejamu visām metodēm
        //Kā arī izveido DataTable kolekciju, kurā tiks glabāti izvēlētie autori
        private DataTable titleAut = new DataTable();
        private static int titleID;
        public Window5(int ID)
        {
            InitializeComponent();
            titleID = ID;
            FillAuthors(); //Izsauc funkciju, kura aizpilda Visu Author data grid
           
        }


        //Metode, kura aizpilda visu autoru datagrid
        private void FillAuthors()
        {
            try
            {
                //Definē savienojumu ar datubāzi
                SqlConnection con = new SqlConnection(DataManager.conString);

                //SQL vaicājums, kurš izvēlēsies datus no author tabulas
                SqlCommand cmd2 = new SqlCommand("select * from author", con);

                //Atver savienojumu ar datubāzi
                con.Open();

                SqlDataAdapter adapter2 = new SqlDataAdapter(cmd2);

                //Izveido datatable kolekcijas, kurās tiks ievadīti izvēlētie dati
                DataTable dt2 = new DataTable();

                //Aizpilda iepriekš izveidoto kolekciju
                adapter2.Fill(dt2);

                //Izmanto iegūto kolekciju kā ItemSource
                AllAuthors.ItemsSource = dt2.DefaultView;

                //https://stackoverflow.com/questions/2949858/how-to-copy-only-the-columns-in-a-datatable-to-another-datatable/2949878
                //Noklonē kolonnas, lai varētu veikt tālākās darbības
                titleAut = dt2.Clone();

                //Izmanto klonēto kolekciju kā Itemsource
                TitleAuthors.ItemsSource = titleAut.DefaultView;

                //Izment iepriekš izveidoto vaicājumu
                cmd2.Dispose();
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


        //Metode, kura pievieno autoru Title (vizuāli)
        private void AddAuthor_Click(object sender, RoutedEventArgs e)
        {
            DataRowView dr = (DataRowView)AllAuthors.SelectedItem;
            bool exist = false;

            //Pārbauda vai Title jau nepieder izvēlētais autors
            foreach (System.Data.DataRowView dr1 in TitleAuthors.ItemsSource)
            {
                if (dr[6].ToString() == dr1[6].ToString())
                {
                    //Ja pieder, tad par to tiek paziņots un tiek apturēta darbība
                    MessageBox.Show("This author already exists in this Title");
                    exist = true;
                    break;
                }
            }

            //Ja izvēlētāis autors neeksistē Title, tad to pievieno gan vizuāli, gan reāli
            if (!exist) 
            {
                titleAut.Rows.Add(dr.Row.ItemArray);
                DataRow Dr = dr.Row;
                AddAuthorToDb(Dr, titleID);
            }
        }


        //Metode, kura noņem autoru no title (gan vizuāli, gan reāli)
        private void RemoveAuthor_Click(object sender, RoutedEventArgs e)
        {
            DataRowView dr = (DataRowView)TitleAuthors.SelectedItem;
            try 
            {
                //Definē savienojumu ar datubāzi
                SqlConnection con = new SqlConnection(DataManager.conString);
                //Izveido savienojumu ar datubāzi
                con.Open();
                //Vaicājuma string, kurā tiek vaicāts izdzēst konkrēto autoru no Title
                string query = "DELETE FROM titleauthor WHERE personId ='" + dr.Row.Field<int>("ID") + "'";


                //https://docs.microsoft.com/en-us/dotnet/api/system.data.sqlclient.sqlcommand?view=netframework-4.8
                //Reprezentē SQL paziņojumu vai glabāto procedūru izpildei pret SQL datu bāzi
                //Cik es sapratu, satur instrukcijas, kas jādara un savienojumu, kur jādara
                SqlCommand cmd = new SqlCommand(query, con);
                //Izpilda iepriekš izveidoto vaicājumu (.ExequteNonQuerry() atgriež int vērtību, kas parāda cik rindas tika izmmainītas, bet tas netiks izmantots)
                cmd.ExecuteNonQuery();
                //Izment visus iepriekš izveidotos vaicājumus
                cmd.Dispose();
                //Beidz savienojumu ar datubāzi
                con.Close();
                //Vizuāli izdzēš autoru no title
                dr.Row.Delete();
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

        //Metode, kura izsauc jauna autora izveides logu
        private void NewAuthor_Click(object sender, RoutedEventArgs e)
        {
            var a = new Window1();
            a.Show();
            //Event, kurš "refresh'o" datagrid pēc loga aizvēršanas
            a.Closed += (s, EventArgs) => { FillAuthors(); }; 
        }

        //Metode, kas vizuāli parāda, ka ir izveidots jauns title
        private void SaveAuthors_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Created a new title!");
            this.Close();
        }


        //Metode, kura pievieno autoru Title (Reāli)
        private void AddAuthorToDb(DataRow AuthorRow, int titleID)
        {
            try
            {
                int returnedOrder; //int tipa mainīgais, kurā tiks saglabāta autora secība

                //Definē savienojumu ar datubāzi
                SqlConnection con = new SqlConnection(DataManager.conString);
                //Izveido savienojumu ar datubāzi
                con.Open();

                //Vaicājuma string, kurš prasa izvēlēties rindu skaitu
                string select = "SELECT COUNT(*) FROM titleauthor WHERE titleID = '" + titleID + "'";

                //https://docs.microsoft.com/en-us/dotnet/api/system.data.sqlclient.sqlcommand?view=netframework-4.8
                //Reprezentē SQL paziņojumu vai glabāto procedūru izpildei pret SQL datu bāzi
                //Cik es sapratu, satur instrukcijas, kas jādara un savienojumu, kur jādara
                SqlCommand rowCnt = new SqlCommand(select, con);

                //ExecuteScalar() atgriež iegūto vērtību, izpildot vaicājumu
                int RowCount = Convert.ToInt32(rowCnt.ExecuteScalar());
                //izmet iepriekš izveidoto vaicājumu
                rowCnt.Dispose();
                //Ja vēl nav neviens author pievienots Title (nav rindu), tad autora secības nr ir 1
                if (RowCount == 0)
                {
                    returnedOrder = 1;
                }
                else
                {   
                    //Vaicājuma string, kurš prasa lielāko autora secības numuru
                    string strsSql = "SELECT MAX(au_ord) FROM titleauthor WHERE titleID = '" + titleID + "'";

                    //https://docs.microsoft.com/en-us/dotnet/api/system.data.sqlclient.sqlcommand?view=netframework-4.8
                    //Reprezentē SQL paziņojumu vai glabāto procedūru izpildei pret SQL datu bāzi
                    //Cik es sapratu, satur instrukcijas, kas jādara un savienojumu, kur jādara
                    SqlCommand cmd = new SqlCommand(strsSql, con);

                    //ExecuteScalar() atgriež iegūto vērtību, izpildot vaicājumu
                    //Tā iegūstot lielāko autora kārtas numuru
                    returnedOrder = Convert.ToInt32(cmd.ExecuteScalar());
                    returnedOrder++;
                    //Izmet iepriekš izveidoto vaicājumu
                    cmd.Dispose();
                }

                //Vaicājuma string, kurš prasa ievietot konkrētas vērtības tabulā
                string query = "INSERT INTO titleauthor (au_ord, titleID, personID)";
                query += " VALUES (@AuthorOrder, @TitleID, @PersonID)";

                //https://docs.microsoft.com/en-us/dotnet/api/system.data.sqlclient.sqlcommand?view=netframework-4.8
                //Reprezentē SQL paziņojumu vai glabāto procedūru izpildei pret SQL datu bāzi
                //Cik es sapratu, satur instrukcijas, kas jādara un savienojumu, kur jādara
                SqlCommand myCommand = new SqlCommand(query, con);
                
                //Pievieno parametrus konkrētajam vaicājumam
                //Nozaudēju atsauci, bet man liekas, ka šādi ir jādara, lai nevarētu ierakstīt sql vaicājumus tīrā tekstā
                myCommand.Parameters.AddWithValue("@AuthorOrder", returnedOrder);
                myCommand.Parameters.AddWithValue("@TitleID", titleID);
                myCommand.Parameters.AddWithValue("@PersonID", AuthorRow.Field<int>("ID"));


                //Izpilda iepriekš izveidoto vaicājumu (.ExequteNonQuerry() atgriež int vērtību, kas parāda cik rindas tika izmmainītas, bet tas netiks izmantots)
                myCommand.ExecuteNonQuery();
                //Izmet iepriekš izveidoto vaicājumu
                myCommand.Dispose();
                //Aizver savienojumu ar datubāzi
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
    }
}
