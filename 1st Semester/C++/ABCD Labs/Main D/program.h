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
