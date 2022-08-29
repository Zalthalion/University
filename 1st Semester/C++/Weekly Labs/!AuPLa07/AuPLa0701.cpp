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
cout << "Ðajâ tekstâ burts " << c << " parâdâs " << bs << " reizes."<< endl;

    cout << "Vai vçlaties programmu izpildît atkârtoti? (Jâ = 1 un Nç = 0)" << endl;
    cin >> ok;
    cin.ignore();
}while (ok==1);
}
