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

//Šeit ir parādīta papildus informācija par Title

namespace MD_3
{
    public partial class MoreTitleDetails : Window
    {
        //Pataisa izvēlēto rindu un tās ID pieejamu visām metodēm
        private static DataRow rin;
        public MoreTitleDetails(DataRow row)
        {
            InitializeComponent();
            rin = row;

            //Saraksts, kurā būs visi Title autoru ID
            List<int> autoru_id = new List<int>();

            //Aizpilda attiecīgos textbox'us ar izvēlētā Title rindas datiem
            TitleTitle.Text = row.Field<string>("title");
            TitleType.Text = row.Field<string>("titleType");
            TitlePubDate.Text = (row.Field<DateTime>("pubdate")).ToString();

            //Pārbauda vai price ir NULL
            object value = row["price"];
            if (value == DBNull.Value)
            {
                //Ja ir NULL tad atstāj tukšu laukumu
                TitlePrice.Text = "";
            }
            else
            {
                //Ja nav tad ieraksta cenu
                TitlePrice.Text = Convert.ToString(row.Field<decimal>("price"));
            }
            

            try
            {
                //Definē savienojumu ar datubāzi
                SqlConnection con = new SqlConnection(DataManager.conString);

                //Sql vaicājumi, kuri vaicā izvēlēties datus no tabulām (tos, kurus vajag)
                SqlCommand cmd = new SqlCommand("select * from publishers WHERE ID = '" + row.Field<int>("pubID") + "'", con);
                SqlCommand cmd1 = new SqlCommand("select * FROM titleauthor WHERE titleID = '" + row.Field<int>("ID") + "'", con);
                SqlCommand cmd2 = new SqlCommand("select * FROM author", con);

                //Atver savienojumu ar datubāzi
                con.Open();

                SqlDataAdapter adapter = new SqlDataAdapter(cmd);
                SqlDataAdapter adapter1 = new SqlDataAdapter(cmd1);
                SqlDataAdapter adapter2 = new SqlDataAdapter(cmd2);

                //Izveido datatable kolekcijas, kurās tiks ievadīti izvēlētie dati
                DataTable dt = new DataTable();
                DataTable dt1 = new DataTable();
                DataTable dt2 = new DataTable();

                //Aizpilda iepriekš izveidotās kolekcijas
                adapter.Fill(dt);
                adapter1.Fill(dt1);
                adapter2.Fill(dt2);

                //iegūst pēdējo rindu
                DataRow lastRow = dt.Rows[dt.Rows.Count - 1];
                //Aizpilda publisher lauku
                TitlePublisher.Text = lastRow.Field<string>("pub_name");

                //Aizpilda ar Title esošo Authors ID
                foreach (DataRow rin in dt1.Rows)
                {
                    autoru_id.Add(rin.Field<int>("personId"));
                }

                //Pārstaigā autoru_id kolekciju, lai atrastu attiecīgo autoru vārdu un uzvārdu

                foreach (int i in autoru_id)
                {
                    foreach (DataRow rini in dt2.Rows)
                    {
                        if (i == rini.Field<int>("ID")) TitleAuthors.Items.Add((rini.Field<string>("fname")).ToString() + " " + (rini.Field<string>("lname")).ToString());
                    }
                }

                //Izment visus iepriekš izveidotos vaicājumus
                cmd.Dispose();
                cmd1.Dispose();
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
    }
}
