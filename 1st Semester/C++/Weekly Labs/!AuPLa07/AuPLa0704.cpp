/*******************************
AuPLa0704. Sastâdît C++ programmu,
kas ïauj noskaidrot, vai doto naturâlu
skaitli n var izteikt kâ divu naturâlu
skaitïu kvadrâtu summu. Izdrukât visus
ðâdus naturâlu skaitïu pârus. Risinâjumâ
izmantot funkciju, kas aprçíina divu
naturâlu skaitïu kvadrâtu summu.
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
cout << n << " Var izteikt kâ " << a << " un " << b << " kvadrâtu summu" << endl;}
else continue;
}}
if (tests == 0) cout << n << " Nevar izteikt kâ divu skaitïu kvadrâtu summu" << endl;
cout << "Vai vçlies izmantot programmu vçlreiz? (jâ=1 un nç = 0)" << endl;
cin >> ok;
    }while (ok==1);
}
