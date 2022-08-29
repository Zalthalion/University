//Masivmanip.cpp

#include<iostream>
using namespace std;
#include "Masivmanip.h"

Masivmanip::Masivmanip(int n)
{
    cout << "Objektam " << this << " tiks pie��irta mas�va atmi�a" << endl;
    this -> n = (n>=1)?n:3;
    mas = new int[this->n];
    cout << "Objekta mas�vam ir pie��irta atmi�a: " << mas << endl;
    for( int j=0; j<n; j++)
        mas[j] = 0;
}

Masivmanip::~Masivmanip()
{
    cout << "Objekta mas�vs " << mas << " tiks izn�cin�ts!!" << endl;
    delete[] mas;
    cout << "Objekta mas�vs " << mas << " ir izn�cin�ts!!" << endl;
    cout << "Objekts " << this << " tiks izn�cin�ts" <<endl;
}
void Masivmanip::mainit(int index, int vertiba)
{
    mas[index] = vertiba;
}
void Masivmanip::drukat()
{
    for(int i = 0; i<n; i++){
        cout << mas[i] << endl;
    }
}
