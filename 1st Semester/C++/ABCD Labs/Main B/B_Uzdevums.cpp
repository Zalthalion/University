/*************************************************************************
B1. Dots naturâls skaitis n. Atrast visus tâdus naturâlu skaitïu pârîðus
a un b, kuri nepârsniedz n, lai a bûtu  vienâds ar visu b dalîtâju summu
(izòemot b), un b bûtu vienâds ar visu a dalîtâju summu (izòemot a).
Risinâjumâ izmantot funkciju, kas atpazîst pirmskaitïus.
*************************************************************************/
// Autors: Juris Freidenfelds
// Radîta 30.10.2018.

#include<iostream>
#include "lvfriendly.h"
using namespace std;

// Funkcija vaiIrPirmsk(i), kas nosaka vai skaitlis ir pirmskaitlis
int vaiIrPirmsk (int i){
bool b1;
int vd, dali = 1;
int daliSk = 0;
    do{vd=i%dali;
    if(vd==0) daliSk++;
    dali++;
    }while (dali <= i);
    b1 = daliSk == 2;
    return b1 ;
}

// funkcija dalSum(n), kura izrçíina skaitïa dalîtâju summu
int dalSum(int n)
{
int summa = 0;
    for(int i = 1; i < n; i++)
    {
        if(n % i == 0) summa = summa + i;
    }
    return summa;
}

int main(){
    int n;      // Ievadîtais skaitlis
    int asum, bsum; // skaitïa dalîtâju summa
    int a, b;   // Rezultâts
    int ok;     // Lietotâja atbilde 1 - lietot programmu vçlreiz 2 - beigt programmu
// Cikls, kurð atïauj veikt atkârtotu programmas lietoðanu.
do{
    cout << "Programma, kura atrod visus tâdus naturâlu skaitïu pârus a un b, kuri nepârsniedz n,  lai a bût vienâds ar ar visu b dalîtâju summu) izòemot b),  un b bûtu vienâds ar visu a  dalîtâju summu (izòemot a)." << endl;
    cout << endl;
//Tiek veikta korekta skaitïa "n" ievade (Skaitlim ir jâbût naturâlam)
    do{
    cout << "Ievadiet lûdzu naturâlu skaitli! (n)" << endl;
    cin >> n;
    cout << endl;
    if (n<=1) cout << "Skaitlim ir jâbût lielâkam par 1!" << endl;
    }while (n<=1);
if (n<7) cout << "Nav tâdu pârîðu" << endl;
for(a=0; a<n; a++){
    if (a == vaiIrPirmsk(a)) continue;
//pârbauda vai dalîtâju summa ir pirmsskaitlis
    if(vaiIrPirmsk(dalSum(a))==true)continue;
    asum = dalSum(a);
    for(b=0; b<n; b++){
        if (b == vaiIrPirmsk(b)) continue;
//pârbauda vai dalîtâju summa ir pirmsskaitlis
        if(vaiIrPirmsk(dalSum(b))==true)continue;
        bsum = dalSum(b);
        if (a == bsum && b == asum)
        cout << a  << " un " << b << endl;}} //Rezultâtu izdrukâ
cout << endl;
cout << "Vai vçlaties programmu izmantot vçlreiz? (Jâ = 1 un Nç = 0)" << endl;
cin >> ok;
}while (ok==1);
}
/*******************Testu plâns ***********************
Ievadîtais skaitlis         gaidâmais rezultâts
        n                           a un b

        5                           Nav tâdu pârîðu
        10                          6 un 6
        50                          6 un 6; 28 un 28
******************************************************/






