using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MD_1
{
    [Serializable()] //Atzīmē klasi kā serializējamu - Lekciju materiāli: 4. lekcija - sintakse

    //Klase Title ar īpašībām:titleType, name, pubDate, publisher, authors un metodēm: asText();
    public class Title
    {
        //privāti atribūti
        private string Name;
        private DateTime PubDate;
        private Publisher Publisher;
        private Author[] Authors;

        public TitleType titleType;
        
        //Noklusējuma get un set
        public string name { set { Name = value; } get { return Name; } }

        public DateTime pubDate { set { PubDate = value; } get { return PubDate; } }

        public Publisher publisher { set { Publisher = value; } get { return Publisher; } }

        public Author[] authors { get { return Authors; } set { Authors = value; } }

        public Title() { } //Default konstruktors

        //Title konstruktors ar parametriem
        public Title(string _name, DateTime _pubDate, Publisher _publisher, Author[] _authors, TitleType _titletype)
        {
            Name = _name;
            PubDate = _pubDate;
            Publisher = _publisher;
            Authors = _authors;
            titleType = _titletype;
        }

        //Funkcija asText, kura izveido visas klases konkatenāciju
        public string asText()
        {
            return Name + " " + PubDate.ToString("MM/dd/yyyy") + " " + Publisher.name.ToString() + " " + titleType;
        }
    }
}

/*  4. Izveidot klasi "Title" ar
*       •	Īpašību "name" teksts;
*       •	Īpašība “pubDate” – publicēšanas datums;
*       •	Īpasību "titleType" – pārskaitāmais tips ar vērtībām: business, psychology, mod_cook, trad_cook, popular_comp, UNDECICED;
*       •	Īpašību “publisher” ar tipu klase Publisher;
*       •	Īpašību “authors”, kas ir saraksts(vai masīvs) ar klases Author instancēm;
*       •	Klasei izveidot 2 konstruktorus, no kuriem viens kā parametru saņem visu īpašību vērtības, kas arī tiek uzstādītas jaunajam objektam.
*/