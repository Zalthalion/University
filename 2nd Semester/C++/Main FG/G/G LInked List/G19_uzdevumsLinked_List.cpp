/********************************************************************
G19. Uzrakstît funkciju, kas apgrieþ sarakstu otrâdi. Darbîbas laikâ
nedrîkst tikt izmantoti papildus elementi, kas dublçtu visu esoðâ
saraksta informâciju. Darbîba jâveic, pârkabinot saites, nevis
pârkopçjot elementu vçrtîbas.
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

//Void funkcija "apgriez", kura ievadîto sarakstu apgrieþ otrâdi
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

    int sk; //Lietoâja ievadîtais skaitlis, kuru pievienos sarakstam
    int elemSk; //elementu daudzums
    int ok;
    do{
    do{
    cout<<"Ievadi, cik daudz saraksta elementus vçlies ievadît: ";
    cin >> elemSk;
    if(elemSk < 1)
    {
        cout << "Saraksta elementu skaitam ir jâbût lielâkam par 0!"<< endl;
    }
    cout << endl << endl;
    }while (elemSk<1);

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
    druka(start);                       //Izdrukâ ievadîto sarakstu
    apgriez(start);                     //Apgrieþ otrâdi ievadîto sarakstu
    cout << "Apgrieztais saraksts: ";
    druka(start);                       //Izdrukâ apgriezto sarakstu
    izdzes(start);                      //Izdzçð sarakstu
    cout << "Vai vçlaties programmu izmantot vçlreiz? (Jâ=1 un nç=0)"<< endl;
    cin >> ok;
    }while(ok==1);
    return 0;
}
/*******************************TESTU PLÂNS******************************************

Elementu skaits     Ievadîtais saraksts    Apgrieztais saraksts
                                           (vçlamais rezultâts)

7                   1;2;3;4;5;6;7           7;6;5;4;3;2;1
8                   0;7;0;1;1;9;9;9         9;9;9;1;1;0;0;7;0
0                   ----                    "Elementu skaitam jâbût lielâkam par 0"
1                   8                       8
*************************************************************************************/
