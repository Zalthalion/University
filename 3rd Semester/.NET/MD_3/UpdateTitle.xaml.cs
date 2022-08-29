using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
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
    public partial class UpdateTitle : Window
    {
        //Izvēlētā rinda    
        
        private DataRow selectedRow;

        //Divas datatable kolekcijas priekš autoru parādīšanas datagridview
        private DataTable titleAut = new DataTable();
        private DataTable allAut = new DataTable();


        public UpdateTitle(DataRow row)
        {
            InitializeComponent();
            selectedRow = row;
            FillAuthors(); //metodes izsaukšana, kura aizpilda visu autoru kolekciju
            

            //Divas string kolekcijas priekš title type un title publisher dropdown
            List<string> publisherDown = new List<string>();
            List<string> typeDown = new List<string>();
            
            //Aizpilda typeDown kolekciju
            for (int i = 0; i < 6; i++)
            {
                typeDown.Add(Enum.GetName(typeof(TitleType), i));
            }
            TitleType.ItemsSource = typeDown;

            //Aizpilda textbox'us
            TitleTitle.Text = row.Field<string>("title");
            TitlePublishDate.SelectedDate = row.Field<DateTime>("pubdate");

            //Pārbauda vai izvēlētā title price ir NULL
            object value = row["price"];
            if(value == DBNull.Value)
            {   
                //Ja ir null, tad atstāj tukšu laukumu
                TitlePrice.Text = "";
            }
            else
            {
                //Ja nav, tad ievada attiecīgu price
                TitlePrice.Text = Convert.ToString(row.Field<decimal>("price"));
            }
            
            

            try
            {
                //Definē savienojumu ar datubāzi
                SqlConnection con = new SqlConnection(DataManager.conString);

                //SQL vaicājumi, kuri vaicā atlasīt vajadzīgos datus
                SqlCommand cmd = new SqlCommand("select * from publishers", con);
                SqlCommand cmd1 = new SqlCommand("select *from publishers WHERE ID = '" + row.Field<int>("pubID") + "'", con);
                SqlCommand cmd3 = new SqlCommand("select * from titleauthor WHERE titleID = '" + row.Field<int>("ID") + "'", con);

                //Sāk savienojumu ar datubāzi
                con.Open();


                SqlDataAdapter adapter = new SqlDataAdapter(cmd);
                SqlDataAdapter adapter1 = new SqlDataAdapter(cmd1);
                SqlDataAdapter adapter3 = new SqlDataAdapter(cmd3);
                
                //Izveido DataTable kolekcijas, kurās tiks saglabāti atlasītie dati
                DataTable dt = new DataTable();
                DataTable dt1 = new DataTable();
                DataTable dt3 = new DataTable();

                //Aizpilda iepriekš izveidotās kolekcijas
                adapter.Fill(dt);
                adapter1.Fill(dt1);
                adapter3.Fill(dt3);


                //Pārstaigā atlasītos autorus, kuri pieder Title
                foreach (DataRow aut in dt3.Rows)
                {
                    foreach (DataRow aut1 in allAut.Rows)
                    { 
                        if (aut.Field<int>("personId") == aut1.Field<int>("ID")) titleAut.Rows.Add(aut1.ItemArray);  
                    }
                }
                TitleAuthors.ItemsSource = titleAut.DefaultView;


                string item;    //string palīgmainīgais
                //Pārstaigā visus esošos publisher un ievieto tos dropdown
                foreach (DataRow rin in dt.Rows)
                {
                    item = rin.Field<string>("pub_name");
                    publisherDown.Add(item);
                }
                TitlePublisher.ItemsSource = publisherDown;

                //Izvēlas attiecīgo publisher 
                DataRow temp = dt1.Rows[dt1.Rows.Count - 1];
                TitlePublisher.SelectedItem = temp.Field<string>("pub_name");
                
                //Izvļeas Attiecīgo Title Type
                int selectedType = 0;
                string titletype = row.Field<string>("titleType");

                for (int i = 0; i < 6; i++)
                {
                    if (string.Compare(publisherDown[i], titletype) == 1) break;
                    selectedType++;
                }
                TitleType.SelectedIndex = selectedType - 1;

                //Izmet ārā iepriekš izveidotos vaicājumus
                cmd1.Dispose();
                cmd.Dispose();
                cmd3.Dispose();

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

                //Aizpilda iepriekš izveidoto kolekciju
                adapter2.Fill(allAut);

                //Izmanto iegūto kolekciju kā ItemSource
                AllAuthors.ItemsSource = allAut.DefaultView;

                //https://stackoverflow.com/questions/2949858/how-to-copy-only-the-columns-in-a-datatable-to-another-datatable/2949878
                //Noklonē kolonnas, lai varētu veikt tālākās darbības
                titleAut = allAut.Clone();

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

        //Metode, kura pievieno title author (vizuāli)
        private void AddAuthor_Click(object sender, RoutedEventArgs e)
        {

            //Kā pārstaigāt datagridview
            //https://stackoverflow.com/questions/15686381/wpf-iterate-through-datagrid
            //Pārbauda vai title jau eksistē šāds autors

            DataRowView dr = (DataRowView)AllAuthors.SelectedItem;
            bool exist = false;
                foreach (DataRowView dr1 in TitleAuthors.ItemsSource)
                {
                    //Ja ir sastapti vienādi ID, tad šāds autors jau pieder Title un par to tiek paziņots
                    if (dr[6].ToString() == dr1[6].ToString())
                    {
                    MessageBox.Show("This author already exists in this Title");
                    exist = true;
                    break;
                    }
                }

                //Ja pārstaigājot visus title autorus, tas neeksistē jau sarakstā, tad to pievieno
            if(!exist)titleAut.Rows.Add(dr.Row.ItemArray);
            DataRow Dr = dr.Row;
            //Izsauc funkciju, kura pievienos autoru title no datubāzes puses
            AddAuthorToDb(Dr, selectedRow.Field<int>("ID"));
            
            


        }

        //Metode, kura noņem no title autoru (gan vizuāli, gan reāli)
        private void RemoveAuthor_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                DataRowView dr = (DataRowView)TitleAuthors.SelectedItem;
                
                //Definē savienojumu ar datubāzi
                SqlConnection con = new SqlConnection(DataManager.conString);
                //Sāk savienojumu ar datubāzi
                con.Open();
                //Vaicājums pēc attiecīgā ieraksta dzēšanas
                string query = "DELETE FROM titleauthor WHERE personId ='" + dr.Row.Field<int>("ID") + "'";
                SqlCommand cmd = new SqlCommand(query, con);
                //Izpilda vaicājumu
                cmd.ExecuteNonQuery();
                //Izmet iepriekš izveidoto vaicājumu
                cmd.Dispose();
                //Beidz savienojumu ar datubāzi
                con.Close();
                //Izdzēš rindu vizuāli
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

        private void NewAuthor_Click(object sender, RoutedEventArgs e)
        {
            //Izsauc jauna autora izveides logu
            var a = new Window1();
            a.Show();
            a.Closed += (s, EventArgs) => { FillAuthors(); }; //Funkcija, kas aizpilda autoru gridview
        }

        private void SaveChanges_Click(object sender, RoutedEventArgs e)
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
            if (TitlePrice.Text == "") { price = Convert.DBNull; } else { price = Convert.ToDecimal(TitlePrice.Text); };

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
                    //Sāk savienojumu ar datubāzi
                    con.Open();
                    //vaicājuma string, kurš prasa atjaunināt konkrētas rindas datus
                    string query = "UPDATE titles SET title = @Title, titleType = @TitleType, price = @TitlePrice, " +
                            "pubdate = @TitlePubDate, pubID = @TitlePubID WHERE ID = '" + selectedRow.Field<int>("ID") + "'";
                    SqlCommand myCommand = new SqlCommand(query, con);
                    //vaicājums atrast ID priekš izvēlētā publisher
                    string getPubID = "SELECT (ID) FROM publishers where pub_name = '" + selPububName + "'";
                    SqlCommand GetPubID = new SqlCommand(getPubID, con);
                    //Izpilda vaicājumu
                    int pubID = Convert.ToInt32(GetPubID.ExecuteScalar());

                    //Pievieno parametrus konkrētajam vaicājumam
                    //Nozaudēju atsauci, bet man liekas, ka šādi ir jādara, lai nevarētu ierakstīt sql vaicājumus tīrā tekstā, piem., (DROP TABLE)
                    myCommand.Parameters.AddWithValue("@Title", TitleTitle.Text);
                    myCommand.Parameters.AddWithValue("@TitleType", TitleType.SelectedItem.ToString());
                    myCommand.Parameters.AddWithValue("@TitlePrice", price);
                    myCommand.Parameters.AddWithValue("@TitlePubDate", TitlePublishDate.SelectedDate);
                    myCommand.Parameters.AddWithValue("@TitlePubID", pubID);
                    //izpilda vaicājumu
                    myCommand.ExecuteNonQuery();
                    //Izmet iepriekš izveidotos vaicājumus
                    myCommand.Dispose();
                    GetPubID.Dispose();
                    //Beidz savienojumu ar datubāzi
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
            }
            this.Close();
            MessageBox.Show("Chenges to the Title have been saved!");
        }


        //Metode, kura pievieno title author (reāli)
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
