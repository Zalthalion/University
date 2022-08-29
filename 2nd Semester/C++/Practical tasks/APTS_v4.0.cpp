///By: Juris Freidenfelds (jf18017)
#include <iostream>
#include <fstream>
using namespace std;


struct place{
    place *prev;                    //Norade uz ieprieksejo
    char word[256] = {'\0'};        //Masivs vardam
    place *next;                    //Norade uz nakamo
};

int main()
{
    fstream input;
    fstream output;
    char leter;
    int i= 0;

    ///Parbauda vai fails ir pilnigi tukss
    input.open("paldies.in");       //Atver ievades failu
    if(input.peek() == EOF)         //Parbauda vai fails nav tukss
    {
        output.open("paldies.out", ios::out);   //Atver izvades failu
        output << "nothing";                    //Ieraksta zinojumu
        output.close();                         //Aizver izvades failu
    }

    ///Parbauda vai fails sastav tikai no tuksiem simboliem
    for (istreambuf_iterator<char> it(input), end; it != end; ++it)
        if (*it && !isspace(*it))
            {                           //Ja nav tikai no whitespace
                place *first=NULL;      //Izveido sakuma noradi
                place *last=NULL;       //Izveido beigu noradi
                place *p= new place;    //Izveido jaunu elementu (place) ar palignoradi p
                p->prev=NULL;
                first = p;

    ///Izveido sarakstu un to aizpilda
     while (!input.eof())
    {
        input.get(leter);               //Iegust simbolu no faila
        if (leter == ' ')               //Ja simbols ir space...
        {
            p->next=new place;          //Tad tiek izveidots jauns elements
            p->next->prev=p;
            p->word[i] = '\0';          //Varda gala ieliek beigu simbolu
            i=0;
            p=p->next;
            continue;                   //Un izlaiz atstarpi, lai ta netiktu nekur ievadita
        }
        p->word[i] = leter;             //Aizpilda elementa, char masivu
        i++;
    }
    p->word[i-1]='\0';                  //Nonem no beigam burtu kas dubultojas
    input.close();                      //Aizver ievades failu

    last = p;                           //Norada saraksta beigu noradi
output.open("paldies.out", ios::out);   //Atver izvades failu
    for(int i = 97; i<124; i++)         //Cikls, kurs saskiro vardus pec pirma burta
        {
            while(p!=NULL)
            {
                if(p->word[0]==(char)i)
                output << p->word <<' ' ;   //Izvade
                p = p->prev;                //Parcel palignoradi uz ieprieksejo elementu
            }
            p=last;                     //Kad ir parbauditit visi saraksta elementi ar vienu burtu
                                        //Palignoradi atleik atpakal uz saraksta beigam, lai saktu visu no jauna
        }
            output.close();                         //Aizver izvades failu

        }
        else                            //Ja fails sastav tikai no atstarpem, tad izvades faila ieraksta nothing
        {
            output.open("paldies.out", ios::out);   //Atver izvades failu
            output << "nothing";                    //Izvade
            output.close();}                        //Aizver izvades failu



return 0;
}
