#include<iostream>
#include "lvfriendly.h"
using namespace std;
int main()
{
    int ok;
    do
    {   int a, b, c, dal;

        cout << "Ievadi pirmo skaitli (a): " << endl;
        cin >> a;

        if (a == 0){do{
            cout << "Ar 0 dal�t nedr�kst!!!" << endl;
            cout << "Ievadi v�lreiz pirmo skaitli" << endl;
            cin >> a;} while(a <= 0);
        }

        cout << endl;

        cout << "Ievadi otro skaitli (b): " << endl;
        cin >> b;

        if (a>b){do{
            cout << "Ievadi otro skaitli (b): " << endl;
            cout << "B ir j�b�t liel�kam par A" << endl;
            cout << endl;
        cin >> b;
        cout << endl;
        }while (a>b);}

        cout << endl;

        do{
        cout << "Ievadi tre�o skaitli (c): " << endl;
        cin >> c;
        cout << endl;}while (c<=0);

        cout << "Skait�a c dal�t�ji interv�l� [a;b] ir : " <<endl;
        dal = a;
        do{
            if(c % dal == 0)cout << dal << endl;
            dal++;
        }while(dal < b+1);
        cout << endl;
        cout << " Vai turpinaat (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}
