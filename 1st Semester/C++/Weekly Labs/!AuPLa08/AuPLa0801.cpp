#include<iostream>
#include"lvfriendly.h"
using namespace std;


const int N=3;
const int M=2;

int main(){
int tab [N] [M];
int ok;
int liel, maz, rez;

do{
cout << "Programma kas apr��in�s starp�bu starp liel�ko un maz�ko skaitli" << endl;
cout << "Tiks apstr�d�ts mas�vs, kur� sast�v no "<< N << " rind�m un "<< M << " kolonn�m" << endl;



for(int rin = 0; rin < N; rin++){
    for(int kol = 0; kol < M; kol++){
         do{ cout << "Ievadi " << rin+1 <<  ". rindas un " << kol+1 << ". kolonnoas locekli" << endl;
                cin >> tab[rin][kol];
         if (tab[rin][kol] < 0) cout << "Skaitlim j�b�t natur�lam!" << endl;

         }while (tab[rin][kol]<0);
}
}

liel = tab[0][0];
maz = tab[0][0];

for(int rin = 0; rin < N; rin++){
    for(int kol = 0; kol < M; kol++){
if (tab[rin][kol] > liel) liel = tab[rin][kol];
         if (tab[rin][kol] < maz) maz = tab[rin][kol];
    }}

rez = liel - maz;
cout << "Amplit�da = " << rez << endl;

cout << "Vai v�laties programmu izpild�t v�lreiz? (j�=1 un n�=0)" << endl;
cin >> ok;
}while (ok==1);
}
