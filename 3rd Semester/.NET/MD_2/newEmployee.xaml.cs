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
    public partial class Window2 : Window
    {
        public Window2()
        {
            InitializeComponent();

            FormManager.ComboBoxPublishers.Clear(); //Notīra visus combobox items, lai izvairītos no dublēšanas
            FormManager.ComboBoxPublishers.Insert(0, new Publisher("-New Publisher-")); //Pievieno default izvēli, kuru izvēloties būs iespējams pievienot jaunu publisher
            foreach (Publisher pub in FormManager.publishers)           //Aizpilda kolekciju ar visiem esošajiem publisher
            {
                FormManager.ComboBoxPublishers.Add(pub);
            }
            //Aizpilda combobox izmantojot data binding
            Publishers.ItemsSource = FormManager.ComboBoxPublishers;
        }

        //Metode NewWmp_Clisk, kura izveido jaunu employee un saglabā tajā datus
        private void NewEmp_Click(object sender, RoutedEventArgs e)
        {
            int errorCnt = 0;
            string errorMsg = "Cannot create Employee: \n Error List: \n";

            if (EmpName.Text == "") { errorCnt++; errorMsg += "  - Employee Name is required \n"; };
            if (EmpSurname.Text == "") { errorCnt++; errorMsg += "  - Employee Surname is required \n"; };
            if (EmpHireDate.SelectedDate.ToString() == "") { errorCnt++; errorMsg += "  - Employee Hire Date is required \n"; };
            if (Publishers.SelectedItem == null) { errorCnt++; errorMsg += "  - Employee Publisher should be selected \n"; };

            if(errorCnt > 0)
            {
                MessageBox.Show(errorMsg);
                return;
            }
            else
            {
                string name = EmpName.Text;
                string surname = EmpSurname.Text;
                DateTime date = (DateTime)EmpHireDate.SelectedDate;
                Publisher t = (Publisher)Publishers.SelectedItem;
                

                //Izveido jaunu employee
                Employee i = new Employee(name, surname, date, t);
                //Pieveino jauno employee globālajai kolekcijai
                FormManager.employees.Add(i);

                //Aizver logu
                this.Close();
                //Paziņo, ka ir izveidots jauns Employee
                MessageBox.Show("Pievienots jauns Employee!");
            }
          
            
        }

        //Metode AddPublisher_Click, kura izveido jaunu Publisher, ja tiek izvēlēts 0-tais elements ("-New Publihser"-)

        private void Publishers_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (Publishers.SelectedIndex == 0)
            {

                var n = new Window3();
                n.Show();
                n.Closed += (s, EventArgs) => 
                { 
                    Publishers.Items.Refresh();
                };
                Publishers.SelectedIndex = FormManager.ComboBoxPublishers.Count;
            }
            else return;
        }
    }
}
