/**
G13. Uzrakstît funkciju, kas saraksta n-to elementu iznîcina
un tâ vietâ ievieto to elementu, kura numurs glabâjâs n-tajâ
elementâ. Darbîba jâveic, pârkabinot saites, nevis pârkopçjot
elementu vçrtîbas.
**/

#include<iostream>
#include<fstream>
#include<list>
#include "lvfriendly.h"
using namespace std;

//Funkcija delReplace, kura izdzçð n-to elementu un aizstâj to ar n-tâ elementa vçrtîbas elementu

void delReplace(int elemSk, int elemNr, list<int>&saraksts)
{
    //Specgadîjums, ja izvçlâs pirmo elementu
    if(elemNr == 0)
    {
        auto i = saraksts.begin();
        int del = *i;
        if (del>elemSk || del == 0)     //Ja pirmâ elementa vçrtîba ir vienâda ar 0 vai lielâka par saraksta elementu skaitu
        {
            saraksts.pop_front();                           //Tad izdzçð pirmo elementu un paziòo, ka nav elementa ar ko aizvietot
            cout << "Nav elementa ar ko aizvietot"<<endl;
            return;
        }
        else
        {
            auto it = saraksts.begin();             //Iegûst norâdi uz pirmo elementu
            advance(it, del);                       //Pârvieto to uz tâ vçlamo elementu ar kuru aizstâs dzçsto
            saraksts.pop_front();                   //Izdzçð pirmo elementu
            saraksts.splice(saraksts.begin(), saraksts, it);    //Pârvieto elementu izdzçstâ vietâ
            return;
        }
    }

    //Specgadîjums, ja izvçlçtais dzçðamais elements ir saraksta beigâs
        if(elemSk == elemNr+1)
        {
            auto i = saraksts.back();
            if (i>elemSk)
            {
                saraksts.pop_back();
                cout << "Nav elementa ar ko aizvietot"<<endl;
                return;
            }
            else
            {
                auto it = saraksts.end();
                advance(it, i);
                saraksts.pop_back();
                saraksts.splice(saraksts.end(), saraksts, it);
                return;
            }
        }

    auto it1 = saraksts.begin();
    auto it2 = saraksts.begin();
    advance(it1, elemNr);
    int del = *it1;
    if(del>elemSk)
    {
        saraksts.erase(it1);
        cout << "Nav elementa ar ko aizvietot"<<endl;
        return;
    }
    else
    {
        advance(it2, del);
        saraksts.splice(it1, saraksts, it2);
        saraksts.erase(it1);
        return;
    }
        return;
}



int main() {
    int elemSk;
    list<int> saraksts;
    int a;
    int elemNr;
    int ok;
do{
//lietotâjs izvçlâs cik daudz elementus vçlas ievadît sarakstâ
    do{
    cout<<"Ievadi, cik daudz saraksta elementus vçlies ievadît: ";
    cin >> elemSk;
    if(elemSk < 1)
    {
        cout << "Saraksta elementu skaitam ir jâbût lielâkam par 0!"<< endl;
    }
    cout << endl << endl;
    }while (elemSk<1);

//lietotâjs aizpilda sarakstu
    cout << "Aizpildi sarakstu: " << endl;
    for(int i = 0; i<elemSk; i++){
        cout << "ievadi saraksta " << i+1 <<". elementu: ";
        cin >> a;
        saraksts.push_back(a);
    }
    cout << endl;

//Ievadîtâ saraksta izdruka
    cout<<"Ievadîtais saraksts: ";
    for(auto i=saraksts.begin();i!=saraksts.end();i++) {
        cout<<*i<<" ";   }
    cout<<endl;

 cout << "Ievadi, elementa numuru, kuru vçlies izdzçst: ";
 cin >> elemNr;

 ///Funkcijas izsaukðana
 delReplace(elemSk, elemNr, saraksts);

 ///Saraksta izdruka
    cout << "Atjaunotais saraksts: ";
    for(auto i=saraksts.begin();i!=saraksts.end();i++)cout<<*i<<" ";
    cout<<endl;

///Saraksta izdzçðana
    saraksts.erase(saraksts.begin(), saraksts.end());

//Jautâ vai lietotâjs vçlas izmantot programmu vçlreiz
    cout << "Vai vçlaties programmu izmantot vçlreiz? (jâ=1 un nç=0)" << endl;
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







