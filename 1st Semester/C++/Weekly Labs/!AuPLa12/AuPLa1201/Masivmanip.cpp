//Masivmanip.cpp

#include<iostream>
using namespace std;
#include "Masivmanip.h"

Masivmanip::Masivmanip(int n)
{
    cout << "Objektam " << this << " tiks pieðíirta masîva atmiòa" << endl;
    this -> n = (n>=1)?n:3;
    mas = new int[this->n];
    cout << "Objekta masîvam ir pieðíirta atmiòa: " << mas << endl;
    for( int j=0; j<n; j++)
        mas[j] = 0;
}

Masivmanip::~Masivmanip()
{
    cout << "Objekta masîvs " << mas << " tiks iznîcinâts!!" << endl;
    delete[] mas;
    cout << "Objekta masîvs " << mas << " ir iznîcinâts!!" << endl;
    cout << "Objekts " << this << " tiks iznîcinâts" <<endl;
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
