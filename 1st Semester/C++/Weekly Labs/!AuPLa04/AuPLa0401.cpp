// AuPLa0401.cpp
/*********************************************************************
Juris Freidenfelds jf18017
AuPLa0401. Sastâdît C++ programmu, kas dotam naturâlam skaitlim
nosaka vieninieku skaitu pierakstâ desmitnieku skaitîðanas sistçmâ.
Risinâjuma iegûðanai sastâdît funkciju, kura naturâlam skaitlim nosaka
vieninieku skaitu pierakstâ desmitnieku skaitîðanas sistçmâ.
Programma izveidota: 28.09.2018.
**********************************************************************/
#include<iostream>
#include "lvfriendly.h"
using namespace std;
int cikVieninieku (int n){          //izveido funkciju, kas nosaka cik skaitlî ir vieninieku

    int vsk, sk, cip;
 vsk=0; sk=n;
       do
       {
           cip=sk%10;               // Iegûst pçdçjo ciparu
           if(cip==1)vsk++;
           sk/=10;                  // Atðíeï no sk pçdçjo ciparu
       }while(sk>0);

       return vsk;                  //izdod rezultâtu

}

int main()
{

    int n;
    int ok;

    cout << "Nosaka, cik vieninieku atrodas ievadîtajâ skaitlî. " << endl;
    cout << endl;
    do
    {
       do
        {
        cout << "Ievadiet naturâlu skaitli, lielâku vai vienâdu ar 0: ";
        cin >> n;
        }while(n<0);
        int rez;
        rez = cikVieninieku(n);
        cout << rez << endl;
        cout << endl;

        cout << " Vai turpinât (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}
/**************** Testu plâns ***************
Ievadîtie dati              Vçlamais rezultâts
11111                               5
12145                               2
2548658                             0
********************************************/
