/**
G13. Uzrakst�t funkciju, kas saraksta n-to elementu izn�cina
un t� viet� ievieto to elementu, kura numurs glab�j�s n-taj�
element�. Darb�ba j�veic, p�rkabinot saites, nevis p�rkop�jot
elementu v�rt�bas.
**/

#include<iostream>
#include<fstream>
#include<list>
#include "lvfriendly.h"
using namespace std;

//Funkcija delReplace, kura izdz�� n-to elementu un aizst�j to ar n-t� elementa v�rt�bas elementu

void delReplace(int elemSk, int elemNr, list<int>&saraksts)
{
    //Specgad�jums, ja izv�l�s pirmo elementu
    if(elemNr == 0)
    {
        auto i = saraksts.begin();
        int del = *i;
        if (del>elemSk || del == 0)     //Ja pirm� elementa v�rt�ba ir vien�da ar 0 vai liel�ka par saraksta elementu skaitu
        {
            saraksts.pop_front();                           //Tad izdz�� pirmo elementu un pazi�o, ka nav elementa ar ko aizvietot
            cout << "Nav elementa ar ko aizvietot"<<endl;
            return;
        }
        else
        {
            auto it = saraksts.begin();             //Ieg�st nor�di uz pirmo elementu
            advance(it, del);                       //P�rvieto to uz t� v�lamo elementu ar kuru aizst�s dz�sto
            saraksts.pop_front();                   //Izdz�� pirmo elementu
            saraksts.splice(saraksts.begin(), saraksts, it);    //P�rvieto elementu izdz�st� viet�
            return;
        }
    }

    //Specgad�jums, ja izv�l�tais dz��amais elements ir saraksta beig�s
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
//lietot�js izv�l�s cik daudz elementus v�las ievad�t sarakst�
    do{
    cout<<"Ievadi, cik daudz saraksta elementus v�lies ievad�t: ";
    cin >> elemSk;
    if(elemSk < 1)
    {
        cout << "Saraksta elementu skaitam ir j�b�t liel�kam par 0!"<< endl;
    }
    cout << endl << endl;
    }while (elemSk<1);

//lietot�js aizpilda sarakstu
    cout << "Aizpildi sarakstu: " << endl;
    for(int i = 0; i<elemSk; i++){
        cout << "ievadi saraksta " << i+1 <<". elementu: ";
        cin >> a;
        saraksts.push_back(a);
    }
    cout << endl;

//Ievad�t� saraksta izdruka
    cout<<"Ievad�tais saraksts: ";
    for(auto i=saraksts.begin();i!=saraksts.end();i++) {
        cout<<*i<<" ";   }
    cout<<endl;

 cout << "Ievadi, elementa numuru, kuru v�lies izdz�st: ";
 cin >> elemNr;

 ///Funkcijas izsauk�ana
 delReplace(elemSk, elemNr, saraksts);

 ///Saraksta izdruka
    cout << "Atjaunotais saraksts: ";
    for(auto i=saraksts.begin();i!=saraksts.end();i++)cout<<*i<<" ";
    cout<<endl;

///Saraksta izdz��ana
    saraksts.erase(saraksts.begin(), saraksts.end());

//Jaut� vai lietot�js v�las izmantot programmu v�lreiz
    cout << "Vai v�laties programmu izmantot v�lreiz? (j�=1 un n�=0)" << endl;
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







