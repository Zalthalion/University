
#include <iostream>
#include <cmath>
#include "lvfriendly.h"
using namespace std;
int main()
{
        int ok, sk;
cout << "Programma kura nosaka ievad�t� skait�a pirmsp�d�jo ciparu" << endl;
cout << endl;
do{
    do{
        cout << "Ievadi pozit�vu, veselu skaitli: ";
        cin >> sk;
    }while (floor(sk) > ceil(sk) || floor(sk) < ceil(sk) || sk<0);
        int rez;
        rez = sk % 100;
        rez = rez/10;
        cout << endl;
        cout << "Pirmsp�d�jais cipars ir: " << rez <<endl;
        cout << endl;
cout << " Vai turpin�t (1) vai beigt (0)?" << endl;
        cin >> ok;
}while (ok == 1);
}
