#include<iostream>
#include"lvfriendly.h"
#include<fstream>
#include<cstring>
using namespace std;

int main(){
int vg, ok, tests = 0;
char sv[101],a,e,i,o,u;

char patsk[5] = {'a','e','i','o','u'};
do{
cout << "Ievadi tekstu" << endl;
cin.getline (sv, 101);
vg = strlen(sv);

for(int i = 0; i<5; i++){
    if(sv[vg-2]==patsk[i]) break; else continue;
    cout << "cau" << endl;
}
cout << "Pirmsp�d�jais burts nav patskanis!" << endl;
delete[] sv;
    cout << "V�lreiz? (j�=1 un n�=0)" << endl;
    cin >> ok;
    cin.ignore();
}while(ok==1);
}
