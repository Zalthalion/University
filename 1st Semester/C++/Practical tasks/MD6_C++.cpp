
#include<iostream>
#include "lvfriendly.h"
using namespace std;
int main()
{
        int sk, vsk, cip;
    int ok;
    cout << "Nosaka ievad�t� skait�a ciparu daudzumu! "<< endl;
    cout << endl;
    do
    {
       do
        {
        cout << "Ievadiet natur�lu skaitli, liel�ku vai vien�du ar 0: ";
        cin >> sk;
        }while(sk<0);
       vsk=0;
        do{

           cip= sk % 10;
           if(cip >= 0) vsk++;
           sk = sk / 10;
       }while(sk>0);

      cout << "�aj� skaitl� ir " << vsk << " cipari!" << endl;
      cout << endl;
        cout << " Vai turpin�t (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}

