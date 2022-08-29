/**
AuPLa0803. Sast�d�t C++ funkciju, kas apr��ina virknes n-to locekli.
Virkne uzdota ar sakar�bu:
v0 = 2; v1 = 3;
vn = 4*vn-1 + 3*vn-2;
Par�d�t, k� �o funkciju izsaukt ar konkr�t�m argumentu v�rt�b�m.
J�b�t iesp�jai programmu izpild�t atk�rtoti, neizejot no programmas.
**/
#include<iostream>
#include "lvfriendly.h"
using namespace std;


int virknesN(int vn){
if(vn == 1 || vn == 0) return 1;
 return 4*virknesN(vn-1)+3*virknesN(vn-2);
}


int main(){
int ok;
int v0 = 2;
int v1 = 3;
int vn;
int rez;
do{
    cout << "ievadi skaitli: ";
    cin >> vn;

    rez = virknesN(vn);
    cout << rez << endl;


    cout << "Again? 1Y 0N" << endl;
    cin >> ok;
}while (ok == 1);
return 0;
}
