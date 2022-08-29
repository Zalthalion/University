// AuPLa0403.cpp
/*******************************************************************
Juris Freidenfelds jf 18017
AuPLa0403. Sastâdît C++ programmu, kas dotam naturâlam skaitlim
nosaka dota cipara skaitu pierakstâ desmitnieku skaitîðanas sistçmâ.
Risinâjuma iegûðanai sastâdît funkciju, kura naturâlam skaitlim
nosaka dota cipara skaitu pierakstâ desmitnieku skaitîðanas sistçmâ.
Programma izveidota: 20.09.2018.
********************************************************************/
#include<iostream>
#include "lvfriendly.h"
using namespace std;

int cikCiparu (int n, int c){

    int vsk, sk, cip, a;
 vsk =0; sk = n; cip = c;
       do{
           a=sk % 10; // Iegûst pçdçjo ciparu
           if (a == c) vsk++; else vsk = vsk+0;
           sk/=10;    // Atðíeï no sk pçdçjo ciparu
       }while(sk>0);
       return vsk;
}

int main()
{
    int ok;

    cout << "Nosaka, cik vieninieku atrodas ievadîtajâ skaitlî. " << endl;
    cout << endl;
    do
    {
int sk, cip;
       do
        {
        cout << "Ievadiet  skaitli ";
        cin >> sk;
        }while(sk<0);
        do{
        cout << "Ievadiet ciparu: ";
        cin >> cip;
        }while(cip<0);
        int rez;
        rez = cikCiparu(sk, cip);
        cout << rez << endl;
        cout << endl;

        cout << " Vai turpinât (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}
/**************** Testu plâns ***************

********************************************/
