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
#include "lvfriendly.h"
using namespace std;

struct elem {
    int value;
    elem *next;
};

//Void funkcija "pievieno", kura izveido jaunu elementu un ievada taj� inform�ciju
void pievieno(int sk, elem* &start, elem* &last)
{
    elem *p = new elem;
    p->value=sk;
    p->next=NULL;
    if(start==NULL) start=p;
    else last->next=p;
    last=p;
}

//Void funkcija "druka", kura izdruk� sarakstu
void druka(elem *start)
{
    while (start!=NULL)
    {
        cout<<start->value<<" ";
        start=start->next;
    }
    cout << endl;
}

///Void funkcija frontIfNotInList, kura pievieno saraksta s�kum� skaitli, ja tas nav sastopams sarakst�
void frontIfNotInList(int papElem, elem* &start)
{
    elem *dummyStart = start;           //Papildus nor�de, lai nepazaud�tu s�kuma elementu
    elem *p = new elem;                 //Izveido jaunu elementu ar nor�di p
    bool isInList = false;              //Bool main�gais, lai zin�tu, vai elements ir sastopams sarakst�
    while (start!=NULL)                 //While cikls, kur� p�rstaig� sarakstu un p�rbauda vai taj� ir sastopams lietot�ja ievad�tais skaitlis
    {
        if(papElem==start->value)
        {
            isInList = true;
            break;

        }
        start = start->next;
    }
    if(isInList == false)
    {
        p->value = papElem;             //Jaunaj� element� ievieto, lietot�ja ievad�to skaitli
        p->next = dummyStart;           //Piekabina jauno elementu saraksta s�kum�
        start = p;                      //Nor�di "Start" novieto uz jauno elementu (jaunais elements ir saraksta s�kum�)
        return;
    }else start = dummyStart;
    return;

}
//Void funkcija "izdzes", kura ievad�to saraktu izdz��
void izdzes(elem* &start)
{
    while (start!=NULL)
    {
        start = start->next;
        delete start;
    }
}

int main(){

    int sk;             //Lieto�ja ievad�tais skaitlis, kuru pievienos sarakstam
    int elemSk;         //Elementu daudzums
    int papElem;        //Elements, kuru lietot�js grib pievienot sarakstam
    int ok;             //Papildus main�gais, kur� tiek izmantots programmas atk�rtotai izmanto�anai

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

        //S�kuma nor�de ir NULL, jo v�l nav ievad�ts neviens saraksta elements
        elem *start=NULL;
        //Nor�de uz p�d�jo saraksta elementu, lai atvieglotu saraksta papildin��anu
        elem *last=NULL;

        //For cikls, kur� aizpilda sarakstu ar lietot�ja ievad�tajiem skait�iem
        for(int i=0;i<elemSk;i++)
        {
            cout << "ievadi " << i+1 <<". elementu: ";
            cin >> sk;
            pievieno(sk, start, last);                   //Pievieno sarakstam lietot�ja ievad�to skaitli
        }
        cout << endl;

    do
    {
        cout << "Ievad�tais saraksts: ";
        druka(start);                                    //Izdruk� ievad�to sarakstu

        cout << "Ievadi skaitli, kuru pievienot sarakstam"<<endl;
        cout << "(skaitlis tiks pievienots sarakstam, ja tas nav sastopams sarakst�)"<<endl;
        cin >> papElem;

        frontIfNotInList(papElem, start);                //Pievieno elementu saraksta s�kum�, ja tas nav sastopams sarakst�

        cout << "Atjaunots saraksts: ";
        druka(start);                                    //Izdruk� apgriezto sarakstu
        cout << "Vai v�laties programmu izmantot v�lreiz? (J�=1 un n�=0)"<< endl;
        cin >> ok;
    }while(ok==1);

        izdzes(start);                      //Izdz�� sarakstu
        return 0;
}
/******************************************Testu pl�ns****************************************
Elementu skaits     Ievad�tie elementi      Ievad�tais papildus elements    V�lamais rezult�ts
    1                       5                           1                       1 5
    0                       -                           -                   Saraksta elementu skaitam ir j�b�t liel�kam par 0!
    7               1 3 3 7 8 2 5                       9                   9 1 3 3 7 8 2 5
    4                   4 2 0 9                         0                   4 2 0 9
*********************************************************************************************/

