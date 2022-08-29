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
    
    public partial class Window3 : Window
    {
        public Window3()
        {
            InitializeComponent();
        }

        //Pārbauda vai ir korekti ievadīti dati
        //Atsauce uz lekcijā izveidoto piemēru
        private void Add_Publisher_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                if (PubName.Text == "") { MessageBox.Show("Please input a Publisher"); return; }
                string name = PubName.Text;
                Publisher t = new Publisher(name);
                FormManager.publishers.Add(t);
                FormManager.ComboBoxPublishers.Add(t);
                
            }
            catch (ArgumentOutOfRangeException aoofrex)
            {
                MessageBox.Show("Nekorekti ieejas dati: " + aoofrex.Message);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

            
            this.Close(); //Aizver logu
            MessageBox.Show("Pievienots jauns Publisher!"); //Tiek paziņots, ka ir izveidots jauns publisher
        }
    }
}
