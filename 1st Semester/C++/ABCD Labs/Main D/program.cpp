//program.cpp fails
#include<iostream>
#include"program.h"
#include"lvtocon.h"
#include"lvtocon.cpp"
using namespace std;

Kompleksais_skaitlis::Kompleksais_skaitlis(int n, int i)
{
this ->n=n;
this ->i=i;
}

Kompleksais_skaitlis::~Kompleksais_skaitlis(){
cout<<"Objekts tiek livid�ts"<<endl;
}

void Kompleksais_skaitlis:: pieskaitit(int a, int b){
n+=a;
i+=b;
}

void Kompleksais_skaitlis:: reizinat (int x, int y){
int imm =n*y;//sareizina dot� skait�a re�lo da�u ar jaun� skait�a imagin�ro, ieg�st imagin�ro, ko pieskaita gala imagin�rajam rezult�tam
int imq =i*y;//sareizinot dot� skait�a imagin�ro ar jaun� skait�a imagin�ro, ieg�st skitli reiz imagin�rais kvadr�t�, imagin�rais kvadr�t�=-1, t�p�c ieg�to skaitli pareizina ar -1 (ieg�st re�lu skaitli) un pieskaita (at�em) no gala re�l� rezult�ta
n=n*x;//sareizina dot� skait�a un jaun� skait�a re�l�s da�as, ieg�st re�lu skaitli
i=i*x;//sareizina dot� skait�a imagin�ro da�u ar jaun� skait�a re�lo, ieg�st imagin�ru skaitli
n=n-imq;//gal�j� rezult�ta re�l� da�a
i=i+imm;//gal�j� rezult�ta imagin�r� da�a
}

void Kompleksais_skaitlis::drukat(){
cout<<"Kompleksais skaitlis: "<<n<<"+("<<i<<"i)"<<endl;
}
