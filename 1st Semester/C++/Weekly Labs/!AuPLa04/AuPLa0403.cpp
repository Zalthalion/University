// AuPLa0403.cpp
/*******************************************************************
Juris Freidenfelds jf 18017
AuPLa0403. Sast�d�t C++ programmu, kas dotam natur�lam skaitlim
nosaka dota cipara skaitu pierakst� desmitnieku skait��anas sist�m�.
Risin�juma ieg��anai sast�d�t funkciju, kura natur�lam skaitlim
nosaka dota cipara skaitu pierakst� desmitnieku skait��anas sist�m�.
Programma izveidota: 20.09.2018.
********************************************************************/
#include<iostream>
#include "lvfriendly.h"
using namespace std;

int cikCiparu (int n, int c){

    int vsk, sk, cip, a;
 vsk =0; sk = n; cip = c;
       do{
           a=sk % 10; // Ieg�st p�d�jo ciparu
           if (a == c) vsk++; else vsk = vsk+0;
           sk/=10;    // At��e� no sk p�d�jo ciparu
       }while(sk>0);
       return vsk;
}

int main()
{
    int ok;

    cout << "Nosaka, cik vieninieku atrodas ievad�taj� skaitl�. " << endl;
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

        cout << " Vai turpin�t (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}
/**************** Testu pl�ns ***************

********************************************/
