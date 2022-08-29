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
cout << "Programma kas aprçíinâs starpîbu starp lielâko un mazâko skaitli" << endl;
cout << "Tiks apstrâdâts masîvs, kurð sastâv no "<< N << " rindâm un "<< M << " kolonnâm" << endl;



for(int rin = 0; rin < N; rin++){
    for(int kol = 0; kol < M; kol++){
         do{ cout << "Ievadi " << rin+1 <<  ". rindas un " << kol+1 << ". kolonnoas locekli" << endl;
                cin >> tab[rin][kol];
         if (tab[rin][kol] < 0) cout << "Skaitlim jâbût naturâlam!" << endl;

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
cout << "Amplitûda = " << rez << endl;

cout << "Vai vçlaties programmu izpildît vçlreiz? (jâ=1 un nç=0)" << endl;
cin >> ok;
}while (ok==1);
}
