/************************************************************
Izveidot programmu valodâ C++, kas apstrâdâ teksta failu secîgâ reþîmâ.
Dati no faila jânolasa pa vienai rindiòai. Nedrîkst dublçt visa faila
saturu operatîvajâ atmiòâ. Sîkâkas prasîbas sk. Laboratorijas darbu
noteikumos.

F19. Izvadît dotajâ teksta failâ f sastapto latîòu alfabçta burtu un
ciparu lietojuma bieþuma tabulu (ðíirojot lielos un mazos burtus) failâ
f1. Tabulai jâbût sakârtotai pçc burtu lietojuma bieþuma.

Programmu izveidoja: Juris Freidenfelds (jf18017)
Programma izveidota: 25.02.2019
************************************************************/
#include <fstream>
#include <iostream>
#include "lvfriendly.h"
#include <iomanip>
#include <ctype.h>
using namespace std;

int main()
{
    fstream fin;
    fstream fout;
    string rin;             // No faila nolasîtâ rindiòa
    int biezumi[256] = {0}; // Simbola ar kodu i bieþums ir elementa biezumi[i] vçrtîba


    fin.open ("f.txt", ios::in);                  // Atver ievades failu
    if (!fin){cout << "Nav faila"<< endl; return 13;} //Pârbaude, vai vispâr fails eksistç

    getline(fin, rin); // iegûst dokumenta pirmo rindiòu
    while (fin) //while cikls, kurð izpildîsies lîdz tiks sasniegts dokumenta beigu simbols
    {
    for(int i=0;i<rin.size();i++) // for cikls, kurð pârbauda katru simbolu no rindiòas
     biezumi[(unsigned char) rin[i]]++;// Lai indekss bûtu 0-255
    getline(fin, rin);  //iegûst nâkamo teksta rindiòu
    };
    fin.close();        //aizver ievades failu

    fout.open ("f1.txt", ios::out); //atver izvades dokumentu

    for (int j = 1; j <50; j++){   //for cikls kurð iziet cauri ASCII tabulas simboliem
      for(int i = 0; i<256; i++){  //
            if(((isalpha((unsigned char)i)) == 0) && (isdigit((unsigned char)i)) == 0) continue; //"siets", kurð izsijâ tikai burtus un ciparus
    else{
        if(biezumi[i]==j){
         fout << setw(5)<< biezumi[i]  << " reizes sastopams simbols: |" <<setw(3) << (char)i << endl; // Izdruka
         fout << "--------------------------------------------" << endl;
      }}}}
    fout.close();   // aizver izvades dokumentu
    cout << "Darîts!" << endl;
    return 0;
}


/****** Testu plâns *************************************
fails                   gaidâmais rezultâta fails
f1                      1 reizi         l
1 A a b , ,             1 reizi         b
a cc AA                 2 reizes        c
dedf ad ZZ              2 reizes        Z
111 232 432             2 reizes        4
 2313 432               3 reizes        a
 ///                    3 reizes        A
                        3 reizes        d
                        4 reizes        1
                        5 reizes        2
                        5 reizes        3
********************************************************/
