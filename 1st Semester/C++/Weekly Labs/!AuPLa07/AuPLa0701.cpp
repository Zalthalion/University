#include <iostream>
#include <cstring>
#include <fstream>
#include "lvfriendly.h"
using namespace std;

int main(){
int ok, vg, bs;
char sv[81], c;

do{
cout << "Ievadi tekstu!" << endl;
cin.getline (sv, 81);
cout << "ievadi burtu!" << endl;
cin.get(c);

vg = strlen(sv);
bs = 0;
for(int i = 0; i<vg; i++){
    if(sv[i]==c) bs++;
}
cout << "�aj� tekst� burts " << c << " par�d�s " << bs << " reizes."<< endl;

    cout << "Vai v�laties programmu izpild�t atk�rtoti? (J� = 1 un N� = 0)" << endl;
    cin >> ok;
    cin.ignore();
}while (ok==1);
}
