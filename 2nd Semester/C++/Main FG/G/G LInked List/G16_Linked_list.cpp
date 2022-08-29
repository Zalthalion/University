/******************************************************************
G16. Uzrakst�t funkciju, kas no diviem sarakstiem izveido tre�o t�, lai 3. s
arakst� b�tu visas v�rt�bas no 1. un 2. saraksta un izveidotaj� sarakst�
neb�tu elementu ar vien�d�m v�rt�b�m.
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

void isEqual(elem *start, elem *start1, elem *start2, elem *last1, elem *last2)
{
    elem *p1 = start1;          //Novieto nor�di uz pirmo elementu
    elem *p2 = start2;
    elem *it = start1;
    elem *p = start;
    bool vaiIr = false;
    elem *last = NULL;
    pievieno(p1->value, start,last);
    it = it->next;
    p1 = p1->next;
    if (it->value !=p1->value)pievieno(it->value,start,last);
    it = it->next;

    while(1)

    {
        cout << "LIELAIS cikla tests" <<endl;
    while (p != NULL)
    {
        cout << "pirmais cikla tests" <<endl;
        if(p->value == it->value)vaiIr = true;
        p = p->next;
        cout << "pirmais cikla tests" <<endl;
    }
    if(vaiIr == false)
    {
    pievieno(it->value,start,last);
    }
    it = it->next;
    if(it==last1)it=start2;
    if(it==last2->next)break;
    }
    druka(start);

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

        elem* start=NULL;
        elem *last = NULL;
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

        cout << "Pirmais saraksts: ";
        druka(start1);
        cout << "Otrais saraksts: ";                                    //Izdruk� ievad�to sarakstu
        druka(start2);                                    //izdruk� otru sarakstu

        isEqual(start, start1, start2, last1, last2);
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

