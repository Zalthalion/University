using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MD_1
{
    [Serializable()] //Atzīmē klasi kā serializējamu - Lekciju materiāli: 4. lekcija - sintakse

    //Person apakšklase author, kura implementē interfeisu IAdress (Pievienojum "I" interfeisa nosaukuma sākumā, lai to varētu vieglāk atšķirt no klases)
    public class Author : Person, IAdress
    {
        //Visi atribūti privāti
        private string Adress;
        private string City;
        private string Country;
        private string State;
        private string Zip;
        public Author() { } //Noklusējuma konstruktors

        // Konstruktors, kurš pieprasa visas klasei nepieciešamas vērtības
        public Author(string _name, string _surname, string _adress, string _city, string _country, string _state, string _zip)
        {
            name = _name;
            surname = _surname;
            Adress = _adress;
            City = _city;
            Country = _country;
            State = _state;
            Zip = _zip;
        }

        //Kaudze ar noklusējuma get un set, jo interfeiss to pieprasa
        public string adress { set { Adress = value; } get { return Adress; } }
        public string city { set { City = value; } get { return City; } }
        public string country { set { Country = value; } get { return Country; } }
        public string state { set { State = value; } get { return State; } }
        public string zip { set { Zip = value; } get { return Zip; } }

        //Tikai lasāma īpašība fullAdress, kas atgriež visu vērtību konkatenāciju
        public string fullAdress { get { return string.Format(Adress + " " + City + " " + Country + " " + State + " " + Zip); } }

        //Metode asText, kura izveido visas klases konkatenāciju
        public override string asText()
        {
            return name + " " + surname + " " + Adress + " " + City + " " + Country + " " + state + " " + zip.ToString();
        }
    }
}
/* 2. Izveidot klasei „Person” apakšklasi „Author”:
*       •	Implementēt interfeisu “Adress”
*       •	Pārdefinēt metodi: asText, lai tiktu atgrieztas visu šīs klases īpašību vērtības.
*/