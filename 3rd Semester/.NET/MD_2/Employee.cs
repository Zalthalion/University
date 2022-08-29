using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MD_2
{
    [Serializable()] //Atzīmē klasi kā serializējamu - Lekciju materiāli: 4. lekcija - sintakse    //Person sub-klase Employee

    //Klases Person apakšklase - Employee ar īpašībām hireDate, publisher un metodi asText();
    public class Employee : Person
    {
        //Privāti atribūti
        private DateTime HireDate;
        private Publisher Publisher;

        public Employee() { } //Default konstruktors

        //Konstruktors, kurš aizpilda visus klases atribūtus
        public Employee(string _name, string _surname, DateTime _date, Publisher _publisher)
        {
            name = _name;
            surname = _surname;
            HireDate = _date;
            Publisher = _publisher;
        }
        
        //Default set un get metodēm hireDate un publisher
        public DateTime hireDate { set { HireDate = value; } get { return HireDate; } }
        public Publisher publisher { set { Publisher = value; } get { return Publisher; } }

        //Metode asText(), kura atgriež visu šīs klases īpāšību vērtības
        public override string ToString()
        {
            return name + " " + surname + " " + HireDate.ToString("dd/MM/yyyy") + " " + Publisher.name.ToString();
        }
    }
}

/*  3. Izveidot klasei „Persona” apakšklasi „Employee”:
*       •	Īpašību „hireDate” ar tipu datums;
*       •	Īpašību “publisher” ar datu tipu Publisher;
*       •	Pārdefinēt metodi: asText(), lai tiktu atgrieztas visu šīs klases īpašību vērtības;
*/
