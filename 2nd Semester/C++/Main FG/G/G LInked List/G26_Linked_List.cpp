#include <iostream>
#include "lvfriendly.h"
using namespace std;
struct elem {
    int value;
    elem *next;
};

//funkcija izveido jaunu elementu un ievada tajâ informâciju
void pievieno(int sk, elem* &start, elem* &last)
{
    elem *p = new elem;
    p->value=sk;
    p->next=NULL;
    if(start==NULL) start=p;
    else last->next=p;
    last=p;
}

///Funkcija, kura izdzçð saraksta elementu, ja elementa vçrtîba pirms tam ir lielâka
void delIfNextLargerThanPrev(elem *&start)
{
    //Izveido divas palîgnorâdes
    elem *p = start;        //vienu pirms dzçðamâ elementa
    elem *del;              //un vienu dzçðamajam elementam


while (p->next!= NULL)
{
        if( p->next->value < p->value)  //Pârbauda kura vçrtîba ir lielaka
        {
            del = p->next;          //Pieðíir norâdi dzçðamajam elementam

            //Pârbauda vai netiek dzçsts pçdçjais elements
            if(del->next == NULL)
            {
                p->next = NULL;delete del;return;   //Ja ir jâdzçð saraksta pçdçjais elements, tad saiti pârkabina uz NULL
            }
            p->next = del->next;    //pârkabina saiti, lai varçtu izdzçst
            delete del;             //Izdzçð elementu

        }
            p = p->next;
}
return;

}

//funkcija kura izdrukâ sarakstu
void izdruka(elem *start)
{
    while (start!=NULL)
    {
        cout<<start->value<<" ";
        start=start->next;
    }
    cout << endl;
}

//funkcija kura ievadîto saraktu izdzçð
void dzest_sarakstu(elem* &start)
{
    while (start!=NULL)
    {
        start = start->next;
        delete start;
    }
}

int main(){

    int elemSk;     //Elementu skaits (saraksta garums)
    int sk;
    int ok;         //Palîgmainîgais, programmas atkârtotai izvçlei;

    do{
        do{
            cout<<"Ievadi, cik daudz saraksta elementus vçlies ievadît: ";
            cin >> elemSk;
            //datu pârbaude
            if(elemSk < 2)
            {
                cout << "Saraksta elementu skaitam ir jâbût vismaz 3 elementu garam lai programmai bûtu jçga!"<< endl;
            }
            cout << endl << endl;
        }while (elemSk<2);

        //Izveido tukðu sarakstu
        elem *start=NULL;
        elem *last=NULL;

        //aizpilda sarakstu
        for(int i=0;i<elemSk;i++)
        {
            cout << "ievadi " << i+1 <<". elementu: ";
            cin >> sk;
            pievieno(sk, start, last);
        }
        cout << endl;

        //izdruka
        cout << "Ievadîtais saraksts: ";
        izdruka(start);

        ///Izsauc funkciju, kas izpilda vçlamo uzdevumu
        delIfNextLargerThanPrev(start);
        cout << "Atjaunots saraksts: ";
        //izdruka
        izdruka(start);
        //izdzçð sarakstu
        dzest_sarakstu(start);

        cout << "Vai vçlaties programmu izmantot vçlreiz? (Jâ=1 un nç=0)"<< endl;
        cin >> ok;
    }while(ok==1);
        return 0;
}

/**********************Testu plâns ***************************
Elementu skaits     Saraksts           vçlamais rezultâts
    7             9 1 9 1 9 9               9 9 9 9
    5             1 2 3 4 1                 1 2 3 4
    7             4 1 5 2 6 3 7             4 5 6 7
    1                   -           Sarakstam jâbût vismaz 2 elementus garam
*************************************************************/
