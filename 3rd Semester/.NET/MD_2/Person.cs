using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MD_2
{
        [Serializable()] //Atzīmē klasi kā serializējamu - Lekciju materiāli: 4. lekcija - sintakse
        public abstract class Person
        {
            //Privāti atribūti - personas vārds un uzvārds
            private string Name;
            private string Surname;

            //Konstruktors, kuram padod parametrus _Name un _Surename, kuri pēc tam
            //tiek piešķirti atribūtiem Name un Surname 
            public Person(string _Name, string _Surname)
            {
                Name = _Name;
                Surname = _Surname;
            }
            public Person() { } //Noklusējuma konstruktors

            //Iepriekšējā vērtība tiek uzskatīta kā tukšs string
            //Publiska īpašība "name", kura atgriež iepriekšējo vērtību, ja padotais parametrs ir tukšs
            public string name
            {
                set
                {
                    if (string.IsNullOrEmpty(value) == true)
                    { Name = ""; }
                    else Name = value;
                }
                get { return Name; }
            }

            //Publiska īpašība "surname", kura atgriež iepriekšējo vērību, ja padotas parametrs ir tukšs
            public string surname
            {
                set
                {
                    if (string.IsNullOrEmpty(value) == true)
                    { Surname = ""; }
                    else Surname = value;
                }
                get { return Surname; }
            }

            //readonly īpašība "fullName", kura atgriež vārda un uzvārda konkatenāciju
            public string fullName { get { return string.Format(Name + " " + Surname); } }

            //virtuālā metode "asText", kura atgriež visas klasē deklarētās vērtības
            public virtual string asText() { return Name + " " + Surname; }

        }
    
}


/*   1. Izveidot abstraktu klasi „Person”:
*       •	Privātiem atribūtiem un publiskām īpašībām „name” un „surname”
*       •	Uzstādot īpašības „name” vērtību, jāpārbauda vai jaunā vērtība ir tukša un, ja ir, tad jāatstāj iepriekšējā vērtība.
*       •	Tikai lasāmu īpašību „fullName”, kas atgriež vārda un uzvārda konkatenāciju ar vienu atstarpi pa vidu.
*       •	Izveidot virtuālu metodi: asText(), kas atgriež visu īpašību vērtības kā tekstu. Drīkst šī vietā pārdefinēt ToString metodi
*/
