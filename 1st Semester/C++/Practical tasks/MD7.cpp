#include<iostream>
#include "lvfriendly.h"
using namespace std;
int main()
{
    double ok, sk, sum, rez, dal;
cout << "Vid�j� aritm�tisk� apr��in��ana" << endl;
cout << endl;
    do
    {
    dal = 0;
    sum = 0;
           do{
    cout << "Ievadi skaitli: ";
    cin >> sk;
    sum = sk + sum;
    dal++;
    }while (sk > 0);
    rez = sum / (dal - 1);
    cout << rez << endl;

        cout << " Vai s�kt no jauna (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}
