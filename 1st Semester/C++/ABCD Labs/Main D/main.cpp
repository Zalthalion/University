/********************
D1. Izveidot klasi ""Komplekss skaitlis"", kurâ tiek glabâti divi
skaitïi, kas nosaka kompleksu skaitli. Klasei izveidot ðâdas metodes:
(1) konstruktors, ar kuru tiek padotas sâkotnçjâs vçrtîbas,
(2) destruktors, kurð paziòo par objekta likvidçðanu,
(3) metode ""Pieskaitît"" ar diviem parametriem, kas (savam) kompleksajam skaitlim
pieskaita otru (kas padots ar parametriem) kompleksu skaitli un
rezultâtu noglabâ pie sevis,
(4) metode ""Reizinât"" – ar diviem parametriem, kas sareizina kompleksus skaitïus,
(5) metode ""Drukât"", kas izdrukâ komplekso skaitli.
********************/
//programmas autors: Juris Freidenfelds (jf18017)
//programma radîta: 26.12.2018
#include<iostream>
#include"program.cpp"

using namespace std;
int main(){

int n, n1, n2, i, i1, i2;
int ok;
Kompleksais_skaitlis* skaitlis;
do{
cout<<"Ievadi kompleksâ skaitïa reâlo daïu!"<<endl;
cin>>n;
cout<<"Ievadi kompleksâ skaitïa imaginâro daïu!"<<endl;
cin>>i;
skaitlis = new Kompleksais_skaitlis (n, i);//dinamiski, jo man tâ liekas elastîgâka metode
skaitlis->drukat();//metodes izsauc ar "->", nevis ".", jo dinamisks objekts
cout<<"Ievadi reâlo daïu kompleksajam skaitlim, ko pieskaitîsi dotajam skaitlim!"<<endl;
cin>>n1;
cout<<"Ievadi imaginâro daïu kompleksajam skaitlim, ko pieskaitîsi dotajam skaitlim!"<<endl;
cin>>i1;
skaitlis->pieskaitit (n1,i1);
skaitlis->drukat();
cout<<"Ievadi reâlo daïu kompleksajam skaitlim, ar kuru reizinâsi doto skaitli!"<<endl;
cin>>n2;
cout<<"Ievadi imaginâro daïu kompleksajam skaitlim, ar kuru reizinâsi doto skaitli!"<<endl;
cin>>i2;
skaitlis->reizinat (n2,i2);
skaitlis->drukat();
cout<<"Vai turpinât (1) vai beigt (0)?"<<endl;
cin>>ok;
}while(ok==1);
return 0;
}
/************Testu Plâns************
Ievade              Ievade
n = 2;              n = 3;
i = 2;              i = 8;
n1 = -1;            n1 = 1;
i1 = 1;             i1 = 2;
n2 = 4;             n2 = -7;
i2 = -2;            i2 = 3;

Rezultâts           Rezultâts
10+10i              -58-58i
************************************/

