/*******************************
AuPLa0704. Sast�d�t C++ programmu,
kas �auj noskaidrot, vai doto natur�lu
skaitli n var izteikt k� divu natur�lu
skait�u kvadr�tu summu. Izdruk�t visus
��dus natur�lu skait�u p�rus. Risin�jum�
izmantot funkciju, kas apr��ina divu
natur�lu skait�u kvadr�tu summu.
*******************************/

#include<iostream>
#include "lvfriendly.h"
using namespace std;

int kvadratuSum (int a, int b){
int sum;
a = a*a;
b = b*b;
sum = a+b;
return sum;
}
int main(){
    int a,b,n, rez;
    int tests = 0;
    int ok;

    do{
cout << "Ievadi skaitli" << endl;
    cin >> n;
for(a = 1; a < n ; a++){
    for(b=1;b<a;b++){
    rez = kvadratuSum(a, b);
    if(n==rez){tests++;
cout << n << " Var izteikt k� " << a << " un " << b << " kvadr�tu summu" << endl;}
else continue;
}}
if (tests == 0) cout << n << " Nevar izteikt k� divu skait�u kvadr�tu summu" << endl;
cout << "Vai v�lies izmantot programmu v�lreiz? (j�=1 un n� = 0)" << endl;
cin >> ok;
    }while (ok==1);
}
