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
using namespace std;

class Kompleksais_skaitlis{
int n;
int i;
public:
Kompleksais_skaitlis (int n, int i);
~Kompleksais_skaitlis();
void pieskaitit(int a, int b);
void reizinat(int x, int y);
void drukat();
};
