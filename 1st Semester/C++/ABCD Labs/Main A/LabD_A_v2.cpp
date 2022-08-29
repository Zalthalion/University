/***********************************************
Juris Freidenfelds jf18017
Izveidot programmu C++. Ievadot lo�iski nepareizus
datus, programmai j�izdod atbilsto�s pazi�ojums. J�b�t iesp�jai
programmu izpild�t atk�rtoti. Atr�dot programmu, j�atr�da
   a) programmas teksts,
   b) testa piem�ri,
   c) programma darb�b�.
Prec�z�kas pras�bas sk. Laboratorijas darbu noteikumos.
A1. Izdruk�t aritm�tisk�s progresijas pirmos n locek�us, ja dots a(1)
(pirmais loceklis) un d (diference).
Programma izveidota 24.09.2018
***********************************************/
#include<iostream>
#include "lvfriendly.h"
#include<cmath>
using namespace std;
int main()
{
    cout << "Programma, kura izdruk� aritm�tisk�s progresijas 'n' locek�us " << endl; // Programmas uzdevums
    cout <<endl;
    int ok;
    do          // Nodro�ina iesp�ju programmu izmantot atk�rtoti to neaizverot
    {
        double d, sk, n;    //dekler� main�gos k� re�lus skait�us
        cout << "Ievadi virknes pirmo locekli: ";
        cin >> sk;          //sk dr�kst b�t jebkur� skaitlis, jo virkne var s�kties jebkur
        cout << "Ievadi diferenci: ";
        cin >> d;           //d dr�kst b�t jebkur� skaitlis, jo pieskait�t var jebkuru skaitli
        cout << "Ievadi cik virknes n�kamos locek�us gribi uzzin�t: ";
        cin >> n;           //n dr�kst b�t tikai vesels skaitlis, jo virknes loceklis ir k� cilv�ks.
        cout << endl;
        if (n>0 && floor(n) == ceil(n)) //p�rbauda vai n ir liel�ks par 0 un vai tas ir vesels skaitlis
            {
            for ( int a = 0; a<n; a++){ //ja p�rbaude ir patiesa tad var iedarbin�t ciklu
            sk=sk+d;
            cout << sk << endl;
        }}
        else
        {
        do {        //ja p�rbaude nav patiesa tad iedarbin�s cikls

            cout << "Ievadi l�dzu POZIT�U, VESELU skaitli!" << endl; //kur� tiek izmests pazi�ojums par nepareizu datu ievadi
            cout << "Programma risina tikai n�kamos veselos virknes locek�us" << endl;
            cout << "nevis da��jus vai iepriek��jos" << endl;
            cout << endl;
            cout << "Ievadi cik virknes n�kamos locek�us gribi uzzin�t: "; // un liek ievad�t pareizus datus
            cin >> n;
        } while (floor(n) > ceil(n) || floor(n) < ceil(n) || n<=0); //l�dz br�dim kam�r dati ir ievad�ti pareizi
            cout << endl;
        for ( int a = 0; a<n; a++){ //ja dati ir ievad�ti pareizi tad tiek iedarbin�ts cikls kur� r��ina aritm�tisko progressiju

            sk=sk+d;
            cout << sk << endl;
        }}
        cout << endl;
        cout << " Vai turpin�t (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}


/******************* Testu plans ************************
Ievad�tie dati                    Gaid�mais rezult�ts
Sk      d       n
-8      0       0                   "Ievadi pozit�vu n!"
5       -5      7                   0;-5;-10;-15;-20;-25;-30
0       8       -8                  "Ievadi pozit�vu n!"
1.7     5       5                   6.7;11.7;16.7;21.7;26.7
5       0       7                   5;5;5;5;5;5;5
-3      2       3                   -1;1;3
-5      2.8     2                   -2.2;0.6
********************************************************/
