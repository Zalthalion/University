/***************************************************
Juris Freidenfelds, jf18017
AuPLa0301. Sast�d�t C++ programmu, kas dotam natur�lam skaitlim N apr��ina faktori�lu no N.
J�b�t iesp�jai programmu izpild�t atk�rtoti, neizejot no programmas.
Programma izveidota: 20.09.2018
***************************************************/
#include<iostream>
using namespace std;
int main()
{   cout << "Natur�la skait�a N apr��ina faktori�lu no N" << endl;
    cout << endl;
    int ok;
    do
    {
        int n;
        unsigned long long int fakt; //faktorials no N
        cout << "Ievadi N: ";
        cin >> n;
        fakt=1;
        for ( int a=1; a<=n; a++)
            fakt=fakt*a;
        cout << "Skait�a " << n << " faktori�ls =  " << fakt << endl;
        cout << " Vai turpinaat (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}
/******************* Testu pl�ns *****************
    N       N!
    17      355687428096000
    0       1
    1       1
    20      2432902008176640000 no wolframalpha.com
    21      Nevar apr��in�t, jo 21! ir liel�ks par ULLOG_MAX
    -1      Nevar apr��in�t, jo N! nav defin�ts
*************************************************/
