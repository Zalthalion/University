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
    
    public partial class Window5 : Window
    {
        //Izvēlētā Employee indeks, lai man būtu ērtāk izmantot tā vērtības
        
        public Window5()
        {
            int indeks = FormManager.i;
            InitializeComponent();
            FormManager.ComboBoxPublishers.Clear();
            FormManager.ComboBoxPublishers.Insert(0, new Publisher("-New Publisher-"));
            foreach (Publisher pub in FormManager.publishers)
            {
                FormManager.ComboBoxPublishers.Add(pub);
            }
            //Aizpilda combobox izmantojot data binding
            Publishers.ItemsSource = FormManager.ComboBoxPublishers;
            //Aizpilda visus laukus ar jau esošajām vērībām
            EmpName.Text = FormManager.employees[indeks].name;
            EmpSurname.Text = FormManager.employees[indeks].surname;
            EmpHireDate.SelectedDate = FormManager.employees[indeks].hireDate;
            Publishers.SelectedItem = FormManager.employees[indeks].publisher;
           
        }

        private void SaveEmployee_Click(object sender, RoutedEventArgs e)
        {
            int indeks = FormManager.i;
            int errorCnt = 0; //kļūdu skaitītājs
            string errorMsg = "Can't update Employee!\n Error list:\n"; //default error message

            //Pārbauda vai kāds lauks nav atstāts tukš, ja ir, tad tiek pievienots kļudas paziņojumam attiecīgais teksts
            if (EmpName.Text == "") { errorCnt++; errorMsg += "  - Employee Name is required\n"; };
            if (EmpSurname.Text == "") { errorCnt++; errorMsg += "  - Employee Surname is required\n"; };
            if (EmpHireDate.SelectedDate.ToString() == "") { errorCnt++; errorMsg += "  - Employee Hire Date is required\n"; };
            if (Publishers.SelectedItem == null) { errorCnt++; errorMsg += "  - Employee Publisher is required"; };
            if (errorCnt > 0)
            {
                MessageBox.Show(errorMsg);
                return;
            }
            else
            {
          
                //Saglabā jaunās vērtības
                FormManager.employees[indeks].publisher = (Publisher)Publishers.SelectedItem;
                FormManager.employees[indeks].name = EmpName.Text;
                FormManager.employees[indeks].surname = EmpSurname.Text;
                FormManager.employees[indeks].hireDate = (DateTime)EmpHireDate.SelectedDate;
                

                //Paziņo, ka ir izmainīti dati
                MessageBox.Show("Employee has been updated!");
                //Aizver logu
                this.Close();
            }
        }
            
            
        
        //Izsauc New Publisher logu, ja tiek izvēlēts 0-tais elements (-"New Publisher"-)
        private void Publishers_SelectionChanged_1(object sender, SelectionChangedEventArgs e)
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
