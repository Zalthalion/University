/********************
D1. Izveidot klasi ""Komplekss skaitlis"", kur� tiek glab�ti divi
skait�i, kas nosaka kompleksu skaitli. Klasei izveidot ��das metodes:
(1) konstruktors, ar kuru tiek padotas s�kotn�j�s v�rt�bas,
(2) destruktors, kur� pazi�o par objekta likvid��anu,
(3) metode ""Pieskait�t"" ar diviem parametriem, kas (savam) kompleksajam skaitlim
pieskaita otru (kas padots ar parametriem) kompleksu skaitli un
rezult�tu noglab� pie sevis,
(4) metode ""Reizin�t"" � ar diviem parametriem, kas sareizina kompleksus skait�us,
(5) metode ""Druk�t"", kas izdruk� komplekso skaitli.
********************/
//programmas autors: Juris Freidenfelds (jf18017)
//programma rad�ta: 26.12.2018
#include<iostream>
#include"program.cpp"

using namespace std;
int main(){

int n, n1, n2, i, i1, i2;
int ok;
Kompleksais_skaitlis* skaitlis;
do{
cout<<"Ievadi kompleks� skait�a re�lo da�u!"<<endl;
cin>>n;
cout<<"Ievadi kompleks� skait�a imagin�ro da�u!"<<endl;
cin>>i;
skaitlis = new Kompleksais_skaitlis (n, i);//dinamiski, jo man t� liekas elast�g�ka metode
skaitlis->drukat();//metodes izsauc ar "->", nevis ".", jo dinamisks objekts
cout<<"Ievadi re�lo da�u kompleksajam skaitlim, ko pieskait�si dotajam skaitlim!"<<endl;
cin>>n1;
cout<<"Ievadi imagin�ro da�u kompleksajam skaitlim, ko pieskait�si dotajam skaitlim!"<<endl;
cin>>i1;
skaitlis->pieskaitit (n1,i1);
skaitlis->drukat();
cout<<"Ievadi re�lo da�u kompleksajam skaitlim, ar kuru reizin�si doto skaitli!"<<endl;
cin>>n2;
cout<<"Ievadi imagin�ro da�u kompleksajam skaitlim, ar kuru reizin�si doto skaitli!"<<endl;
cin>>i2;
skaitlis->reizinat (n2,i2);
skaitlis->drukat();
cout<<"Vai turpin�t (1) vai beigt (0)?"<<endl;
cin>>ok;
}while(ok==1);
return 0;
}
/************Testu Pl�ns************
Ievade              Ievade
n = 2;              n = 3;
i = 2;              i = 8;
n1 = -1;            n1 = 1;
i1 = 1;             i1 = 2;
n2 = 4;             n2 = -7;
i2 = -2;            i2 = 3;

Rezult�ts           Rezult�ts
10+10i              -58-58i
************************************/

