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

cout << "Aizpildi mas�vu (mas�va izm�rs: " << RINSK << " rindas un " << KOLSK << " kolonnas" << endl;
cout << endl;

for (int n = 0; n < RINSK ; n++){
        for (int m = 0; m<KOLSK; m++){
                cout << "ievadi " << n+1 << ". rindas, " << m+1 << ". kolonnas locekli" << endl;
                cin >> matr[n][m];
        }
}

cout << "Ievadi rindas numuru, kurai gribi uzzin�t p�ra skait�u skaitu" << endl;
cin >> r;
cout << endl;

rez = rindpara(matr, RINSK, KOLSK, r-1);

cout << "�aj� rind� ir: "<< rez << " p�ra skait�u" << endl;

cout << endl;
cout << "vai v�laties programmu izpild�t v�lreiz? (j�=1 un n� =0)" << endl;
cin >> ok;
}while (ok==1);
}

