
#include <iostream>
#include <cmath>
#include "lvfriendly.h"
using namespace std;
int main()
{
        int ok, sk;
cout << "Programma kura nosaka ievadîtâ skaitïa pirmspçdçjo ciparu" << endl;
cout << endl;
do{
    do{
        cout << "Ievadi pozitîvu, veselu skaitli: ";
        cin >> sk;
    }while (floor(sk) > ceil(sk) || floor(sk) < ceil(sk) || sk<0);
        int rez;
        rez = sk % 100;
        rez = rez/10;
        cout << endl;
        cout << "Pirmspçdçjais cipars ir: " << rez <<endl;
        cout << endl;
cout << " Vai turpinât (1) vai beigt (0)?" << endl;
        cin >> ok;
}while (ok == 1);
}
