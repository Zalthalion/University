/**
F15. Dots teksta fails, kurâ atrodas sintaktiski pareizs C++ programmas teksts.
Uzrakstît programmu, kura saskaita, cik daþâdu bibliotçku (#include) iekïauts dotajâ
programmâ. Drîkst uzskatît, ka programmas tekstâ nav komentâru un ka attiecîgie simboli
neparâdîsies teksta literâïos.
**/
#include <iostream>
#include <fstream>
#include "lvfriendly.h"
using namespace std;

int main()
{
    fstream fin;
    string rin;
    int counter = 0;      //Bibliotçku skaitîtâjs

    fin.open ("f.txt", ios::in);    //Atver ievades failu
    getline(fin, rin);              //Iegûst faila pirmo rindiòu

    cout << "Izmantotâs bibliotçkas: " <<endl;
    cout<<endl;

    //Secîga faila nolasîðana par rindiòâm
    while(fin)
    {
        //For cikls, kurð pârstaigâ katru rindiòas simbolu
        for(int i = 0; i<rin.size();i++)
        {
            //Ja tiek sastapts # tad tiek izvadîta rindiòa un skaitîtâjam tiek piestkaitîts klât vieninieks
            if (rin[i]=='#')
            {
                cout <<rin;
                counter++;
                cout << endl;
            }
        }
        getline(fin, rin); //Iegûst nâkamo faila teksta rindiòu
    }
    cout << endl;
    cout << "Kopâ tika izmantotas " << counter << " bibliotekâs" << endl;

    fin.close(); //Aizver ievades failu

    return 0;
}
