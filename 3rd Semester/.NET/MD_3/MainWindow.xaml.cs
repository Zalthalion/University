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
using System.Windows.Navigation;
using System.Windows.Shapes;

using System.Data.Linq;
using System.Data.Linq.Mapping;



     

//https://www.c-sharpcorner.com/UploadFile/deepak.sharma00/data-binding-in-wpf-datagrid-control-using-sql-server-databa/
using System.Configuration;
using System.Data;
using System.Data.SqlClient;



namespace MD_3
{
    public partial class MainWindow : Window 
    {
        
        public MainWindow()
        {
            InitializeComponent();
            FillTitlesGrid();           //Aizpilda Titles laukumu
            FillPublishersGrid();       //Aizpilda Publishers laukumu
            FillPAuthorsGrid();         //Aizpilda Authors laukumu
        }

        //Aizpilda titles Grid
        //https://www.youtube.com/watch?v=MQ8t2bHtGlg&feature=youtu.be kā pieslēgt datubāzi
        //https://parallelcodes.com/wpf-datagrid-bind-sql-database/ kā aizpildīt grid

        private void FillTitlesGrid()
        {
            try
            {
                //Definē savienojumu ar datubāzi
                SqlConnection con = new SqlConnection(DataManager.conString);
                //vaicājums atlasīt datus no titles tabulas
                SqlCommand cmd = new SqlCommand("select * from titles", con);
                //Sāk savienojumu ar datubāzi
                con.Open();
                //Izpilda vaicājumu
                SqlDataAdapter adapter = new SqlDataAdapter(cmd);
                //Izveido datatable kolekciju, kurā saglabāt datus
                DataTable dt = new DataTable();
                //Azipilda iepriekš izveidoto datubāzi
                adapter.Fill(dt);

                Titles.ItemsSource = dt.DefaultView;

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
        
        //Aizpilda Author grid
        private void FillPAuthorsGrid()
        {

            try
            {
                //Definē savienojumu ar datubāzi
                SqlConnection con = new SqlConnection(DataManager.conString);
                //vaicājums atlasīt datus no author tabulas
                SqlCommand cmd = new SqlCommand("select * from author", con);
                //Sāk savienojumu ar datubāzi
                con.Open();
                //Izpilda vaicājumu
                SqlDataAdapter adapter = new SqlDataAdapter(cmd);
                //Izveido datatable kolekciju, kurā saglabāt datus
                DataTable dt2 = new DataTable();
                //Azipilda iepriekš izveidoto datubāzi
                adapter.Fill(dt2);
                Authors.ItemsSource = dt2.DefaultView;


                //https://stackoverflow.com/questions/18528736/how-to-retrieve-values-from-the-last-row-in-a-datatable
                //Lai iegūtu pēdējās rindas ID, jo author tabulai ID neiet automātiski uz priekšu
                DataRow lastRow = dt2.Rows[dt2.Rows.Count - 1];
                DataManager.lastID = lastRow.Field<int>("ID");

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

        //Aizpilda publishers Grid
        private void FillPublishersGrid()
        {
            try
            {
                //Definē savienojumu ar datubāzi
                SqlConnection con = new SqlConnection(DataManager.conString);
                //vaicājums atlasīt datus no publisher tabulas
                SqlCommand cmd = new SqlCommand("select * from publishers", con);
                //Sāk savienojumu ar datubāzi
                con.Open();
                //Izpilda vaicājumu
                SqlDataAdapter adapter = new SqlDataAdapter(cmd);
                //Izveido datatable kolekciju, kurā saglabāt datus
                DataTable dt1 = new DataTable();
                //Azipilda iepriekš izveidoto datubāzi
                adapter.Fill(dt1);
                Publishers.ItemsSource = dt1.DefaultView;



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

        //Izveido jaunu Author
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            //Izsauc jauna autora izveides logu
            var a = new Window1();
            a.Show();
            a.Closed += (s, EventArgs) => { FillPAuthorsGrid(); };
        }

        //Author Dzēšana
        private void DeleteAuthor_Click(object sender, RoutedEventArgs e)
        {
            //Pārbauda vai ir izvēlēts Autors
            if (Authors.SelectedItem == null) { MessageBox.Show("Please, select an Author!"); return; }
            //https://social.msdn.microsoft.com/Forums/vstudio/en-US/d3f223ac-7fca-486e-8939-adb46e9bf6c9/how-can-i-get-yesno-from-a-messagebox-in-wpf?forum=wpf
            //Pārliecinas par dzēšanu
            if (MessageBox.Show("Are you sure you want to delete this Author?", "Question", MessageBoxButton.YesNo, MessageBoxImage.Warning) == MessageBoxResult.No)
            {
                
            }
            else
            {
                try
                {
                    
                    //Definē savienojumu ar datubāzi
                    SqlConnection con = new SqlConnection(DataManager.conString);
                    //Iegūst izvēlētās rindas datus
                    DataRowView selectedRow = (DataRowView)Authors.SelectedItem;
                    DataRow rinda = (DataRow)selectedRow.Row;
                    //Iegūst izvēlētās rindas ID
                    int ID = rinda.Field<int>("ID");

                    //Sāk saviwnojumu ar datubāzi
                    con.Open();
                    //vaicājumi izdzēst no author tabulas izvēlēto autoru
                    SqlCommand command = new SqlCommand("DELETE FROM author WHERE ID = '" + ID + "'", con);
                    //Tā kā Autora ID ir foreign key citā tabulā, ir jāizdzēš visi ieraksti no saistītajām tabulām
                    SqlCommand childDel = new SqlCommand("DELETE FROM titleauthor WHERE personId = '" + ID + "'", con);

                    //Izpilda vaicājumu
                    childDel.ExecuteNonQuery();
                    command.ExecuteNonQuery();

                    //Izmet iepriekš veidotos vaicājumus
                    childDel.Dispose();
                    command.Dispose();

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
               
                    MessageBox.Show("Author deleted successfully");
                    FillPAuthorsGrid();
            }
            
        }
        
        //Izveido jaunu title
        private void NewTitle_Click(object sender, RoutedEventArgs e)
        {
            //Izsauc jauna title izveides logu
            var a = new Window2();
            a.Show();
            a.Closed += (s, EventArgs) => { FillTitlesGrid(); }; //pēc loga aizvēršanas tiek atjaunināts title datagridview
        }

        //Izdzēš title
        private void DeleteTitle_Click(object sender, RoutedEventArgs e)
        {
            //Pārbauda, vai vispār ir izvēlēts kāds title
            if (Titles.SelectedItem == null) { MessageBox.Show("Please, select a Title!"); return; }

            //Pārbaude, vai tiešām lietotājs grib dzēst ierakstu
            if (MessageBox.Show("Are you sure you want to delete this Title?", "Question", MessageBoxButton.YesNo, MessageBoxImage.Warning) == MessageBoxResult.No)
            {

            }
            else
            {
                try
                {
                    //definē savienojumu ar datubāzi
                    SqlConnection con = new SqlConnection(DataManager.conString);
                    
                    //Iegūst izvēlētā Title ID
                    DataRowView selectedRow = (DataRowView)Titles.SelectedItem;
                    DataRow rinda = (DataRow)selectedRow.Row;
                    int ID = rinda.Field<int>("ID");

                    //Sāk savienojumu ar datubāzi
                    con.Open();

                    //Viacājumi izdzēst ierakstus pie konkrēta title ID
                    SqlCommand command = new SqlCommand("DELETE FROM titles WHERE ID = '" + ID + "'", con);
                    //Tā kā Title ID ir foreign key, ir jāizdzēš arī visi citu tabulu ieraksti, kas ir sasitīti ar šo title
                    SqlCommand childDel = new SqlCommand("DELETE FROM titleauthor WHERE titleID = '" + ID + "'", con);

                    //Izpilda vaicājumus
                    childDel.ExecuteNonQuery();
                    command.ExecuteNonQuery();

                    //Izmet iepriekš izveidotos vaicājumus
                    childDel.Dispose();
                    command.Dispose();

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
                    MessageBox.Show("Title deleted successfully");
                    FillTitlesGrid();
            }
                
        }

        //Izveido publisher
        private void CreatePublisher_Click(object sender, RoutedEventArgs e)
        {
            //Izsauc jauna publisher izvides logu
            var createPubWindow = new Window3();
            createPubWindow.Show();
            createPubWindow.Closed += (s, EventArgs) => { FillPublishersGrid(); }; //Pēc loga aizvēršanas tiek atjaunināts publisher grid

        }

        //Izdzēš publisher
        private void DeletePublisher_Click(object sender, RoutedEventArgs e)
        {
            //Pārbauda vai vispār ir izvēlēts kāds publisher, ko dzēst
            if (Publishers.SelectedItem == null) { MessageBox.Show("Please, select a Publisher!"); return; }
            //Pārliecinas, vai lietotājs tiešām grib dzēst izvēlēto publisher
            if (MessageBox.Show("Are you sure you want to delete this Publisher? \n(This might affect Titles also)", "Question", MessageBoxButton.YesNo, MessageBoxImage.Warning) == MessageBoxResult.No)
            {

            }
            else
            {
                try
                {
                    //Definē savienojumu ar datubāzi
                    SqlConnection con = new SqlConnection(DataManager.conString);

                    //Iegūst izvēlētā publisher ID
                    DataRowView selectedRow = (DataRowView)Publishers.SelectedItem;
                    DataRow rinda = (DataRow)selectedRow.Row;
                    int ID = rinda.Field<int>("ID");

                    //Sāk savienojumu ar datubāzi
                    con.Open();
                    
                    //vaicājums atlasīt visus titles, kur ir attiecīgais publisher ID
                    SqlCommand selectTitleID = new SqlCommand("SELECT * FROM titles WHERE pubID = '" + ID + "'", con);
                    //izpilda vaicājumu
                    SqlDataAdapter adapter = new SqlDataAdapter(selectTitleID);
                    //Izveido datatable kolekciju, kurā tiek saglabāta vaicājuma atgrieztā tabula
                    DataTable dt1 = new DataTable();
                    //Aizpilda kolekciju ar iegūtajiem datiem
                    adapter.Fill(dt1);

                    //Saraksts, kurā atradīsies visi titles, kuriem ir izvēlētais publisher
                    List<int> toBeDeleted = new List<int>();
                    //aizpilda kolekciju
                    foreach (DataRow rinf in dt1.Rows)
                    {
                        toBeDeleted.Add(rinf.Field<int>("ID"));
                    }

                    //izdzēš visus titleauthor ierakstus, kur titleID sakrīt ar dzēšamajiem
                    //(Jo publisher ir saist;its ar title, bet title ir saistīts ar titleauthor)
                    foreach(int i in toBeDeleted)
                    {
                        SqlCommand del = new SqlCommand("DELETE FROM titleauthor WHERE titleID = '" + i + "'",con);
                        del.ExecuteNonQuery();
                        del.Dispose();
                    }
                    
                    //Izdzēš izvēlēto publisher
                    SqlCommand childDel = new SqlCommand("DELETE FROM titles WHERE pubID = '" + ID + "'", con);
                    //Tā kā publisher ir foreign key un saistīts ar title, ir jāizdzēš visi title, kuriem bija izdzēstais publisher
                    SqlCommand command = new SqlCommand("DELETE FROM publishers WHERE ID = '" + ID + "'", con);


                    //Izpilda vaicājumus
                    childDel.ExecuteNonQuery();
                    command.ExecuteNonQuery();

                    //izmet ārā iepriekš izveidotos vaicājumus
                    childDel.Dispose();
                    command.Dispose();

                    //beidz savienojumu ar datubāzi
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
                
                    MessageBox.Show("Publisher deleted successfully!");
                    FillPublishersGrid();
                    FillTitlesGrid();

                
            }
                
        }

        //Update Publisher
        private void UpdatePublisher_Click(object sender, RoutedEventArgs e)
        {
            //Pārbauda vai kāds publisher ir izvēlēts
            if (Publishers.SelectedItem == null) { MessageBox.Show("Please, select a Publisher!"); return; }

            //Iegūst izvēlētā publisher datus
            DataRowView selectedRow = (DataRowView)Publishers.SelectedItem;
            DataRow rinda = (DataRow)selectedRow.Row;

            //Izsauc publisher atjaunināšanas logu
            var UpdatePublisherWindow = new Window4(rinda);
            UpdatePublisherWindow.Show();
            UpdatePublisherWindow.Closed += (s, EventArgs) => { FillPublishersGrid(); }; //kas logs tiek aizvērts, tiek atjaunināts publisher grid
        }

        //Update Author
        private void UpdateAuthor_Click(object sender, RoutedEventArgs e)
        {
            //Pārbauda vai ir izvēlēts author, ko atjaunināt
            if (Authors.SelectedItem == null) { MessageBox.Show("Please, select an Author!"); return; }

            //iegūst izvēlētās rindas datus
            DataRowView selectedRow = (DataRowView)Authors.SelectedItem;
            DataRow rinda = (DataRow)selectedRow.Row;

            //izsauc autora atjaunināšanas logu padodt izvēlēto rindu
            var UpdateAuthorWindow = new UpdateAuthor(rinda);
            UpdateAuthorWindow.Show();
            UpdateAuthorWindow.Closed += (s, EventArgs) => { FillPAuthorsGrid(); }; //Aizverot logu, tiek atjaunināts author grid
        }

        private void UpdateTitle_Click(object sender, RoutedEventArgs e)
        {
            //Pārbauda vai ir izvēlēts title, ko atjaunināt
            if (Titles.SelectedItem == null) { MessageBox.Show("Please, select a Title!"); return; }

            //iegūst izvēlētās rindas datus
            DataRowView selectedRow = (DataRowView)Titles.SelectedItem;
            DataRow rinda = (DataRow)selectedRow.Row;

            //izsauc title atjaunināšanas logu padodt izvēlēto rindu
            var UpdatePublisherWindow = new UpdateTitle(rinda);
            UpdatePublisherWindow.Show();
            UpdatePublisherWindow.Closed += (s, EventArgs) => { FillTitlesGrid(); }; //aizverot logu tiek atjaunināts titles grid
        }

        private void MoreDetails_Click(object sender, RoutedEventArgs e)
        {
            //Pārbauda vai ir izvēlēts title, ko atjaunināt
            if (Titles.SelectedItem == null) { MessageBox.Show("Please, select a Title!"); return; }

            //iegūst izvēlētās rindas datus
            DataRowView selectedRow = (DataRowView)Titles.SelectedItem;
            DataRow rinda = (DataRow)selectedRow.Row;

            //izsauc title vairāk info logu padodt izvēlēto rindu
            var MoreDetailsWindow = new MoreTitleDetails(rinda);
            MoreDetailsWindow.Show();
        }
    }

}

