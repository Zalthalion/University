#include <iostream>
#include "lvfriendly.h" //Atbalsta latvie�u burtu ievadi un izvadi
using namespace std;

int main()
{
    int sk1, sk2;
    int cip1, cip2;
    int ok;

do{
    int cipSum1 = 0, cipSum2 = 0;
    int cipSumStarp = 0;

do{                                         //Do while cikls, kur� �auj izpild�t programmu v�lreiz
cout << "Ievadi pirmo skaitli: ";           //Pirm� skait�a ievade
cin >>sk1;
if(sk1<0) cout << "Skaitlim ir j�b�t liel�kam par 0!" << endl;      //Datu p�rbaude: Skaitlim ir j�b�t nautur�lam
}while (sk1<0);
cout << endl;
do{
cout << "Ievadi otro skaitli: ";            //Otr� skait�a ievade
cin >>sk2;
if(sk2<0) cout << "Skaitlim ir j�b�t liel�kam par 0!" << endl;      //Datu p�rbaude: Skaitlim ir j�b�t natur�lam
}while (sk2<0);
cout << endl << endl;

do{                     //Do while cikls, kur� saskaita skait�a ciparus kop�
    cip1 = sk1%10;
    cipSum1 = cipSum1 + cip1;
    sk1 = sk1 / 10;
}while (sk1>0);

do{                     //Do while cikls, kur� saskaita skait�a ciparus kop�
    cip2 = sk2%10;
    cipSum2 = cipSum2 + cip2;
    sk2 = sk2 / 10;
}while (sk2>0);

cipSumStarp = cipSum1 - cipSum2;


cout << "Ievad�to skait�u ciparu summas starp�ba ir: " << cipSumStarp << endl;

cout << "Vai v�laties programmu izmantot v�lreiz? (J� = 1 un N� = 0)" << endl;
cin >> ok;
}while (ok==1);
return 0;
}

/******Testu pl�ns******
sk1        sk2      gaid�mais rezult�ts
1234        123     4
123         1234    -4
***********************/
