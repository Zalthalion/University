/**
AuPLa0201. Sast�d�t C++ programmu, kura p�rv�r� F�renheita gr�dos uzdotu temperat�ru par temperat�ru Celsija gr�dos. Formula p�rv�r�anai:
C = 5/9(F-32)
**/
#include<iostream>
#include"lvfriendly.h"
using namespace std;

int main(){
double F, C;
int ok;
do{
cout << "Ievadi temperat�ru F�renh�ta gr�dos: ";
cin >> F;
cout << endl;
C = 5/9*(F-32);
cout << "Ievad�t� temperat�ra ir: " << C << " gr�di p�c celsija" << endl;
cout << "Vai v�laties programmu izpild�t atk�rtoti? (J� = 1 un N� = 0)" << endl;
cin >> ok;
}while(ok==1);
return 0;
}

