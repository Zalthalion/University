/*******************************************************************************
Izveidot programmu valodâ C++, kas apstrâdâ teksta failu secîgâ reþîmâ.
Dati no faila jânolasa pa vienai rindiòai. Nedrîkst dublçt visa faila saturu
operatîvajâ atmiòâ. Sîkâkas prasîbas sk. Laboratorijas darbu noteikumos.

F6. Dots teksta fails, kurâ atrodas sintaktiski pareizs C++ programmas teksts.
Sastâdît programmu, kura failâ izvada visus dotâs programmas komentârus.
Drîkst pieòemt, ka teksta literâïos neparâdîsies komentâru sâkuma vai beigu
apzîmçjuma simboli.
*******************************************************************************/

#include <fstream>
#include <iostream>
#include "lvfriendly.h"
using namespace std;

int main()
{
    fstream fin;
    fstream fout;
    string rin;

    fin.open ("f.txt", ios::in);                        //Atver ievades failu
    fout.open ("fout.txt", ios::out);                   //Atver izvades failu
    if (!fin){cout << "Nav faila"<< endl; return 13;}   //Pârbauda vai ievades fails eksistç

    getline(fin, rin);                                  //Iegûst faila pirmo rindiòu

    //Secîga faila nolasîðana pa rindiòâm
    while (fin)
    {
        //for cikls, kurð pârstaigâ rindiòas katru simbolu
        for(int i=0;i<rin.size();i++)
        {

            /************* Single line komentâri ******************/

            //Ja tiek sastapti simboli '/' un '/' vai '/' un '*' pçc kârtas...
            if(rin[i]=='/'&&rin[i+1]=='/'&&rin[i+1])
            {
                    int j = i;
                    //...tad tiek palaists izdrukas cikls, kurð izdrukâ tekstu lîdz rindiòas beigâm
                    while (1)
                {
                    fout<<rin[j];
                    j++;
                    if(rin[j]=='\n'||rin[j]==fin.eof())break;
                }
                fout << endl <<endl;
            }
            else
            /************* Multi line komentâri ******************/

            if(rin[i]=='/'&&rin[i+1]=='*')
            {
                //Ja tiek sastapti simboli '/' un '*' pçc kârtas...
                int j = i;

                    //...tad tiek palaists izdrukas cikls, kurð izdrukâ tekstu lîdz komentâra beigu simbolam '/'
                    while (1)
                    {
                        if(rin.empty()){fout<<endl; getline(fin, rin); j=0;}
                        fout<<rin[j];
                        j++;
                        if(rin[j]=='\n'||rin[j]==fin.eof()){fout<<endl;getline(fin, rin);j=0;}
                        if(rin[j]=='/'){fout << rin[j]; break;}
                    }
                    fout << endl<<endl;
            }
        }
    getline(fin, rin);     //Iegûst nâkamo faila rindiòu
    }
    fout.close();       //Aizver izvades failu
    fin.close();        //Aizver ievades failu
    cout << "Darîts!";
    return 0;
}



