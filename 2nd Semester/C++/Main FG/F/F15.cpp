/**
F15. Dots teksta fails, kur� atrodas sintaktiski pareizs C++ programmas teksts.
Uzrakst�t programmu, kura saskaita, cik da��du bibliot�ku (#include) iek�auts dotaj�
programm�. Dr�kst uzskat�t, ka programmas tekst� nav koment�ru un ka attiec�gie simboli
nepar�d�sies teksta liter��os.
**/
#include <iostream>
#include <fstream>
#include "lvfriendly.h"
using namespace std;

int main()
{
    fstream fin;
    string rin;
    int counter = 0;      //Bibliot�ku skait�t�js

    fin.open ("f.txt", ios::in);    //Atver ievades failu
    getline(fin, rin);              //Ieg�st faila pirmo rindi�u

    cout << "Izmantot�s bibliot�kas: " <<endl;
    cout<<endl;

    //Sec�ga faila nolas��ana par rindi��m
    while(fin)
    {
        //For cikls, kur� p�rstaig� katru rindi�as simbolu
        for(int i = 0; i<rin.size();i++)
        {
            //Ja tiek sastapts # tad tiek izvad�ta rindi�a un skait�t�jam tiek piestkait�ts kl�t vieninieks
            if (rin[i]=='#')
            {
                cout <<rin;
                counter++;
                cout << endl;
            }
        }
        getline(fin, rin); //Ieg�st n�kamo faila teksta rindi�u
    }
    cout << endl;
    cout << "Kop� tika izmantotas " << counter << " bibliotek�s" << endl;

    fin.close(); //Aizver ievades failu

    return 0;
}
