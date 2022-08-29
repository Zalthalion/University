#include <iostream>
#include <list>
#include "lvfriendly.h"
using namespace std;

///Void funkcija isEqual, kura sal�dzina vai saraksti ir vien�di
void delIfNextLargerThanPrev(list <int>&saraksts)
{

    auto i = saraksts.begin();  //ieg�st nor�di uz saraksta s�kumu
    auto j = i;                 //Izveido jaunu nor�di ar� uz s�kumu
    j = ++j;                    //Bet p�rce� to uz n�kamo elementu, lai p�c tam tos sal�dzin�tu

    while (j!= saraksts.end())  //Cikls p�rstaig� saraksta elementus kam�r j nav sasniedzis saraksta beigas
                                //Kam�r j nav end, jo j ir t�l�k par i t� garant�jot, ka cikls neiziet �rpus saraksta
    {
        if( *j < *i)            //Ja tagad�jais ir maz�ks par iepriek��jo
        {
            //P�rbauda vai netiek dz�sts p�d�jais elements
            if(*j == saraksts.back())
            {
                saraksts.erase(j);      //Ja ir p�d�jais elements, tad to izdz�� un p�rtrauc ciklu
                break;
            }
            saraksts.erase(j);  //Ja elements nav p�d�jais, tad to izdz��
        }
        i++;
        j = i;
        j++;
    }
}
int main()
{
    int elemSk;            //Lietot�ja ievad�tais elementu skaits
    list<int> saraksts;
    int a;
    int ok;         //Pal�gmain�gais, programmas atk�rtotai izpildei
    do{
    //Lietot�js izv�l�s cik elementi b�s sarakst� (Sarakstam ir j�b�t vismaz diviem elementam)
    do
    {
        cout<<"Ievadi, cik daudz saraksta elementus v�lies ievad�t: ";
        cin >> elemSk;
        if(elemSk < 2)
        {
            cout << "Saraksta elementu skaitam ir j�b�t liel�kam par 2!"<< endl;
        }
        cout << endl << endl;
    }while (elemSk<2);


    cout << "Aizpildi pirmo sarakstu: " << endl;
    //Aizpilda sarakstu
    for(int i = 0; i<elemSk; i++)
    {
        cout << i+1 <<". elements: ";
        cin >> a;
        saraksts.push_back(a);      //Pievieno saraksta beig�m elementu
    }

    cout << endl;

    cout<<"Ievad�tais saraksts: ";

    //Izdruka
    for(auto i=saraksts.begin();i!=saraksts.end();i++)cout<<*i<<" ";

    cout<<endl;


    delIfNextLargerThanPrev(saraksts);

    //Izdruka
    for(auto i=saraksts.begin();i!=saraksts.end();i++)cout<<*i<<" ";
    //Izdz�� sarakstu
    saraksts.erase(saraksts.begin(), saraksts.end());        //Izdz�� pirmo sarakstu
    cout << endl;
    cout << "Vai v�laties programmu izmantot v�lreiz? (J�=1 un n�=0)"<< endl;
    cin >> ok;

    }while(ok==1);
    return 0;
}


/**********************Testu pl�ns ***************************
Elementu skaits     Saraksts           v�lamais rezult�ts
    7             9 1 9 1 9 9               9 9 9 9
    5             1 2 3 4 1                 1 2 3 4
    7             4 1 5 2 6 3 7             4 5 6 7
    1                   -           Sarakstam j�b�t vismaz 2 elementus garam
*************************************************************/
