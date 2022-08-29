/************************************************************
Izveidot programmu valod� C++, kas apstr�d� teksta failu sec�g� re��m�.
Dati no faila j�nolasa pa vienai rindi�ai. Nedr�kst dubl�t visa faila
saturu operat�vaj� atmi��. S�k�kas pras�bas sk. Laboratorijas darbu
noteikumos.

F19. Izvad�t dotaj� teksta fail� f sastapto lat��u alfab�ta burtu un
ciparu lietojuma bie�uma tabulu (��irojot lielos un mazos burtus) fail�
f1. Tabulai j�b�t sak�rtotai p�c burtu lietojuma bie�uma.

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
    string rin;             // No faila nolas�t� rindi�a
    int biezumi[256] = {0}; // Simbola ar kodu i bie�ums ir elementa biezumi[i] v�rt�ba


    fin.open ("f.txt", ios::in);                  // Atver ievades failu
    if (!fin){cout << "Nav faila"<< endl; return 13;} //P�rbaude, vai visp�r fails eksist�

    getline(fin, rin); // ieg�st dokumenta pirmo rindi�u
    while (fin) //while cikls, kur� izpild�sies l�dz tiks sasniegts dokumenta beigu simbols
    {
    for(int i=0;i<rin.size();i++) // for cikls, kur� p�rbauda katru simbolu no rindi�as
     biezumi[(unsigned char) rin[i]]++;// Lai indekss b�tu 0-255
    getline(fin, rin);  //ieg�st n�kamo teksta rindi�u
    };
    fin.close();        //aizver ievades failu

    fout.open ("f1.txt", ios::out); //atver izvades dokumentu

    for (int j = 1; j <50; j++){   //for cikls kur� iziet cauri ASCII tabulas simboliem
      for(int i = 0; i<256; i++){  //
            if(((isalpha((unsigned char)i)) == 0) && (isdigit((unsigned char)i)) == 0) continue; //"siets", kur� izsij� tikai burtus un ciparus
    else{
        if(biezumi[i]==j){
         fout << setw(5)<< biezumi[i]  << " reizes sastopams simbols: |" <<setw(3) << (char)i << endl; // Izdruka
         fout << "--------------------------------------------" << endl;
      }}}}
    fout.close();   // aizver izvades dokumentu
    cout << "Dar�ts!" << endl;
    return 0;
}


/****** Testu pl�ns *************************************
fails                   gaid�mais rezult�ta fails
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
