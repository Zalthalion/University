// AuPLa0401.cpp
/*********************************************************************
Juris Freidenfelds jf18017
AuPLa0401. Sast�d�t C++ programmu, kas dotam natur�lam skaitlim
nosaka vieninieku skaitu pierakst� desmitnieku skait��anas sist�m�.
Risin�juma ieg��anai sast�d�t funkciju, kura natur�lam skaitlim nosaka
vieninieku skaitu pierakst� desmitnieku skait��anas sist�m�.
Programma izveidota: 28.09.2018.
**********************************************************************/
#include<iostream>
#include "lvfriendly.h"
using namespace std;
int cikVieninieku (int n){          //izveido funkciju, kas nosaka cik skaitl� ir vieninieku

    int vsk, sk, cip;
 vsk=0; sk=n;
       do
       {
           cip=sk%10;               // Ieg�st p�d�jo ciparu
           if(cip==1)vsk++;
           sk/=10;                  // At��e� no sk p�d�jo ciparu
       }while(sk>0);

       return vsk;                  //izdod rezult�tu

}

int main()
{

    int n;
    int ok;

    cout << "Nosaka, cik vieninieku atrodas ievad�taj� skaitl�. " << endl;
    cout << endl;
    do
    {
       do
        {
        cout << "Ievadiet natur�lu skaitli, liel�ku vai vien�du ar 0: ";
        cin >> n;
        }while(n<0);
        int rez;
        rez = cikVieninieku(n);
        cout << rez << endl;
        cout << endl;

        cout << " Vai turpin�t (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}
/**************** Testu pl�ns ***************
Ievad�tie dati              V�lamais rezult�ts
11111                               5
12145                               2
2548658                             0
********************************************/
