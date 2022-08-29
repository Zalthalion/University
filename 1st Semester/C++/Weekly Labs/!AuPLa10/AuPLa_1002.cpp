#include<iostream>
#include"lvfriendly.h"
using namespace std;

int rindpara(const int** mas, int rinsk, int kolsk, int rin){
int parsk = 0;
for (int m = 0; m<kolsk; m++){
    if (mas[rin][m]);
}
}

int main(){
int** mas;
int rinsk, kolsk;
int rin;
int rez;
int ok;

cout << "Ievadi masîva rindu skaitu" << endl;
cin >> rinsk;
cout << "Ievadi masîva kolonnu skaitu" << endl;
cin >>  kolsk;

mas = new int [rinsk][kolsk];

cout << "Aizpildi masîvu" << endl;

for(int r = 0; r<rinsk; r++){
    for(int k = 0; k<kolsk; k++){
        cout << "Ievadi " << rinsk+1 << ". rindas " << kolsk+1 << ". kolonnas skaitli" << endl;
        cin >> mas[rinsk][kolsk];
    }
}
cout << "Ievadi rindas numuru, kurai gribi uzzinât pâra skaitïu skaitu" << endl;
cin  >> rin;

rez = rindpara(mas, rinsk, kolsk, r-1);

cout << "ğajâ rindâ ir: " << rez << " pâra skaitïu" << endl;
delete[] mas;
return 0;
}
