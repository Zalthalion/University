using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//jf10819

/*
 * Neliels info par MD. (īsāk sakot, "ko es nepaspēju izdarīt, jo sāku par vēlu")
 * Nav pilnīga metode "createTitles" (bet ir iesākta)
 * print metode izdrukā tikai metodes createPersons izveidotās vērtības
 * Nav vispār iekļauta failu apstrāde (nav metodes saveToFile un readFromFile)
 * Tāpat kā konsoles saskarne nav pilnīga
 */


namespace MD_1
{ 
    //Kaut kāda daļa no konsoles saskarnes
    class Program
    {
        static void Main(string[] args)
        {

            DataManager.createPerosns(); //Izsauc metodi, kura aizpilda objektus ar attiecīgām vērtībām
            DataManager.createTitles(); //Izveidoti tie titles,kas mums nenoraus galvu
            DataManager.saveToFile(); //Saglabā izveidotās vērtības failā
            DataManager.readFromFile(); //Nolasa failā esošās vērtības
            DataManager.print(); //Izsauc metodu, kura izdrukā visas klases vērtības


            Console.ReadLine(); //Stop punkts, lai console neaizveras pārāk ātri
          
        }
    }
}
