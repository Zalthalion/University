/*******************************************************************
G18. Uzrakst�t funkciju, kas sal�dzina vai divi saraksti ir vien�di
*******************************************************************/
#include <iostream>
#include <list>
#include "lvfriendly.h"
using namespace std;

///Void funkcija isEqual, kura sal�dzina vai saraksti ir vien�di
void isEqual(list <int> saraksts1, list<int>saraksts2)
{
    auto i = saraksts1.begin();
    auto j = saraksts2.begin();

    while(1)
    {
        if(*i != *j)
        {
            cout << "Saraksti nav vien�di!" << endl;
            return;
        }
        i++;
        j++;
        if(i==saraksts1.end() && j==saraksts2.end())
        {
            cout << "Saraksti ir vien�di!" << endl;
            return;
        }
    }
}

int main()
{
    int elemSk;             //Lietot�ja ievad�tais elementu skaits
    list<int> saraksts1;    //Pirmais saraksts
    list<int> saraksts2;    //Otrais saraksts
    int a;
    int papElem;            //Lietot�ja oevad�tais papildus elements;
    int ok;

    //Lietot�js izv�l�s cik elementi b�s sarakst� (Sarakstam ir j�b�t vismaz vienam elementam)
    do
    {
        cout<<"Ievadi, cik daudz saraksta elementus v�lies ievad�t: ";
        cin >> elemSk;
        if(elemSk < 1)
        {
            cout << "Saraksta elementu skaitam ir j�b�t liel�kam par 0!"<< endl;
        }
        cout << endl << endl;
    }while (elemSk<1);


    cout << "Aizpildi pirmo sarakstu: " << endl;
    //For cikls ar kuru lietot�js aizpilda sarakstu
    for(int i = 0; i<elemSk; i++)
    {
        cout << i+1 <<". elements: ";
        cin >> a;
        saraksts1.push_back(a);
    }

    cout << endl;

    cout << "Aizpildi otro sarakstu: " << endl;
    //For cikls ar kuru lietot�js aizpilda sarakstu
    for(int i = 0; i<elemSk; i++)
    {
        cout << i+1 <<". elements: ";
        cin >> a;
        saraksts2.push_back(a);
    }

    cout << endl;

    cout<<"Pirmais ievad�tais saraksts: ";

    //For cikls, kur� izdruk� pirmo sarakstu
    for(auto i=saraksts1.begin();i!=saraksts1.end();i++)cout<<*i<<" ";

    cout<<endl;

    cout<<"Otrais ievad�tais saraksts: ";

    //For cikls, kur� izdruk�  otro sarakstu
    for(auto i=saraksts2.begin();i!=saraksts2.end();i++)cout<<*i<<" ";

    cout<<endl;

    isEqual(saraksts1, saraksts2);                              //Izsauc funkciju, kura sal�dzina sarakstus

    saraksts1.erase(saraksts1.begin(), saraksts1.end());        //Izdz�� pirmo sarakstu
    saraksts2.erase(saraksts2.begin(), saraksts2.end());        //izdz�� otro sarakstu

    return 0;
}

/***************************************Testu pl�ns**************************************
    Elemetnu skaits     Pirmais saraksts        Otrais saraksts        V�lamais rezult�ts
          6             1 2 3 4 5 6             1 2 3 4 5 6 6           Saraksti ir vien�di
          0                     -                       -               Sarakstam ir j�b�t vismaz 1 elementu garam
          1                     5                       5               Saraksti ir vien�di
          4             1 3 3 7                     3 1 7 3             Saraksti nav vien�di
****************************************************************************************/
