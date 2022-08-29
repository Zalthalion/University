/********************************************************************
G19. Uzrakst�t funkciju, kas apgrie� sarakstu otr�di. Darb�bas laik�
nedr�kst tikt izmantoti papildus elementi, kas dubl�tu visu eso��
saraksta inform�ciju. Darb�ba j�veic, p�rkabinot saites, nevis
p�rkop�jot elementu v�rt�bas.
Programmas autors: Juris Freidenfelds (jf18017)
Programma izveidota: 15.03.2019
********************************************************************/
#include<iostream>
#include<fstream>
#include<list>
#include "lvfriendly.h"
using namespace std;

int main() {
    int elemSk;
    list<int> saraksts;
    int a;
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
// funkcija reverse(), kura apgrie� otr�di saraksta elementu sec�bu
    saraksts.reverse();

//Apgriezt� saraksta izdruka
    cout<<"Apgrieztais saraksts: ";
    for(auto i=saraksts.begin();i!=saraksts.end();i++) {
        cout<<*i<<" ";   }
    cout<<endl;
//Saraksta izdz��ana
    saraksts.erase(saraksts.begin(), saraksts.end());
//Jaut� vai lietot�js v�las izmantot programmu v�lreiz
    cout << "Vai v�laties programmu izmantot v�lreiz? (j�=1 un n�=0)" << endl;
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






