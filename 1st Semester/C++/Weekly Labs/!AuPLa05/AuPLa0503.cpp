#include <iostream>
#include "lvfriendly.h"
using namespace std;

int cip_para(int ){
    int sk, psk;
    do{
    sk = s % 10;
    if (sk%2 == 0) psk++;
    sk/10;
    }while (sk>0);
    return psk;
}
int main(){
    int rez, s;
    cout << "Ievadi naturâlu skaitli, kurğ ir lielâks par 0" << endl;
    cin >> s;
    rez = cip_para(s);
    cout << rez << endl;




}
