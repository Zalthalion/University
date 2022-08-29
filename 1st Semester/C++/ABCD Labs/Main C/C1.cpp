/********************************************************************
C1. Virkni a(1..n) sauc par monotonu, ja a(1)<=a(2)<=...<=a(n) vai
a(1)>=a(2)>=...>=a(n). Dots veselu skait�u mas�vs A(m). Noskaidrot
gar�ko taj� sastopamo monotono virkni. Izveidot un izmantot funkciju,
kas nosaka mas�v� sastopam�s monotonas virknes garumu, s�kot no elementa
ar indeksu i.
Autors: Juris Freidenfelds
Rad�ta: 21.11.2018.
*************************************************************************/

#include<iostream>
#include"lvfriendly.h"
using namespace std;
//Rekurs�va funkcija monoDilst, kura noskaidro cik gara ir dilsto�a monotonit�te s�kot ar indeksu i
int monoDilst(int i, int *virkne){
if (virkne[i]<virkne[i+1]) return 1;
if(virkne[i]>=virkne[i+1]){
    return 1+monoDilst(i+1, virkne);
}
}
//Rekurs�va funkcija monoAug, kura noskaidro cik gara ir augo�a monotonit�te s�kot ar indeksu i
int monoAug(int i, int *virkne){
if (virkne[i] > virkne[i+1]) return 1;
if (virkne[i]<=virkne[i+1]){
    return 1+monoAug(i+1, virkne);
}
}

int main(){
int *virkne;    //Dinamisks mas�vs
int vg;         //Virknes garums
int i;          //Virknes locek�a indekss
int rez1, rez2; //funkciju rezult�ts
int ok;         //Lietot�ja atbilde 1 - lietot programmu v�lreiz, 0 - beigt programmu
//Do while cikls, kur� at�auj programmu izpild�t vair�kas reizes, neizejot no programmas
do{
int maksMono = 1; // Pie��irt� gar�k� monotonit�te
//Korektu datu ievade. Virknes garumam ir j�b�t vismaz 2, lai b�tu izm�r�ma monotonit�te
do{
cout << "Ievadi virknes garumu! (Virknes garumam ir j�b�t liel�kam par 1) " << endl;
cin >> vg;
if(vg<2) cout << "Virknes garumam ir j�b�t leil�kam par 1, ievadi pareizus datus" << endl;
}while (vg<2);

virkne = new int[vg]; //Pie��ir mas�vam jaunu izm�ru

//Mas�va aizpild��ana ar for ciklu
cout << "Ievadi skait�u virkni!" << endl << endl;
for(int j = 0; j<vg; j++){
    cout << "Ievadi virknes " << j+1 << " locekli" << endl;
    cin >> virkne[j];}
//For cikls, kas nosaka virknes monotonit�tes garumu, s�kot ar indeksu s
for(int s = 0; s<vg; s++){

    rez1 = monoAug(s, virkne);      //Izm�ra augo�as monotonit�tes garumu
    rez2 = monoDilst(s, virkne);    //Izm�ra dilsto�as monotonit�tes garumu

    if(rez1>maksMono){
    maksMono=rez1;
    i = s;}

    if(rez2>maksMono){
    maksMono = rez2;
    i = s;}
}
//Rezult�ta izdruk��ana
cout << "Gar�k� sastopam� monotomit�te s�k�s ar indeksu I =  "<< i+1 <<" Un t�s garums ir: "<< maksMono << endl;

delete[] virkne; //Izdz�� mas�va aiz�emto vietu

//Pied�v� lietot�jam izpild�t programmu v�lreiz
cout << "Vai v�laties izmantot programmu v�lreiz? (J� = 1 un N� = 0)" << endl;
cin >>ok;
}while(ok==1);
}
