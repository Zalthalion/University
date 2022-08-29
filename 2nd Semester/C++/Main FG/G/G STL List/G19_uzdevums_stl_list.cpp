/********************************************************************
G19. Uzrakstît funkciju, kas apgrieþ sarakstu otrâdi. Darbîbas laikâ
nedrîkst tikt izmantoti papildus elementi, kas dublçtu visu esoðâ
saraksta informâciju. Darbîba jâveic, pârkabinot saites, nevis
pârkopçjot elementu vçrtîbas.
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
// funkcija reverse(), kura apgrieþ otrâdi saraksta elementu secîbu
    saraksts.reverse();

//Apgrieztâ saraksta izdruka
    cout<<"Apgrieztais saraksts: ";
    for(auto i=saraksts.begin();i!=saraksts.end();i++) {
        cout<<*i<<" ";   }
    cout<<endl;
//Saraksta izdzçðana
    saraksts.erase(saraksts.begin(), saraksts.end());
//Jautâ vai lietotâjs vçlas izmantot programmu vçlreiz
    cout << "Vai vçlaties programmu izmantot vçlreiz? (jâ=1 un nç=0)" << endl;
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






