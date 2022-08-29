#include<iostream>
#include"lvfriendly.h"
using namespace std;

const int RINSK  = 2;
const int KOLSK = 3;
int rindpara(const int matr[][KOLSK], int n, int m, int r){
    int parsk = 0;
for(m = 0; m<=KOLSK; m++){
    if(matr[r][m]%2==0) parsk++;
}
return parsk;
}

int main(){

int matr[RINSK][KOLSK];
int rez;
int r;
int ok;

do{

cout << "Aizpildi masîvu (masîva izmçrs: " << RINSK << " rindas un " << KOLSK << " kolonnas" << endl;
cout << endl;

for (int n = 0; n < RINSK ; n++){
        for (int m = 0; m<KOLSK; m++){
                cout << "ievadi " << n+1 << ". rindas, " << m+1 << ". kolonnas locekli" << endl;
                cin >> matr[n][m];
        }
}

cout << "Ievadi rindas numuru, kurai gribi uzzinât pâra skaitïu skaitu" << endl;
cin >> r;
cout << endl;

rez = rindpara(matr, RINSK, KOLSK, r-1);

cout << "ðajâ rindâ ir: "<< rez << " pâra skaitïu" << endl;

cout << endl;
cout << "vai vçlaties programmu izpildît vçlreiz? (jâ=1 un nç =0)" << endl;
cin >> ok;
}while (ok==1);
}

