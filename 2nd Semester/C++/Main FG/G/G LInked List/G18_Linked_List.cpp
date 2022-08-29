/******************************************************************
G18. Uzrakst�t funkciju, kas sal�dzina vai divi saraksti ir vien�di
******************************************************************/
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

void isEqual(elem *start1, elem *start2)
{
    elem *p1 = start1;          //Novieto nor�di uz pirmo elementu
    elem *p2 = start2;

    while(1)
    {
        if(p1->value != p2->value)
        {
            cout << "Saraksti nav vien�di" <<endl;

            return;
        }
        p1=p1->next;
        p2=p2->next;
        if(p1->next==NULL && p2->next==NULL)
        {
            cout << "Saraksts ir vien�ds" << endl;
            return;
        }
    }
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

        //S�kuma nor�de ir NULL, jo v�l nav ievad�ts neviens pirm� saraksta elements
        elem *start1=NULL;
        //Nor�de uz p�d�jo saraksta elementu, lai atvieglotu pirm� saraksta papildin��anu
        elem *last1=NULL;

        //S�kuma nor�de ir NULL, jo v�l nav ievad�ts neviens otr� saraksta elements
        elem *start2=NULL;
        //Nor�de uz p�d�jo saraksta elementu, lai atvieglotu otr� saraksta papildin��anu
        elem *last2=NULL;


        //For cikls, kur� aizpilda pirmo sarakstu ar lietot�ja ievad�tajiem skait�iem
        cout << "Aizpildi pirmo sarakstu!" << endl;
        for(int i=0;i<elemSk;i++)
        {
            cout << "ievadi " << i+1 <<". elementu: ";
            cin >> sk;
            pievieno(sk, start1, last1);                   //Pievieno sarakstam lietot�ja ievad�to skaitli
        }
        cout << endl;

        //For cikls, kur� aizpilda pirmo sarakstu ar lietot�ja ievad�tajiem skait�iem
        cout << "Aizpildi otro sarakstu!" << endl;
        for(int i=0;i<elemSk;i++)
        {
            cout << "ievadi " << i+1 <<". elementu: ";
            cin >> sk;
            pievieno(sk, start2, last2);                   //Pievieno sarakstam lietot�ja ievad�to skaitli
        }
        cout << endl;

        cout << "Ievad�tais saraksts: ";
        druka(start1);                                    //Izdruk� ievad�to sarakstu
        druka(start2);                                    //izdruk� otru sarakstu

        isEqual(start1, start2);
//
//        cout << "Atjaunots saraksts: ";
//        druka(start1);                                    //Izdruk� apgriezto sarakstu
        izdzes(start1);                      //Izdz�� sarakstu
        izdzes(start2);
        cout << "Vai v�laties programmu izmantot v�lreiz? (J�=1 un n�=0)"<< endl;
        cin >> ok;

    }while(ok==1);


        return 0;
}
/***************************************Testu pl�ns**************************************
    Elemetnu skaits     Pirmais saraksts        Otrais saraksts        V�lamais rezult�ts
          6             1 2 3 4 5 6             1 2 3 4 5 6 6           Saraksti ir vien�di
          0                     -                       -               Sarakstam ir j�b�t vismaz 1 elementu garam
          1                     5                       5               Saraksti ir vien�di
          4             1 3 3 7                     3 1 7 3             Saraksti nav vien�di
****************************************************************************************/

