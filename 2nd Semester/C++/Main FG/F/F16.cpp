/**
F16. Dots teksta fails, kurâ atrodas sintaktiski pareizs C++ programmas teksts.
Saskaitît, cik salîdzinâðanas operatoru (==, !=, <=, >=) satur dotâ programma.
Drîkst uzskatît, ka programmas tekstâ nav komentâru un ka attiecîgie simboli
neparâdîsies teksta literâïos.
**/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fin;
    string rin;
    int counter = 0;
    fin.open("f1.txt", ios::in);

    getline(fin, rin);
    while(fin)
    {
        for(int i = 0; i<rin.size(); i++)
        {


            if(rin[i+1]=='='&&rin[i]=='!'||rin[i]=='<'&&rin[i+1]=='='||rin[i]=='>'&&rin[i+1]=='='||rin[i]=='='&&rin[i+1]=='=')
                {
                    counter++;
                    cout << rin[i] <<rin[i+1]<<endl;
                }

        }
        getline(fin,rin);
    }

    fin.close();
    cout << counter;
}
