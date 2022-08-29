/******************************************************************
G18. Uzrakstît funkciju, kas salîdzina vai divi saraksti ir vienâdi
******************************************************************/
#include <iostream>
#include "lvfriendly.h"
using namespace std;

struct elem {
    int value;
    elem *next;
};

//Void funkcija "pievieno", kura izveido jaunu elementu un ievada tajâ informâciju
void pievieno(int sk, elem* &start, elem* &last)
{
    elem *p = new elem;
    p->value=sk;
    p->next=NULL;
    if(start==NULL) start=p;
    else last->next=p;
    last=p;
}

//Void funkcija "druka", kura izdrukâ sarakstu
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
    elem *p1 = start1;          //Novieto norâdi uz pirmo elementu
    elem *p2 = start2;

    while(1)
    {
        if(p1->value != p2->value)
        {
            cout << "Saraksti nav vienâdi" <<endl;

            return;
        }
        p1=p1->next;
        p2=p2->next;
        if(p1->next==NULL && p2->next==NULL)
        {
            cout << "Saraksts ir vienâds" << endl;
            return;
        }
    }
}
//Void funkcija "izdzes", kura ievadîto saraktu izdzçð
void izdzes(elem* &start)
{
    while (start!=NULL)
    {
        start = start->next;
        delete start;
    }
}

int main(){

    int sk;             //Lietoâja ievadîtais skaitlis, kuru pievienos sarakstam
    int elemSk;         //Elementu daudzums
    int papElem;        //Elements, kuru lietotâjs grib pievienot sarakstam
    int ok;             //Papildus mainîgais, kurð tiek izmantots programmas atkârtotai izmantoðanai

    do
    {

    do
    {
        cout<<"Ievadi, cik daudz saraksta elementus vçlies ievadît: ";
        cin >> elemSk;
        if(elemSk < 1)
        {
            cout << "Saraksta elementu skaitam ir jâbût lielâkam par 0!"<< endl;
        }
        cout << endl << endl;
        }while (elemSk<1);

        //Sâkuma norâde ir NULL, jo vçl nav ievadîts neviens pirmâ saraksta elements
        elem *start1=NULL;
        //Norâde uz pçdçjo saraksta elementu, lai atvieglotu pirmâ saraksta papildinâðanu
        elem *last1=NULL;

        //Sâkuma norâde ir NULL, jo vçl nav ievadîts neviens otrâ saraksta elements
        elem *start2=NULL;
        //Norâde uz pçdçjo saraksta elementu, lai atvieglotu otrâ saraksta papildinâðanu
        elem *last2=NULL;


        //For cikls, kurð aizpilda pirmo sarakstu ar lietotâja ievadîtajiem skaitïiem
        cout << "Aizpildi pirmo sarakstu!" << endl;
        for(int i=0;i<elemSk;i++)
        {
            cout << "ievadi " << i+1 <<". elementu: ";
            cin >> sk;
            pievieno(sk, start1, last1);                   //Pievieno sarakstam lietotâja ievadîto skaitli
        }
        cout << endl;

        //For cikls, kurð aizpilda pirmo sarakstu ar lietotâja ievadîtajiem skaitïiem
        cout << "Aizpildi otro sarakstu!" << endl;
        for(int i=0;i<elemSk;i++)
        {
            cout << "ievadi " << i+1 <<". elementu: ";
            cin >> sk;
            pievieno(sk, start2, last2);                   //Pievieno sarakstam lietotâja ievadîto skaitli
        }
        cout << endl;

        cout << "Ievadîtais saraksts: ";
        druka(start1);                                    //Izdrukâ ievadîto sarakstu
        druka(start2);                                    //izdrukâ otru sarakstu

        isEqual(start1, start2);
//
//        cout << "Atjaunots saraksts: ";
//        druka(start1);                                    //Izdrukâ apgriezto sarakstu
        izdzes(start1);                      //Izdzçð sarakstu
        izdzes(start2);
        cout << "Vai vçlaties programmu izmantot vçlreiz? (Jâ=1 un nç=0)"<< endl;
        cin >> ok;

    }while(ok==1);


        return 0;
}
/***************************************Testu plâns**************************************
    Elemetnu skaits     Pirmais saraksts        Otrais saraksts        Vçlamais rezultâts
          6             1 2 3 4 5 6             1 2 3 4 5 6 6           Saraksti ir vienâdi
          0                     -                       -               Sarakstam ir jâbût vismaz 1 elementu garam
          1                     5                       5               Saraksti ir vienâdi
          4             1 3 3 7                     3 1 7 3             Saraksti nav vienâdi
****************************************************************************************/

