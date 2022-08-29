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
cout<<"Objekts tiek lividçts"<<endl;
}

void Kompleksais_skaitlis:: pieskaitit(int a, int b){
n+=a;
i+=b;
}

void Kompleksais_skaitlis:: reizinat (int x, int y){
int imm =n*y;//sareizina dotâ skaitïa reâlo daïu ar jaunâ skaitïa imaginâro, iegûst imaginâro, ko pieskaita gala imaginârajam rezultâtam
int imq =i*y;//sareizinot dotâ skaitïa imaginâro ar jaunâ skaitïa imaginâro, iegûst skitli reiz imaginârais kvadrâtâ, imaginârais kvadrâtâ=-1, tâpçc iegûto skaitli pareizina ar -1 (iegûst reâlu skaitli) un pieskaita (atòem) no gala reâlâ rezultâta
n=n*x;//sareizina dotâ skaitïa un jaunâ skaitïa reâlâs daïas, iegûst reâlu skaitli
i=i*x;//sareizina dotâ skaitïa imaginâro daïu ar jaunâ skaitïa reâlo, iegûst imaginâru skaitli
n=n-imq;//galçjâ rezultâta reâlâ daïa
i=i+imm;//galçjâ rezultâta imaginârâ daïa
}

void Kompleksais_skaitlis::drukat(){
cout<<"Kompleksais skaitlis: "<<n<<"+("<<i<<"i)"<<endl;
}
