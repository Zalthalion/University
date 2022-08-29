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
#include <list>
#include "lvfriendly.h"
using namespace std;

//Void funkcija frontIfNotInList, kura pârbauda vai ievadîtais elements ir sastopams sarakstâ
//Un ja nav tad pievieno to saraksta sâkumâ
void frontIfNotInList(int papElem, list<int>&saraksts)
{
bool sastopams = false; //Bool mainîgais, kurð pasaka vai sarakstâ ir sastopams papiElem;

        //For cikls, kurð pârstaigâ saraksta elementus un pârbauda vai tajâ atrodas lietotâja ievadîtais skaitlis
        for (auto i=saraksts.begin(); i!=saraksts.end();i++)
        {
            if(papElem==*i)
            {
                sastopams = true;
                break;
            }
        }
        if(sastopams == false) saraksts.push_front(papElem);
        return;
}

int main()
{
    int elemSk;             //Lietotâja ievadîtais elementu skaits
    list<int> saraksts;
    int a;
    int papElem;            //Lietotâja oevadîtais papildus elements;
    int ok;

    //Lietotâjs izvçlâs cik elementi bûs sarakstâ (Sarakstam ir jâbût vismaz vienam elementam)
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


    cout << "Aizpildi sarakstu: " << endl;
    //For cikls ar kuru lietotâjs aizpilda sarakstu
    for(int i = 0; i<elemSk; i++)
    {
        cout << "ievadi saraksta " << i+1 <<". elementu: ";
        cin >> a;
        saraksts.push_back(a);
    }

    cout << endl;

    cout<<"Ievadîtais saraksts: ";

    //For cikls, kurð izdrukâ sarakstu
    for(auto i=saraksts.begin();i!=saraksts.end();i++)cout<<*i<<" ";

    cout<<endl;
    //Do cikls, kurð atïauj programmu izmantot vçlreiz
    do
    {
        //Lietotâjs ievada, kuru elementu grib pievienot sarakstam (ja tâds jau neeksistç sarakstâ)
        cout << "Îevadi elementu (ja elements nav sastopams sarakstâ, tad to pievienos saraksta sâkumâ): ";
        cin >> papElem;

        ///Funkcijas izsaukðana
        frontIfNotInList(papElem, saraksts);

        cout<<"Atjaunotais saraksts: ";
        for(auto i=saraksts.begin();i!=saraksts.end();i++)cout<<*i<<" ";
            cout<<endl;

            //Lietotâjs izvçlais vai atkârtot programmu (ievadît elementu vçlreiz)
            cout << "Vai vçlaties programmu izmantot vçlreiz? (jâ=1 un nç=0)" << endl;
            cin >> ok;
    }while(ok==1);

    //Saraksta dzçðana
    saraksts.erase(saraksts.begin(), saraksts.end());

    return 0;
}

/******************************************Testu plâns****************************************
Elementu skaits     Ievadîtie elementi      Ievadîtais papildus elements    Vçlamais rezultâts
    1                       5                           1                       1 5
    0                       -                           -                   Saraksta elementu skaitam ir jâbût lielâkam par 0!
    7               1 3 3 7 8 2 5                       9                   9 1 3 3 7 8 2 5
    4                   4 2 0 9                         0                   4 2 0 9
*********************************************************************************************/
