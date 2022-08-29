/********************************************************************
G19. Uzrakst�t funkciju, kas apgrie� sarakstu otr�di. Darb�bas laik�
nedr�kst tikt izmantoti papildus elementi, kas dubl�tu visu eso��
saraksta inform�ciju. Darb�ba j�veic, p�rkabinot saites, nevis
p�rkop�jot elementu v�rt�bas.
Programmas autors: Juris Freidenfelds (jf18017)
Programma izveidota: 23.03.2019
********************************************************************/
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

//Void funkcija "apgriez", kura ievad�to sarakstu apgrie� otr�di
void apgriez(elem* &start)
{
    elem *prev = NULL;
    elem *current = start;
    elem *next = NULL;

    while (current !=NULL)
    {
        next = current -> next;
        current->next=prev;
        prev = current;
        current = next;
    }
    start = prev;
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

    int sk; //Lieto�ja ievad�tais skaitlis, kuru pievienos sarakstam
    int elemSk; //elementu daudzums
    int ok;
    do{
    do{
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
        pievieno(sk, start, last);      //Pievieno sarakstam lietot�ja ievad�to skaitli
    }
    cout << endl;

    cout << "Ievad�tais saraksts: ";
    druka(start);                       //Izdruk� ievad�to sarakstu
    apgriez(start);                     //Apgrie� otr�di ievad�to sarakstu
    cout << "Apgrieztais saraksts: ";
    druka(start);                       //Izdruk� apgriezto sarakstu
    izdzes(start);                      //Izdz�� sarakstu
    cout << "Vai v�laties programmu izmantot v�lreiz? (J�=1 un n�=0)"<< endl;
    cin >> ok;
    }while(ok==1);
    return 0;
}
/*******************************TESTU PL�NS******************************************

Elementu skaits     Ievad�tais saraksts    Apgrieztais saraksts
                                           (v�lamais rezult�ts)

7                   1;2;3;4;5;6;7           7;6;5;4;3;2;1
8                   0;7;0;1;1;9;9;9         9;9;9;1;1;0;0;7;0
0                   ----                    "Elementu skaitam j�b�t liel�kam par 0"
1                   8                       8
*************************************************************************************/
