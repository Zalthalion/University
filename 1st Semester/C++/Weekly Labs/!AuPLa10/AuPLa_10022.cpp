#include<iostream>
#include"lvfriendly.h"
using namespace std;


int vertskaits(int* mas, int n, int sk){
if (n<0) return 0;
if (mas[n] != sk){
    return (mas, (n-1), sk);
}else return 1+vertskaits(mas, (n-1), sk);
}

int main(){
int *mas;
int n;
int sk;
int rez;
int ok;
do{
do{
cout << "Ievadi mas�va izm�ru" << endl;
cin >> n;
if (n<1) cout << "skaitlim j�b�t liel�kam par 0" << endl;
}while (n<1);

mas = new int[n];

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
