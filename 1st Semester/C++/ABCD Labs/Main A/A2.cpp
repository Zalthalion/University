#include<iostream>
using namespace std;

//funkcija kas nosaka cik ciparu ir skaitlii lai uzzinaatu cik liels masiivs ir jaaizveido
int cikCip(int a){
int cipSk = 0;
do{
    if(a>0)cipSk++;
        a=a/10;
}while(a>0);
return cipSk;
}

int main(){
int* skaitlis;          //dinamisks masiivs prieks ievadiitaa skaitla
int* otrsSkaitlis;      //dinamisks masiivs prieks apstradata skaitla
int n;                  // ievadiitais skaitlis
cin >> n;               //skaitla ievade
int cip = cikCip(n);    //palaiz funkciju, kas rezultata atgriez cik ciparu ir skaitli, ko velaak izmantosim ka masiiva izmeeru
skaitlis = new int[cip];    //pieskiram masivam izmeru
otrsSkaitlis = new int [cip];   //otram masiivam izvelamies taadu pasu izmeru jo skaitlis nemaina garumu (iznemot nulles gadiijumaa)
for (int c = 0; c<cip; c++){    //for cikls kurð aipilda pirmâ skaitïa masîvu
    skaitlis[c] = n%10;         //Cikls aizpilda masîvu otrâdi ja ir 12345 tad otrs masîvs ir 54321
    n = n/10;}
otrsSkaitlis[0] = skaitlis[0];      //pieðíiram masîva 0tajam elementam ievadîtâ skaitïa 0to elementu
otrsSkaitlis[cip-1] = skaitlis[cip-1]; //Pieðíiram masîva pçdçjam elementam ievadîtâ skaitïa pçdçjo elementu

for (int b = 1; b<cip-1; b++){                  //aizpildâm masîvu starp 0to un pçdçjo elementu ar pirmâ masîva elementiem
    otrsSkaitlis[b] = skaitlis[cip-b-1];
}

for(int i=0; i<cip; i++){               //masîva izdruka
    cout << otrsSkaitlis[i];
}

delete[] skaitlis;
delete[] otrsSkaitlis; //izdzçð masîva aizòemtâs vietas
return 0;
}
