#include <iostream>
#include "lvfriendly.h"
using namespace std;
struct elem {
    int value;
    elem *next;
};

///void funkcija "pievieno", kura izveido jaunu elementu un ievada taj� inform�ciju
void pievieno(int sk, elem* &start, elem* &last)
{
    elem *p = new elem;
    p->value=sk;
    p->next=NULL;
    if(start==NULL) start=p;
    else last->next=p;
    last=p;
}

///function to delete node at given pos
void deleteNode(elem *&start, int pos, int garums)
{
    int vertiba;
    int a=1;
    elem *temp = start;
    elem *temp1 = start;
    elem *del = start;
    elem *temp3 = start;

    //Novieto pal�gnor�di vienu elementu pirms dz��am�
    for (int i=0; temp!=NULL && i<pos-1; i++)
    {
        temp = temp->next;
    }

    //Ieg�st dz��am� elementa v�rt�bu, lai noskaidrotu kuru elementu j�liek dz�st� viet�
    vertiba = temp->next->value;

    // P�d�j� elementa dz��ana
    if(garums==pos)
    {
        vertiba = temp->value;
        if (vertiba>garums)
    {
        free(temp);
        cout<<"sarakst� nav aizvietojama elementa" << endl;
        return;
    }
    }

    //Ja dz��am� elementa v�rt�ba ir liel�ka par saraksta garumu
    if(vertiba>garums)
    {
        del = temp->next;
        temp->next=temp->next->next;
        free(del);

        cout<<"sarakst� nav aizvitojuma elementa" << endl;
        return;
    }

    //Novieto nor�di uz elementu ar kuru aizvietos izdz�sto
    while(a<vertiba)
    {
        a++;
        temp1= temp1->next;
    }

    //Visp�r�ga dz��ana (�rpus specgad�jumiem)
    temp3 = temp1->next;                    //Uzst�da pal�gnor�di uz aizvietojam� elementa
    del = temp->next;                       //Uzst�da nor�di uz elementu, kuru v�l�s izdz�st
    temp1->next = temp3->next;              //"At��d�" aizvietojamo elementu no saraksta
    temp3->next = temp->next->next;         //Elementam pirms aizvietojam� nor�di next p�rvieto uz elementu aiz aizvietojam� (sal�pa caurumu)
    temp->next = temp3;                     //Savieno elementu pirms dz��anas ar aizvietojamo elementu
    free(del);                              //izdz�� elementu
}

///Void funkcija "izdruka", kura izdruk� sarakstu no s�kuma l�dz beig�m
void izdruka(elem *start)
{
    while (start!=NULL)
    {
        cout<<start->value<<" ";
        start=start->next;
    }
    cout << endl;
}

///Void funkcija "dzest_sarakstu", kura ievad�to saraktu izdz��
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
    int sk;         //Lieto�ja ievad�tais skaitlis, kuru pievienos sarakstam
    int elemNr;     //Elementa numurs, kuru lieto�js grib izdz�st;
    int ok;         //Pal�gmain�gais, programmas atk�rtotai izv�lei;

    // do/while cikls, kur� nodro�ina programmas atk�rtotu izpildi to neaizverot
    do{
    // do/while cikls, kur� nodro�ina, ka saraksta garums ir pietiekami gar� (sarakstam ir j�b�t vismaz 3 elementus garam, lai programmai b�tu j�ga)
        do{
            cout<<"Ievadi, cik daudz saraksta elementus v�lies ievad�t: ";
            cin >> elemSk;
            //datu p�rbaude
            if(elemSk < 3)
            {
                cout << "Saraksta elementu skaitam ir j�b�t vismaz 3 elementu garam lai programmai b�tu j�ga!"<< endl;
            }
            cout << endl << endl;
        }while (elemSk<3);

        //S�kuma nor�de ir NULL, jo v�l nav ievad�ts neviens saraksta elements
        elem *start=NULL;
        //Nor�de uz p�d�jo saraksta elementu, lai atvieglotu saraksta papildin��anu
        elem *last=NULL;

        //For cikls, kur� aizpilda sarakstu ar lietot�ja ievad�tajiem skait�iem
        for(int i=0;i<elemSk;i++)
        {
            cout << "ievadi " << i+1 <<". elementu: ";
            cin >> sk;
            pievieno(sk, start, last);      //Pievieno sarakstam lietot�ja ievad�to skaitli
        }
        cout << endl;

        cout << "Ievad�tais saraksts: ";
        izdruka(start);                       //Izdruk� ievad�to sarakstu

        cout << "Ievadi, kuru saraksta elementu gribi izdz�st: ";
        cin >> elemNr;

//        if(elemNr==0)
//        {
//            int vertiba;        //pal�gmain�gais - kur� nosaka, kur� elements ir j�ieliek dz�st� viet�
//            int a=1;            //pal�gmain�gais nor�des novieto�anai
//            elem *temp=start;
//            elem *temp1=start;
//            elem *del = start;
//            vertiba = del->value;
//            if (vertiba==0)
//            {
//                del = start;
//                start = start->next;
//                free(del);
//            }
//            while(a<vertiba)
//            {
//                a++;
//                temp1 = temp1->next; //nor�de pirms aizvoetojam�
//            }
//
//            temp=temp1->next; //aizvietojamais
//            temp1->next = temp->next; //sal�pa caurumu
//            temp->next=del->next;
//            start =temp;
//            free(del);
//
//        }else
        deleteNode(start, elemNr, elemSk); //izsauc elementa dz��anas funkciju
        cout << "Atjaunots saraksts: ";
        izdruka(start);                       //Izdruk� sarakstu
        dzest_sarakstu(start);                      //Izdz�� sarakstu
        cout << "Vai v�laties programmu izmantot v�lreiz? (J�=1 un n�=0)"<< endl;
        cin >> ok;
    }while(ok==1);
        return 0;
}

/**********************Testu pl�ns ***************************
Elementu skaits     Saraksts       Izdz�stais elements     v�lamais rezult�ts
    7             1 3 4 7 1 2 6             1                   1 7 4 1 2 6
    5             2 1 9 2 1                 0                   9 1 2 1
    6             1 2 4 12 1 2              3                   Sarakst� nav elementa ar kuru aizvietot -> 1 2 3 1 2
    1                   -                   -                   Sarakstam j�b�t vismaz 3 elementus garam
*************************************************************/
