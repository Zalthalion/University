/***************************************************
Juris Freidenfelds, jf18017
AuPLa0301. Sastâdît C++ programmu, kas dotam naturâlam skaitlim N aprçíina faktoriâlu no N.
Jâbût iespçjai programmu izpildît atkârtoti, neizejot no programmas.
Programma izveidota: 20.09.2018
***************************************************/
#include<iostream>
using namespace std;
int main()
{   cout << "Naturâla skaitïa N aprçíina faktoriâlu no N" << endl;
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
        cout << "Skaitïa " << n << " faktoriâls =  " << fakt << endl;
        cout << " Vai turpinaat (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}
/******************* Testu plâns *****************
    N       N!
    17      355687428096000
    0       1
    1       1
    20      2432902008176640000 no wolframalpha.com
    21      Nevar aprçíinât, jo 21! ir lielâks par ULLOG_MAX
    -1      Nevar aprçíinât, jo N! nav definçts
*************************************************/
