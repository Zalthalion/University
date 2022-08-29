/***************************************************
AuPLa0203. Sastâdît C++ programmu, kas aprçíina
funkcijas f(x) vçrtîbu y. Funkcija f(x) uzdota ar
sakarîbu:
y ir 0, ja x mazâks par -2;
y ir –x-2, ja x ir robeþâs no -2 lîdz -1;
y ir x, ja x ir robeþâs no -1 lîdz 1(neieskaitot);
y ir –x+2, ja x ir robeþâs no 1 lîdz 2(neieskaitot);
y ir 0, ja x ir lielâks vai vienâds ar 2.
Jâbût iespçjai programmu izpildît atkârtoti, neizejot no programmas.
***************************************************/
#include <iostream>
#include "lvfriendly.h"
using namespace std;

int main(){
int ok, x, y;
do {
        cout <<"ievadiet X" << endl;
        cin >> x;
        if (x<-2) y = 0;
        if (x >= -2 && x < -1) y = -x-2;
        if (x >= -1 && x < 1) y = x;
        if (x >= 1 && x < 2) y = -x+2;
        if (x >= 2) y = 0;
        cout << y << endl;
        cout << "Vai vçlaties izmantot programmu vçlreiz? (Jâ = 1 un Nç = 0)" << endl;
        cin >> ok;
}while (ok==1);


}
