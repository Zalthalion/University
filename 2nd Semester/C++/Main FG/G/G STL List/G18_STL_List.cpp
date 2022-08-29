/*******************************************************************
G18. Uzrakstît funkciju, kas salîdzina vai divi saraksti ir vienâdi
*******************************************************************/
#include <iostream>
#include <list>
#include "lvfriendly.h"
using namespace std;

///Void funkcija isEqual, kura salîdzina vai saraksti ir vienâdi
void isEqual(list <int> saraksts1, list<int>saraksts2)
{
    auto i = saraksts1.begin();
    auto j = saraksts2.begin();

    while(1)
    {
        if(*i != *j)
        {
            cout << "Saraksti nav vienâdi!" << endl;
            return;
        }
        i++;
        j++;
        if(i==saraksts1.end() && j==saraksts2.end())
        {
            cout << "Saraksti ir vienâdi!" << endl;
            return;
        }
    }
}

int main()
{
    int elemSk;             //Lietotâja ievadîtais elementu skaits
    list<int> saraksts1;    //Pirmais saraksts
    list<int> saraksts2;    //Otrais saraksts
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


    cout << "Aizpildi pirmo sarakstu: " << endl;
    //For cikls ar kuru lietotâjs aizpilda sarakstu
    for(int i = 0; i<elemSk; i++)
    {
        cout << i+1 <<". elements: ";
        cin >> a;
        saraksts1.push_back(a);
    }

    cout << endl;

    cout << "Aizpildi otro sarakstu: " << endl;
    //For cikls ar kuru lietotâjs aizpilda sarakstu
    for(int i = 0; i<elemSk; i++)
    {
        cout << i+1 <<". elements: ";
        cin >> a;
        saraksts2.push_back(a);
    }

    cout << endl;

    cout<<"Pirmais ievadîtais saraksts: ";

    //For cikls, kurð izdrukâ pirmo sarakstu
    for(auto i=saraksts1.begin();i!=saraksts1.end();i++)cout<<*i<<" ";

    cout<<endl;

    cout<<"Otrais ievadîtais saraksts: ";

    //For cikls, kurð izdrukâ  otro sarakstu
    for(auto i=saraksts2.begin();i!=saraksts2.end();i++)cout<<*i<<" ";

    cout<<endl;

    isEqual(saraksts1, saraksts2);                              //Izsauc funkciju, kura salîdzina sarakstus

    saraksts1.erase(saraksts1.begin(), saraksts1.end());        //Izdzçð pirmo sarakstu
    saraksts2.erase(saraksts2.begin(), saraksts2.end());        //izdzçð otro sarakstu

    return 0;
}

/***************************************Testu plâns**************************************
    Elemetnu skaits     Pirmais saraksts        Otrais saraksts        Vçlamais rezultâts
          6             1 2 3 4 5 6             1 2 3 4 5 6 6           Saraksti ir vienâdi
          0                     -                       -               Sarakstam ir jâbût vismaz 1 elementu garam
          1                     5                       5               Saraksti ir vienâdi
          4             1 3 3 7                     3 1 7 3             Saraksti nav vienâdi
****************************************************************************************/
