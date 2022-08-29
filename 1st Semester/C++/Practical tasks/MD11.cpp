#include<iostream>
#include"lvfriendly.h"
using namespace std;

int vaiIrPirmsk (int i){
bool b1;
int vd, dali = 1;
int daliSk = 0;
    do{vd=i%dali;
    if(vd==0) daliSk++;
    dali++;
    }while (dali <= i);
    b1 = daliSk == 2;
    return b1 ;
}


int main(){
int a, b, c, d;
int pirm;
int abint, cdint;
cout << "Ievadi skaitli a" << endl;
cin >> a;
cout << "Ievadi skaitli b" << endl;
cin >> b;
cout << "Ievadi skaitli c" << endl;
cin >> c;
cout << "Ievadi skaitli d" << endl;
cin >> d;

abint = 0;
cdint = 0;

for(a; a<=b; a++){
    pirm = vaiIrPirmsk(a);
    if (pirm==2) abint++;
}
for (c; c<=d; c++){
    pirm = vaiIrPirmsk(c);
    if (pirm==2) cdint++;
}
if (abint > cdint) cout<< "Vairâk pirmsskaitïu ir intervâlâ [a;b]" << endl; else cout<<"vairâk pirmsskaitïu ir intervâlâ [c;d]" << endl;
return 0;
}
