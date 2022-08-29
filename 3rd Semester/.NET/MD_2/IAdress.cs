using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MD_2
{
    //publisks interfeiss ar īpašībām adress, city, country, state, zip un authors(readonly)
    public interface IAdress
    {
        string adress { set; get; }
        string city { set; get; }
        string country { set; get; }
        string state { set; get; }
        string zip { set; get; }
        string fullAdress { get; }
    }
}

/*  6. Izveidot Interfeisu “Adress”
*       •	Ar īpašībām "adress", “city”, “country”, “state”, “zip”. Īpašībam jaizvēlās atbilstoši datu tipi;
*       •	Izveidot tikai lasāmu īpašību “fullAdress”, kas atgriež visu adreses lauku vērtību konkatenāciju;
*/