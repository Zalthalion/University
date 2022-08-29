/**
AuPLa0803. Sastâdît C++ funkciju, kas aprçíina virknes n-to locekli.
Virkne uzdota ar sakarîbu:
v0 = 2; v1 = 3;
vn = 4*vn-1 + 3*vn-2;
Parâdît, kâ ðo funkciju izsaukt ar konkrçtâm argumentu vçrtîbâm.
Jâbût iespçjai programmu izpildît atkârtoti, neizejot no programmas.
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
