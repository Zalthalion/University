/***************************************************
AuPLa0203. Sast�d�t C++ programmu, kas apr��ina
funkcijas f(x) v�rt�bu y. Funkcija f(x) uzdota ar
sakar�bu:
y ir 0, ja x maz�ks par -2;
y ir �x-2, ja x ir robe��s no -2 l�dz -1;
y ir x, ja x ir robe��s no -1 l�dz 1(neieskaitot);
y ir �x+2, ja x ir robe��s no 1 l�dz 2(neieskaitot);
y ir 0, ja x ir liel�ks vai vien�ds ar 2.
J�b�t iesp�jai programmu izpild�t atk�rtoti, neizejot no programmas.
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
        cout << "Vai v�laties izmantot programmu v�lreiz? (J� = 1 un N� = 0)" << endl;
        cin >> ok;
}while (ok==1);


}
