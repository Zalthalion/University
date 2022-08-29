/***********************************************
Juris Freidenfelds jf18017
Izveidot programmu C++. Ievadot loìiski nepareizus
datus, programmai jâizdod atbilstoðs paziòojums. Jâbût iespçjai
programmu izpildît atkârtoti. Atrâdot programmu, jâatrâda
   a) programmas teksts,
   b) testa piemçri,
   c) programma darbîbâ.
Precîzâkas prasîbas sk. Laboratorijas darbu noteikumos.
A1. Izdrukât aritmçtiskâs progresijas pirmos n locekïus, ja dots a(1)
(pirmais loceklis) un d (diference).
Programma izveidota 24.09.2018
***********************************************/
#include<iostream>
#include "lvfriendly.h"
#include<cmath>
using namespace std;
int main()
{
    cout << "Programma, kura izdrukâ aritmçtiskâs progresijas 'n' locekïus " << endl; // Programmas uzdevums
    cout <<endl;
    int ok;
    do          // Nodroðina iespçju programmu izmantot atkârtoti to neaizverot
    {
        double d, sk, n;    //deklerç mainîgos kâ reâlus skaitïus
        cout << "Ievadi virknes pirmo locekli: ";
        cin >> sk;          //sk drîkst bût jebkurð skaitlis, jo virkne var sâkties jebkur
        cout << "Ievadi diferenci: ";
        cin >> d;           //d drîkst bût jebkurð skaitlis, jo pieskaitît var jebkuru skaitli
        cout << "Ievadi cik virknes nâkamos locekïus gribi uzzinât: ";
        cin >> n;           //n drîkst bût tikai vesels skaitlis, jo virknes loceklis ir kâ cilvçks.
        cout << endl;
        if (n>0 && floor(n) == ceil(n)) //pârbauda vai n ir lielâks par 0 un vai tas ir vesels skaitlis
            {
            for ( int a = 0; a<n; a++){ //ja pârbaude ir patiesa tad var iedarbinât ciklu
            sk=sk+d;
            cout << sk << endl;
        }}
        else
        {
        do {        //ja pârbaude nav patiesa tad iedarbinâs cikls

            cout << "Ievadi lûdzu POZITÎU, VESELU skaitli!" << endl; //kurâ tiek izmests paziòojums par nepareizu datu ievadi
            cout << "Programma risina tikai nâkamos veselos virknes locekïus" << endl;
            cout << "nevis daïçjus vai iepriekðçjos" << endl;
            cout << endl;
            cout << "Ievadi cik virknes nâkamos locekïus gribi uzzinât: "; // un liek ievadît pareizus datus
            cin >> n;
        } while (floor(n) > ceil(n) || floor(n) < ceil(n) || n<=0); //lîdz brîdim kamçr dati ir ievadîti pareizi
            cout << endl;
        for ( int a = 0; a<n; a++){ //ja dati ir ievadîti pareizi tad tiek iedarbinâts cikls kurð rçíina aritmçtisko progressiju

            sk=sk+d;
            cout << sk << endl;
        }}
        cout << endl;
        cout << " Vai turpinât (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}


/******************* Testu plans ************************
Ievadîtie dati                    Gaidâmais rezultâts
Sk      d       n
-8      0       0                   "Ievadi pozitîvu n!"
5       -5      7                   0;-5;-10;-15;-20;-25;-30
0       8       -8                  "Ievadi pozitîvu n!"
1.7     5       5                   6.7;11.7;16.7;21.7;26.7
5       0       7                   5;5;5;5;5;5;5
-3      2       3                   -1;1;3
-5      2.8     2                   -2.2;0.6
********************************************************/
