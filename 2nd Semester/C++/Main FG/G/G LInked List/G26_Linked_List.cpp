#include <iostream>
#include "lvfriendly.h"
using namespace std;
struct elem {
    int value;
    elem *next;
};

//funkcija izveido jaunu elementu un ievada taj� inform�ciju
void pievieno(int sk, elem* &start, elem* &last)
{
    elem *p = new elem;
    p->value=sk;
    p->next=NULL;
    if(start==NULL) start=p;
    else last->next=p;
    last=p;
}

///Funkcija, kura izdz�� saraksta elementu, ja elementa v�rt�ba pirms tam ir liel�ka
void delIfNextLargerThanPrev(elem *&start)
{
    //Izveido divas pal�gnor�des
    elem *p = start;        //vienu pirms dz��am� elementa
    elem *del;              //un vienu dz��amajam elementam


while (p->next!= NULL)
{
        if( p->next->value < p->value)  //P�rbauda kura v�rt�ba ir lielaka
        {
            del = p->next;          //Pie��ir nor�di dz��amajam elementam

            //P�rbauda vai netiek dz�sts p�d�jais elements
            if(del->next == NULL)
            {
                p->next = NULL;delete del;return;   //Ja ir j�dz�� saraksta p�d�jais elements, tad saiti p�rkabina uz NULL
            }
            p->next = del->next;    //p�rkabina saiti, lai var�tu izdz�st
            delete del;             //Izdz�� elementu

        }
            p = p->next;
}
return;

}

//funkcija kura izdruk� sarakstu
void izdruka(elem *start)
{
    while (start!=NULL)
    {
        cout<<start->value<<" ";
        start=start->next;
    }
    cout << endl;
}

//funkcija kura ievad�to saraktu izdz��
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
    int ok;         //Pal�gmain�gais, programmas atk�rtotai izv�lei;

    do{
        do{
            cout<<"Ievadi, cik daudz saraksta elementus v�lies ievad�t: ";
            cin >> elemSk;
            //datu p�rbaude
            if(elemSk < 2)
            {
                cout << "Saraksta elementu skaitam ir j�b�t vismaz 3 elementu garam lai programmai b�tu j�ga!"<< endl;
            }
            cout << endl << endl;
        }while (elemSk<2);

        //Izveido tuk�u sarakstu
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
        cout << "Ievad�tais saraksts: ";
        izdruka(start);

        ///Izsauc funkciju, kas izpilda v�lamo uzdevumu
        delIfNextLargerThanPrev(start);
        cout << "Atjaunots saraksts: ";
        //izdruka
        izdruka(start);
        //izdz�� sarakstu
        dzest_sarakstu(start);

        cout << "Vai v�laties programmu izmantot v�lreiz? (J�=1 un n�=0)"<< endl;
        cin >> ok;
    }while(ok==1);
        return 0;
}

/**********************Testu pl�ns ***************************
Elementu skaits     Saraksts           v�lamais rezult�ts
    7             9 1 9 1 9 9               9 9 9 9
    5             1 2 3 4 1                 1 2 3 4
    7             4 1 5 2 6 3 7             4 5 6 7
    1                   -           Sarakstam j�b�t vismaz 2 elementus garam
*************************************************************/
