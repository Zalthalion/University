/********************************************************************
C1. Virkni a(1..n) sauc par monotonu, ja a(1)<=a(2)<=...<=a(n) vai
a(1)>=a(2)>=...>=a(n). Dots veselu skaitïu masîvs A(m). Noskaidrot
garâko tajâ sastopamo monotono virkni. Izveidot un izmantot funkciju,
kas nosaka masîvâ sastopamâs monotonas virknes garumu, sâkot no elementa
ar indeksu i.
Autors: Juris Freidenfelds
Radîta: 21.11.2018.
*************************************************************************/

#include<iostream>
#include"lvfriendly.h"
using namespace std;
//Rekursîva funkcija monoDilst, kura noskaidro cik gara ir dilstoða monotonitâte sâkot ar indeksu i
int monoDilst(int i, int *virkne){
if (virkne[i]<virkne[i+1]) return 1;
if(virkne[i]>=virkne[i+1]){
    return 1+monoDilst(i+1, virkne);
}
}
//Rekursîva funkcija monoAug, kura noskaidro cik gara ir augoða monotonitâte sâkot ar indeksu i
int monoAug(int i, int *virkne){
if (virkne[i] > virkne[i+1]) return 1;
if (virkne[i]<=virkne[i+1]){
    return 1+monoAug(i+1, virkne);
}
}

int main(){
int *virkne;    //Dinamisks masîvs
int vg;         //Virknes garums
int i;          //Virknes locekïa indekss
int rez1, rez2; //funkciju rezultâts
int ok;         //Lietotâja atbilde 1 - lietot programmu vçlreiz, 0 - beigt programmu
//Do while cikls, kurð atïauj programmu izpildît vairâkas reizes, neizejot no programmas
do{
int maksMono = 1; // Pieðíirtâ garâkâ monotonitâte
//Korektu datu ievade. Virknes garumam ir jâbût vismaz 2, lai bûtu izmçrâma monotonitâte
do{
cout << "Ievadi virknes garumu! (Virknes garumam ir jâbût lielâkam par 1) " << endl;
cin >> vg;
if(vg<2) cout << "Virknes garumam ir jâbût leilâkam par 1, ievadi pareizus datus" << endl;
}while (vg<2);

virkne = new int[vg]; //Pieðíir masîvam jaunu izmçru

//Masîva aizpildîðana ar for ciklu
cout << "Ievadi skaitïu virkni!" << endl << endl;
for(int j = 0; j<vg; j++){
    cout << "Ievadi virknes " << j+1 << " locekli" << endl;
    cin >> virkne[j];}
//For cikls, kas nosaka virknes monotonitâtes garumu, sâkot ar indeksu s
for(int s = 0; s<vg; s++){

    rez1 = monoAug(s, virkne);      //Izmçra augoðas monotonitâtes garumu
    rez2 = monoDilst(s, virkne);    //Izmçra dilstoðas monotonitâtes garumu

    if(rez1>maksMono){
    maksMono=rez1;
    i = s;}

    if(rez2>maksMono){
    maksMono = rez2;
    i = s;}
}
//Rezultâta izdrukâðana
cout << "Garâkâ sastopamâ monotomitâte sâkâs ar indeksu I =  "<< i+1 <<" Un tâs garums ir: "<< maksMono << endl;

delete[] virkne; //Izdzçð masîva aizòemto vietu

//Piedâvâ lietotâjam izpildît programmu vçlreiz
cout << "Vai vçlaties izmantot programmu vçlreiz? (Jâ = 1 un Nç = 0)" << endl;
cin >>ok;
}while(ok==1);
}
