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
    /// Interaction logic for Window6.xaml
    /// </summary>
    public partial class Window6 : Window
    {
        public Window6()
        {
            InitializeComponent();
            //Aizpilda laukus ar jau esošajām vērtībām   
            editPublisher.Text = FormManager.publishers[FormManager.i].name;
            
        }

        //Metode SaveChanges_Click, kura saglabā veiktās izmaiņas
        private void SaveChanges_Click(object sender, RoutedEventArgs e)
        {
            
            if (editPublisher.Text == "") { MessageBox.Show("Please input a Publisher"); return; }
            //saglabā izmaiņas
            FormManager.publishers[FormManager.i].name = editPublisher.Text;
            //aizver logu
            this.Close();
            //Paziņo, ka izmaiņas ir veiktas
            MessageBox.Show("Publisher has been updated!");
        }
    }
}
