/**
F16. Dots teksta fails, kur� atrodas sintaktiski pareizs C++ programmas teksts.
Saskait�t, cik sal�dzin��anas operatoru (==, !=, <=, >=) satur dot� programma.
Dr�kst uzskat�t, ka programmas tekst� nav koment�ru un ka attiec�gie simboli
nepar�d�sies teksta liter��os.
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
