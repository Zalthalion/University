/*******************
// lvtocon.h
Ðinî failâ aprakstîti funkciju un operatoru prototipi, kas ïauj
pareizi izvadît latvieðu tekstu uz DOS konsoles.

Versija: 2.0,  paredzçta izmantoðanai projektos
Autors: Çriks Gopaks.
Datums: 07/12/2011
*******************/

#ifndef TRANSLATOR_H_INCLUDED
#define TRANSLATOR_H_INCLUDED

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

void Output (const char *s);
ostream & operator << (ostream &, const string &);
ostream & operator << (ostream &, const char *s);

#endif
