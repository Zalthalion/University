#include <iostream>
#include "lvfriendly.h"
using namespace std;
struct elem {
    int value;
    elem *next;
};

///void funkcija "pievieno", kura izveido jaunu elementu un ievada tajâ informâciju
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

    //Novieto palîgnorâdi vienu elementu pirms dzçðamâ
    for (int i=0; temp!=NULL && i<pos-1; i++)
    {
        temp = temp->next;
    }

    //Iegûst dzçðamâ elementa vçrtîbu, lai noskaidrotu kuru elementu jâliek dzçstâ vietâ
    vertiba = temp->next->value;

    // Pçdçjâ elementa dzçðana
    if(garums==pos)
    {
        vertiba = temp->value;
        if (vertiba>garums)
    {
        free(temp);
        cout<<"sarakstâ nav aizvietojama elementa" << endl;
        return;
    }
    }

    //Ja dzçðamâ elementa vçrtîba ir lielâka par saraksta garumu
    if(vertiba>garums)
    {
        del = temp->next;
        temp->next=temp->next->next;
        free(del);

        cout<<"sarakstâ nav aizvitojuma elementa" << endl;
        return;
    }

    //Novieto norâdi uz elementu ar kuru aizvietos izdzçsto
    while(a<vertiba)
    {
        a++;
        temp1= temp1->next;
    }

    //Vispârîga dzçðana (ârpus specgadîjumiem)
    temp3 = temp1->next;                    //Uzstâda palîgnorâdi uz aizvietojamâ elementa
    del = temp->next;                       //Uzstâda norâdi uz elementu, kuru vçlâs izdzçst
    temp1->next = temp3->next;              //"Atíçdç" aizvietojamo elementu no saraksta
    temp3->next = temp->next->next;         //Elementam pirms aizvietojamâ norâdi next pârvieto uz elementu aiz aizvietojamâ (salâpa caurumu)
    temp->next = temp3;                     //Savieno elementu pirms dzçðanas ar aizvietojamo elementu
    free(del);                              //izdzçð elementu
}

///Void funkcija "izdruka", kura izdrukâ sarakstu no sâkuma lîdz beigâm
void izdruka(elem *start)
{
    while (start!=NULL)
    {
        cout<<start->value<<" ";
        start=start->next;
    }
    cout << endl;
}

///Void funkcija "dzest_sarakstu", kura ievadîto saraktu izdzçð
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
    int sk;         //Lietoâja ievadîtais skaitlis, kuru pievienos sarakstam
    int elemNr;     //Elementa numurs, kuru lietoâjs grib izdzçst;
    int ok;         //Palîgmainîgais, programmas atkârtotai izvçlei;

    // do/while cikls, kurð nodroðina programmas atkârtotu izpildi to neaizverot
    do{
    // do/while cikls, kurð nodroðina, ka saraksta garums ir pietiekami garð (sarakstam ir jâbût vismaz 3 elementus garam, lai programmai bûtu jçga)
        do{
            cout<<"Ievadi, cik daudz saraksta elementus vçlies ievadît: ";
            cin >> elemSk;
            //datu pârbaude
            if(elemSk < 3)
            {
                cout << "Saraksta elementu skaitam ir jâbût vismaz 3 elementu garam lai programmai bûtu jçga!"<< endl;
            }
            cout << endl << endl;
        }while (elemSk<3);

        //Sâkuma norâde ir NULL, jo vçl nav ievadîts neviens saraksta elements
        elem *start=NULL;
        //Norâde uz pçdçjo saraksta elementu, lai atvieglotu saraksta papildinâðanu
        elem *last=NULL;

        //For cikls, kurð aizpilda sarakstu ar lietotâja ievadîtajiem skaitïiem
        for(int i=0;i<elemSk;i++)
        {
            cout << "ievadi " << i+1 <<". elementu: ";
            cin >> sk;
            pievieno(sk, start, last);      //Pievieno sarakstam lietotâja ievadîto skaitli
        }
        cout << endl;

        cout << "Ievadîtais saraksts: ";
        izdruka(start);                       //Izdrukâ ievadîto sarakstu

        cout << "Ievadi, kuru saraksta elementu gribi izdzçst: ";
        cin >> elemNr;

//        if(elemNr==0)
//        {
//            int vertiba;        //palîgmainîgais - kurð nosaka, kurð elements ir jâieliek dzçstâ vietâ
//            int a=1;            //palîgmainîgais norâdes novietoðanai
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
//                temp1 = temp1->next; //norâde pirms aizvoetojamâ
//            }
//
//            temp=temp1->next; //aizvietojamais
//            temp1->next = temp->next; //salâpa caurumu
//            temp->next=del->next;
//            start =temp;
//            free(del);
//
//        }else
        deleteNode(start, elemNr, elemSk); //izsauc elementa dzçðanas funkciju
        cout << "Atjaunots saraksts: ";
        izdruka(start);                       //Izdrukâ sarakstu
        dzest_sarakstu(start);                      //Izdzçð sarakstu
        cout << "Vai vçlaties programmu izmantot vçlreiz? (Jâ=1 un nç=0)"<< endl;
        cin >> ok;
    }while(ok==1);
        return 0;
}

/**********************Testu plâns ***************************
Elementu skaits     Saraksts       Izdzçstais elements     vçlamais rezultâts
    7             1 3 4 7 1 2 6             1                   1 7 4 1 2 6
    5             2 1 9 2 1                 0                   9 1 2 1
    6             1 2 4 12 1 2              3                   Sarakstâ nav elementa ar kuru aizvietot -> 1 2 3 1 2
    1                   -                   -                   Sarakstam jâbût vismaz 3 elementus garam
*************************************************************/
