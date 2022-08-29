/****************************************************************************************
Izveidot programmu valod� C++, kas �auj izveidot vienvirziena saist�to sarakstu
(izmantojot dinamisk�s datu strukt�ras),kur� glab�jas noteikta tipa v�rt�bas.
J�b�t  paredz�tai iesp�jai sarakstu papildin�t ar jaunu elementu (pielikt elementu saraksta gal�),
izdruk�t sarakstu, izn�cin�t sarakstu. Bez tam j�uzraksta funkcija, kura aprakst�ta zem�k.
Izn�cinot saraksta elementus, korekti j�atbr�vo izdal�t� atmi�a.
Galvenaj� programm�:
a) j�b�t iesp�jai ievad�t saraksta elementus (izveidot patva��gu sarakstu),
b) j�pielieto uzrakst�t� funkcija sarakstam,
c) j�izdruk� saraksts p�c funkcijas darb�bas.
d) beig�s j�izn�cina saraksts (lietojot delete).
S�k�kas pras�bas sk. Laboratorijas darbu noteikumos.

G3. Uzrakst�t funkciju, kas pieliek sarakstam jaunu elementu saraksta s�kum�, ja elements ar t�du v�rt�bu neeksist�.
****************************************************************************************/
#include <iostream>
#include <list>
#include "lvfriendly.h"
using namespace std;

//Void funkcija frontIfNotInList, kura p�rbauda vai ievad�tais elements ir sastopams sarakst�
//Un ja nav tad pievieno to saraksta s�kum�
void frontIfNotInList(int papElem, list<int>&saraksts)
{
bool sastopams = false; //Bool main�gais, kur� pasaka vai sarakst� ir sastopams papiElem;

        //For cikls, kur� p�rstaig� saraksta elementus un p�rbauda vai taj� atrodas lietot�ja ievad�tais skaitlis
        for (auto i=saraksts.begin(); i!=saraksts.end();i++)
        {
            if(papElem==*i)
            {
                sastopams = true;
                break;
            }
        }
        if(sastopams == false) saraksts.push_front(papElem);
        return;
}

int main()
{
    int elemSk;             //Lietot�ja ievad�tais elementu skaits
    list<int> saraksts;
    int a;
    int papElem;            //Lietot�ja oevad�tais papildus elements;
    int ok;

    //Lietot�js izv�l�s cik elementi b�s sarakst� (Sarakstam ir j�b�t vismaz vienam elementam)
    do
    {
        cout<<"Ievadi, cik daudz saraksta elementus v�lies ievad�t: ";
        cin >> elemSk;
        if(elemSk < 1)
        {
            cout << "Saraksta elementu skaitam ir j�b�t liel�kam par 0!"<< endl;
        }
        cout << endl << endl;
    }while (elemSk<1);


    cout << "Aizpildi sarakstu: " << endl;
    //For cikls ar kuru lietot�js aizpilda sarakstu
    for(int i = 0; i<elemSk; i++)
    {
        cout << "ievadi saraksta " << i+1 <<". elementu: ";
        cin >> a;
        saraksts.push_back(a);
    }

    cout << endl;

    cout<<"Ievad�tais saraksts: ";

    //For cikls, kur� izdruk� sarakstu
    for(auto i=saraksts.begin();i!=saraksts.end();i++)cout<<*i<<" ";

    cout<<endl;
    //Do cikls, kur� at�auj programmu izmantot v�lreiz
    do
    {
        //Lietot�js ievada, kuru elementu grib pievienot sarakstam (ja t�ds jau neeksist� sarakst�)
        cout << "�evadi elementu (ja elements nav sastopams sarakst�, tad to pievienos saraksta s�kum�): ";
        cin >> papElem;

        ///Funkcijas izsauk�ana
        frontIfNotInList(papElem, saraksts);

        cout<<"Atjaunotais saraksts: ";
        for(auto i=saraksts.begin();i!=saraksts.end();i++)cout<<*i<<" ";
            cout<<endl;

            //Lietot�js izv�lais vai atk�rtot programmu (ievad�t elementu v�lreiz)
            cout << "Vai v�laties programmu izmantot v�lreiz? (j�=1 un n�=0)" << endl;
            cin >> ok;
    }while(ok==1);

    //Saraksta dz��ana
    saraksts.erase(saraksts.begin(), saraksts.end());

    return 0;
}

/******************************************Testu pl�ns****************************************
Elementu skaits     Ievad�tie elementi      Ievad�tais papildus elements    V�lamais rezult�ts
    1                       5                           1                       1 5
    0                       -                           -                   Saraksta elementu skaitam ir j�b�t liel�kam par 0!
    7               1 3 3 7 8 2 5                       9                   9 1 3 3 7 8 2 5
    4                   4 2 0 9                         0                   4 2 0 9
*********************************************************************************************/
