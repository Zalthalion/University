#include<iostream>
#include"lvfriendly.h"
using namespace std;

int kapinasana(int a, int b){
int kapin;
if(b==0) return 1;
kapin = a;
for (int i = 1; i<b; i++)
    kapin = kapin * a;
return kapin;}

int main(){
int a, b, rez;
cout << "Ievadi bâzi: " << endl;
cin >> a;
cout << "ievadi pakâpi: " << endl;
cin >> b;
rez = kapinasana(a, b);
cout << a << " pakâpç " << b << " ir: " << endl;
cout << rez << endl;
return 0;}
