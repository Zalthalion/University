/*************************************************************************
B1. Dots natur�ls skaitis n. Atrast visus t�dus natur�lu skait�u p�r��us
a un b, kuri nep�rsniedz n, lai a b�tu  vien�ds ar visu b dal�t�ju summu
(iz�emot b), un b b�tu vien�ds ar visu a dal�t�ju summu (iz�emot a).
Risin�jum� izmantot funkciju, kas atpaz�st pirmskait�us.
*************************************************************************/
// Autors: Juris Freidenfelds
// Rad�ta 30.10.2018.

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

// funkcija dalSum(n), kura izr��ina skait�a dal�t�ju summu
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
    int n;      // Ievad�tais skaitlis
    int asum, bsum; // skait�a dal�t�ju summa
    int a, b;   // Rezult�ts
    int ok;     // Lietot�ja atbilde 1 - lietot programmu v�lreiz 2 - beigt programmu
// Cikls, kur� at�auj veikt atk�rtotu programmas lieto�anu.
do{
    cout << "Programma, kura atrod visus t�dus natur�lu skait�u p�rus a un b, kuri nep�rsniedz n,  lai a b�t vien�ds ar ar visu b dal�t�ju summu) iz�emot b),  un b b�tu vien�ds ar visu a  dal�t�ju summu (iz�emot a)." << endl;
    cout << endl;
//Tiek veikta korekta skait�a "n" ievade (Skaitlim ir j�b�t natur�lam)
    do{
    cout << "Ievadiet l�dzu natur�lu skaitli! (n)" << endl;
    cin >> n;
    cout << endl;
    if (n<=1) cout << "Skaitlim ir j�b�t liel�kam par 1!" << endl;
    }while (n<=1);
if (n<7) cout << "Nav t�du p�r��u" << endl;
for(a=0; a<n; a++){
    if (a == vaiIrPirmsk(a)) continue;
//p�rbauda vai dal�t�ju summa ir pirmsskaitlis
    if(vaiIrPirmsk(dalSum(a))==true)continue;
    asum = dalSum(a);
    for(b=0; b<n; b++){
        if (b == vaiIrPirmsk(b)) continue;
//p�rbauda vai dal�t�ju summa ir pirmsskaitlis
        if(vaiIrPirmsk(dalSum(b))==true)continue;
        bsum = dalSum(b);
        if (a == bsum && b == asum)
        cout << a  << " un " << b << endl;}} //Rezult�tu izdruk�
cout << endl;
cout << "Vai v�laties programmu izmantot v�lreiz? (J� = 1 un N� = 0)" << endl;
cin >> ok;
}while (ok==1);
}
/*******************Testu pl�ns ***********************
Ievad�tais skaitlis         gaid�mais rezult�ts
        n                           a un b

        5                           Nav t�du p�r��u
        10                          6 un 6
        50                          6 un 6; 28 un 28
******************************************************/






