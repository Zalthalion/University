#include <iostream>
#include "lvfriendly.h" //Atbalsta latvieðu burtu ievadi un izvadi
using namespace std;

int main()
{
    int sk1, sk2;
    int cip1, cip2;
    int ok;

do{
    int cipSum1 = 0, cipSum2 = 0;
    int cipSumStarp = 0;

do{                                         //Do while cikls, kurð ïauj izpildît programmu vçlreiz
cout << "Ievadi pirmo skaitli: ";           //Pirmâ skaitïa ievade
cin >>sk1;
if(sk1<0) cout << "Skaitlim ir jâbût lielâkam par 0!" << endl;      //Datu pârbaude: Skaitlim ir jâbût nauturâlam
}while (sk1<0);
cout << endl;
do{
cout << "Ievadi otro skaitli: ";            //Otrâ skaitïa ievade
cin >>sk2;
if(sk2<0) cout << "Skaitlim ir jâbût lielâkam par 0!" << endl;      //Datu pârbaude: Skaitlim ir jâbût naturâlam
}while (sk2<0);
cout << endl << endl;

do{                     //Do while cikls, kurð saskaita skaitïa ciparus kopâ
    cip1 = sk1%10;
    cipSum1 = cipSum1 + cip1;
    sk1 = sk1 / 10;
}while (sk1>0);

do{                     //Do while cikls, kurð saskaita skaitïa ciparus kopâ
    cip2 = sk2%10;
    cipSum2 = cipSum2 + cip2;
    sk2 = sk2 / 10;
}while (sk2>0);

cipSumStarp = cipSum1 - cipSum2;


cout << "Ievadîto skaitïu ciparu summas starpîba ir: " << cipSumStarp << endl;

cout << "Vai vçlaties programmu izmantot vçlreiz? (Jâ = 1 un Nç = 0)" << endl;
cin >> ok;
}while (ok==1);
return 0;
}

/******Testu plâns******
sk1        sk2      gaidâmais rezultâts
1234        123     4
123         1234    -4
***********************/
