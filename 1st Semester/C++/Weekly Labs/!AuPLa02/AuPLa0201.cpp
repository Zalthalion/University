/*******************************************************************
Juris Freidenfelds, jf18017
AuPLa0201. Sastadit C++ programmu, kura parverð Farenheita grados uzdotu temperaturu
par temperaturu Celsija grados. Formula parverðanai:
C = 5/9(F-32)
Jabut iespejai programmu izpildit atkartoti, neizejot no programmas.
Programma izveidota: 14.09.2108
********************************************************************/
#include<iostream>
using namespace std;
int main()
{
    int ok;
    do
    {
        double F;
        cout << "Ievadi temperaturu Farenheita grados: ";
        cin >> F;
        double C=5.0/9*(F-32);
        cout << "Temperatura celsija grados " <<endl;
        cout << C << endl;
        cout << " Vai turpinaat (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}
/********************** Testu plans *********************************
Ievads      Velamnais rezultats
32          0
97.88       36.6
0           -17,77778
********************************************************************/
