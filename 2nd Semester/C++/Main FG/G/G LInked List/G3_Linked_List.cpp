/****************************************************************************************
Izveidot programmu valodâ C++, kas ïauj izveidot vienvirziena saistîto sarakstu
(izmantojot dinamiskâs datu struktûras),kurâ glabâjas noteikta tipa vçrtîbas.
Jâbût  paredzçtai iespçjai sarakstu papildinât ar jaunu elementu (pielikt elementu saraksta galâ),
izdrukât sarakstu, iznîcinât sarakstu. Bez tam jâuzraksta funkcija, kura aprakstîta zemâk.
Iznîcinot saraksta elementus, korekti jâatbrîvo izdalîtâ atmiòa.
Galvenajâ programmâ:
a) jâbût iespçjai ievadît saraksta elementus (izveidot patvaïîgu sarakstu),
b) jâpielieto uzrakstîtâ funkcija sarakstam,
c) jâizdrukâ saraksts pçc funkcijas darbîbas.
d) beigâs jâiznîcina saraksts (lietojot delete).
Sîkâkas prasîbas sk. Laboratorijas darbu noteikumos.

G3. Uzrakstît funkciju, kas pieliek sarakstam jaunu elementu saraksta sâkumâ, ja elements ar tâdu vçrtîbu neeksistç.
****************************************************************************************/
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

///Void funkcija frontIfNotInList, kura pievieno saraksta sâkumâ skaitli, ja tas nav sastopams sarakstâ
void frontIfNotInList(int papElem, elem* &start)
{
    elem *dummyStart = start;           //Papildus norâde, lai nepazaudçtu sâkuma elementu
    elem *p = new elem;                 //Izveido jaunu elementu ar norâdi p
    bool isInList = false;              //Bool mainîgais, lai zinâtu, vai elements ir sastopams sarakstâ
    while (start!=NULL)                 //While cikls, kurð pârstaigâ sarakstu un pârbauda vai tajâ ir sastopams lietotâja ievadîtais skaitlis
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
        p->value = papElem;             //Jaunajâ elementâ ievieto, lietotâja ievadîto skaitli
        p->next = dummyStart;           //Piekabina jauno elementu saraksta sâkumâ
        start = p;                      //Norâdi "Start" novieto uz jauno elementu (jaunais elements ir saraksta sâkumâ)
        return;
    }else start = dummyStart;
    return;

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
            pievieno(sk, start, last);                   //Pievieno sarakstam lietotâja ievadîto skaitli
        }
        cout << endl;

    do
    {
        cout << "Ievadîtais saraksts: ";
        druka(start);                                    //Izdrukâ ievadîto sarakstu

        cout << "Ievadi skaitli, kuru pievienot sarakstam"<<endl;
        cout << "(skaitlis tiks pievienots sarakstam, ja tas nav sastopams sarakstâ)"<<endl;
        cin >> papElem;

        frontIfNotInList(papElem, start);                //Pievieno elementu saraksta sâkumâ, ja tas nav sastopams sarakstâ

        cout << "Atjaunots saraksts: ";
        druka(start);                                    //Izdrukâ apgriezto sarakstu
        cout << "Vai vçlaties programmu izmantot vçlreiz? (Jâ=1 un nç=0)"<< endl;
        cin >> ok;
    }while(ok==1);

        izdzes(start);                      //Izdzçð sarakstu
        return 0;
}
/******************************************Testu plâns****************************************
Elementu skaits     Ievadîtie elementi      Ievadîtais papildus elements    Vçlamais rezultâts
    1                       5                           1                       1 5
    0                       -                           -                   Saraksta elementu skaitam ir jâbût lielâkam par 0!
    7               1 3 3 7 8 2 5                       9                   9 1 3 3 7 8 2 5
    4                   4 2 0 9                         0                   4 2 0 9
*********************************************************************************************/

