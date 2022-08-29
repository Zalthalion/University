#include<iostream>
#include"lvfriendly.h"
using namespace std;

template < typename T >

int vertskaits(T* mas, int n, T sk){
int skaits = 0;
for (int i = 0; i<n; i++){
    if(mas[i] == sk) skaits++;
}
return skaits;
}

int main(){
double *mas;
int n;
double sk;
int rez;
int ok;
do{
do{
cout << "Ievadi masîva izmçru" << endl;
cin >> n;
if (n<1) cout << "skaitlim jâbût lielâkam par 0" << endl;
}while (n<1);

mas = new double[n];

cout << "Aizpildi masîvu (masîva izmçrs: " << n << ")" << endl;
for(int i = 0; i<n; i++){
    cout << "Ievadi " << i+1 << ". skaitli" << endl;
    cin >> mas[i];
}
cout << "ievadi skaitli, kura sastapğanas reizes vçlies uzzinât" << endl;
cin >> sk;

rez = vertskaits(mas, n, sk);

cout << endl;
cout << "Ievadîtajâ masîvâ skaitlis " << sk << " sastopams " << rez << " reizes" << endl;

delete[] mas;

cout << "vai vçlaties programmu izpildît vçlreiz? (jâ=1 un nç =0)" << endl;
cin >> ok;
}while(ok==1);
}
