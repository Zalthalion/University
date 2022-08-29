/******************
// lvtocon.cpp

Ðinî failâ aprakstîtâs funkcijas ïauj pareizi izvadît
latvieðu tekstu uz MS-DOS konsoles.

Versija: 2.0,  paredzçta izmantoðanai projektos
Autors: Çriks Gopaks.
Datums: 07/12/2011
******************/

#include "lvtocon.h"

// Note: no need in overwriting output for other data types

ostream & operator << (ostream& out, const string &s)
{
    Output(s.c_str());
    return out;
}

ostream & operator << (ostream& out, const char *s)
{
    Output(s);
    return out;
}

const unsigned char TRANSLATOR_CHARS[256] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 160, 0, 0, 0, 0, 237, 182, 0, 0, 0, 149, 232, 161, 234,
    190, 0, 238, 0, 0, 0, 0, 0, 0, 0, 0, 199, 0, 0, 207, 0,
    0, 0, 131, 0, 0, 0, 0, 137, 209, 0, 0, 0, 133, 233, 140, 235,
    213, 0, 236, 0, 0, 0, 0, 0, 0, 0, 0, 215, 0, 0, 216, 0};


void Output (const char *s)
{
    int c, sz = strlen(s);
    for (int i = 0; i < sz; i++)
    {
        c = (int)(unsigned char)s[i];
        if (TRANSLATOR_CHARS[c] > 0) printf("%c", TRANSLATOR_CHARS[c]);
        else printf("%c", c);
    }
}
