/**
AuPLa0201. Sastâdît C++ programmu, kura pârvçrð Fârenheita grâdos uzdotu temperatûru par temperatûru Celsija grâdos. Formula pârvçrðanai:
C = 5/9(F-32)
**/
#include<iostream>
#include"lvfriendly.h"
using namespace std;

int main(){
double F, C;
int ok;
do{
cout << "Ievadi temperatûru Fârenhçta grâdos: ";
cin >> F;
cout << endl;
C = 5/9*(F-32);
cout << "Ievadîtâ temperatûra ir: " << C << " grâdi pçc celsija" << endl;
cout << "Vai vçlaties programmu izpildît atkârtoti? (Jâ = 1 un Nç = 0)" << endl;
cin >> ok;
}while(ok==1);
return 0;
}

