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
            cout << "Ar 0 dalît nedrîkst!!!" << endl;
            cout << "Ievadi vçlreiz pirmo skaitli" << endl;
            cin >> a;} while(a <= 0);
        }

        cout << endl;

        cout << "Ievadi otro skaitli (b): " << endl;
        cin >> b;

        if (a>b){do{
            cout << "Ievadi otro skaitli (b): " << endl;
            cout << "B ir jâbût lielâkam par A" << endl;
            cout << endl;
        cin >> b;
        cout << endl;
        }while (a>b);}

        cout << endl;

        do{
        cout << "Ievadi treðo skaitli (c): " << endl;
        cin >> c;
        cout << endl;}while (c<=0);

        cout << "Skaitïa c dalîtâji intervâlâ [a;b] ir : " <<endl;
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
