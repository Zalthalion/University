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
cout << "Ievadi mas�va izm�ru" << endl;
cin >> n;
if (n<1) cout << "skaitlim j�b�t liel�kam par 0" << endl;
}while (n<1);

mas = new double[n];

cout << "Aizpildi mas�vu (mas�va izm�rs: " << n << ")" << endl;
for(int i = 0; i<n; i++){
    cout << "Ievadi " << i+1 << ". skaitli" << endl;
    cin >> mas[i];
}
cout << "ievadi skaitli, kura sastap�anas reizes v�lies uzzin�t" << endl;
cin >> sk;

rez = vertskaits(mas, n, sk);

cout << endl;
cout << "Ievad�taj� mas�v� skaitlis " << sk << " sastopams " << rez << " reizes" << endl;

delete[] mas;

cout << "vai v�laties programmu izpild�t v�lreiz? (j�=1 un n� =0)" << endl;
cin >> ok;
}while(ok==1);
}
