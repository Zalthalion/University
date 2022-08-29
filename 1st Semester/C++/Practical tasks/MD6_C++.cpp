
#include<iostream>
#include "lvfriendly.h"
using namespace std;
int main()
{
        int sk, vsk, cip;
    int ok;
    cout << "Nosaka ievadîtâ skaitïa ciparu daudzumu! "<< endl;
    cout << endl;
    do
    {
       do
        {
        cout << "Ievadiet naturâlu skaitli, lielâku vai vienâdu ar 0: ";
        cin >> sk;
        }while(sk<0);
       vsk=0;
        do{

           cip= sk % 10;
           if(cip >= 0) vsk++;
           sk = sk / 10;
       }while(sk>0);

      cout << "Ðajâ skaitlî ir " << vsk << " cipari!" << endl;
      cout << endl;
        cout << " Vai turpinât (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}

