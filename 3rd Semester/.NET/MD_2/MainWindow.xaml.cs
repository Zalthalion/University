using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

    


namespace MD_2
{
    
    public partial class MainWindow : Window
    {

        public MainWindow()
        {
            InitializeComponent();
        }



        //Izveido jaunu Author
        private void NewAuthor_Click(object sender, RoutedEventArgs e)
        {
            var w = new Window1();
            w.Show();
        }

        

        //Izveido jaunu Employee
        private void NewEmp_Click(object sender, RoutedEventArgs e)
        {
            var w = new Window2();
            w.Show();
        }

       
  
        //Saglabā izveidotos datus failā
        private void SaveToFile_Click(object sender, RoutedEventArgs e)
        {
            FormManager.saveToFile();
            System.Windows.MessageBox.Show("Data has been saved to a file succsesfully!");
        }

        //Izveido jaunu Publisher
        private void NewPubl_Click(object sender, RoutedEventArgs e)
        {
            var w = new Window3();
            w.Show();
        }

        //Izveido jaunu Title
        private void NewTitle_Click(object sender, RoutedEventArgs e)
        {
            var w = new Window4();
            w.Show();
            w.Closed += (s, EventArgs) => { FormManager.tempAuthors.Clear(); }; //Kad tiek aizvērts logs, tiek notīrītas tempauthors vērtības, lai nedublējas dati
        }

        //Izdzēš Title
        private void DelTitle_Click(object sender, RoutedEventArgs e)
        {
            FormManager.allTitles.Remove((Title)formTitles.SelectedItem);
            System.Windows.MessageBox.Show("Title deleted succesfully!");
        }

        //izdzēš employee
        private void DelEmployee_Click(object sender, RoutedEventArgs e)
        {
            FormManager.employees.Remove((Employee)formEmployees.SelectedItem);
            System.Windows.MessageBox.Show("Employee deleted succesfully!");
        }

        //Izdzēš Author
        private void DelAuthor_Click(object sender, RoutedEventArgs e)
        {
            FormManager.authors.Remove((Author)formAuthors.SelectedItem);
            System.Windows.MessageBox.Show("Author deleted succesfully!");
        }
        
        //Izdzēš Publisher
        private void DelPublisher_Click(object sender, RoutedEventArgs e)
        {
            FormManager.publishers.Remove((Publisher)formPublisher.SelectedItem);
            System.Windows.MessageBox.Show("Publisher deleted succesfully!");
        }

        //Metode EditButton_Click , kura labo Publisher
        private void EditButton_Click(object sender, RoutedEventArgs e)
        {
            //Pārbauda vai ir izvēlēts kāds Publisher
            if (formPublisher.SelectedItem == null) { System.Windows.MessageBox.Show("You must select a Publisher"); return; }
            
            //Saglabā izvēlētā Publisher indeksu
            FormManager.i = formPublisher.SelectedIndex;
            //Atver labošanas logu
            var editWindow = new Window6();
            editWindow.Show();
            //Kas labošanas logs tiek aizvērts, tiek atjaunināts formPublisher listbox
            editWindow.Closed += (s, EventArgs) => { formPublisher.Items.Refresh(); };

        }

        //Labo Employee
        private void EditEmployee_Click(object sender, RoutedEventArgs e)
        {
            //Pārbauda vai ir izvēlēts kāds Employee
            if (formEmployees.SelectedItem == null) { System.Windows.MessageBox.Show("You must select an Employee"); return; }
            //Tiek saglabāts izvēlētā Employee indekss
            FormManager.i = formEmployees.SelectedIndex;
            //Tiek atvērts labošanas logs
            var editWindow = new Window5();
            editWindow.Show();
            //Kad logs tiek aizvērts, tiek atjaunināts formEmployees listbox
            editWindow.Closed += (s, EventArgs) => { formEmployees.Items.Refresh(); };
        }

        //Labo Author
        private void EditAuthor_Click(object sender, RoutedEventArgs e)
        {
            //Pārbauda vai ir izvēlēts kāds Author
            if (formAuthors.SelectedItem == null) { System.Windows.MessageBox.Show("You must select a Author"); return; }
            //Tiek saglabāts izvēlētā Author indekss
            FormManager.i = formAuthors.SelectedIndex;
            var editWindow = new Window7();
            //Atver labošanas logs
            editWindow.Show();
            //Kad logs tiek aizvērts labošanas logs, tiek atjaunināts formAuthors listbox
            editWindow.Closed += (s, EventArgs) => { formAuthors.Items.Refresh(); };
        }

        //Labo Title
        private void EditTitle_Click(object sender, RoutedEventArgs e)
        {
            //Pārbauda vai ir izvēlēts kāds Title
            if (formTitles.SelectedItem == null) { System.Windows.MessageBox.Show("You must select a Title"); return; }
            //Tiek saglabāts izvēlētā Title indekss
            FormManager.i = formTitles.SelectedIndex;
            var editWindow = new Window8();
            //Atver labošanas logu
            editWindow.Show();
            //Kad labošanas logs tiek aizvērts, tiek atjaunināts formTitles listbox
            editWindow.Closed += (s, EventArgs) => { formTitles.Items.Refresh(); };
            
        }
        
        //Nolasa failā izveidotos datus
        private void ReadFromFile_Click(object sender, RoutedEventArgs e)
        {
            //Izsauc pirmajā mājasdarbā izveidoto readFromFile
            FormManager.readFromFile();
            formTitles.ItemsSource = FormManager.allTitles;
            formAuthors.ItemsSource = FormManager.authors;
            formPublisher.ItemsSource = FormManager.publishers;
            formEmployees.ItemsSource = FormManager.employees;
        }

        //Izveido testa datus
        private void CreateTestData_Click(object sender, RoutedEventArgs e)
        {
            FormManager.createTestData();

            formTitles.ItemsSource = FormManager.allTitles;
            formAuthors.ItemsSource = FormManager.authors;
            formPublisher.ItemsSource = FormManager.publishers;
            formEmployees.ItemsSource = FormManager.employees;

            System.Windows.MessageBox.Show("Test data has been created!");

        }
    }

}






