


#include <iostream>
#include "lvfriendly.h"
using namespace std;

int main (){
    int ok;
    do{
    int Nauda;
    do{
    cout << "ievadiet naudas summu,kas liel�ka par 0!" <<endl;
    cin >> Nauda;
    }while (Nauda <= 0);

switch (Nauda){
case (1+2):
    cout << "Var izveidot ar 1 un 2 mon�t�m" << endl;
    break;
case (1+5):
    cout << "Var izveidot ar 1 un 5 mon�t�m" <<endl;
    break;
case (2+5):
    cout << "Var izveidot ar 2 un 5 mon�t�m" <<endl;
    break;
default:
    cout << "Nevar" << endl;
}
    cout << "Vai v�laties turpin�t? (1=j� 2=n�)" << endl;
    cin >> ok;
}while (ok == 1);
}


