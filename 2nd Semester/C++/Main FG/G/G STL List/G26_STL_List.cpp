#include <iostream>
#include <list>
#include "lvfriendly.h"
using namespace std;

///Void funkcija isEqual, kura salîdzina vai saraksti ir vienâdi
void delIfNextLargerThanPrev(list <int>&saraksts)
{

    auto i = saraksts.begin();  //iegûst norâdi uz saraksta sâkumu
    auto j = i;                 //Izveido jaunu norâdi arî uz sâkumu
    j = ++j;                    //Bet pârceï to uz nâkamo elementu, lai pçc tam tos salîdzinâtu

    while (j!= saraksts.end())  //Cikls pârstaigâ saraksta elementus kamçr j nav sasniedzis saraksta beigas
                                //Kamçr j nav end, jo j ir tâlâk par i tâ garantçjot, ka cikls neiziet ârpus saraksta
    {
        if( *j < *i)            //Ja tagadçjais ir mazâks par iepriekðçjo
        {
            //Pârbauda vai netiek dzçsts pçdçjais elements
            if(*j == saraksts.back())
            {
                saraksts.erase(j);      //Ja ir pçdçjais elements, tad to izdzçð un pârtrauc ciklu
                break;
            }
            saraksts.erase(j);  //Ja elements nav pçdçjais, tad to izdzçð
        }
        i++;
        j = i;
        j++;
    }
}
int main()
{
    int elemSk;            //Lietotâja ievadîtais elementu skaits
    list<int> saraksts;
    int a;
    int ok;         //Palîgmainîgais, programmas atkârtotai izpildei
    do{
    //Lietotâjs izvçlâs cik elementi bûs sarakstâ (Sarakstam ir jâbût vismaz diviem elementam)
    do
    {
        cout<<"Ievadi, cik daudz saraksta elementus vçlies ievadît: ";
        cin >> elemSk;
        if(elemSk < 2)
        {
            cout << "Saraksta elementu skaitam ir jâbût lielâkam par 2!"<< endl;
        }
        cout << endl << endl;
    }while (elemSk<2);


    cout << "Aizpildi pirmo sarakstu: " << endl;
    //Aizpilda sarakstu
    for(int i = 0; i<elemSk; i++)
    {
        cout << i+1 <<". elements: ";
        cin >> a;
        saraksts.push_back(a);      //Pievieno saraksta beigâm elementu
    }

    cout << endl;

    cout<<"Ievadîtais saraksts: ";

    //Izdruka
    for(auto i=saraksts.begin();i!=saraksts.end();i++)cout<<*i<<" ";

    cout<<endl;


    delIfNextLargerThanPrev(saraksts);

    //Izdruka
    for(auto i=saraksts.begin();i!=saraksts.end();i++)cout<<*i<<" ";
    //Izdzçð sarakstu
    saraksts.erase(saraksts.begin(), saraksts.end());        //Izdzçð pirmo sarakstu
    cout << endl;
    cout << "Vai vçlaties programmu izmantot vçlreiz? (Jâ=1 un nç=0)"<< endl;
    cin >> ok;

    }while(ok==1);
    return 0;
}


/**********************Testu plâns ***************************
Elementu skaits     Saraksts           vçlamais rezultâts
    7             9 1 9 1 9 9               9 9 9 9
    5             1 2 3 4 1                 1 2 3 4
    7             4 1 5 2 6 3 7             4 5 6 7
    1                   -           Sarakstam jâbût vismaz 2 elementus garam
*************************************************************/
