#include <iostream>
#include <fstream>
using namespace std;

//Objekts - frizieris
struct frizieris
{
    int numurs;             //Friziera numurs
    bool aiznemts;          //Bool mainîgais, kas parâda, vai frizieris ir pieejams (vai strâdâ, vai ir pârtraukumâ)
    int laiksBezKlienta;    //Laiks, cik ilgi frizieris nav apkalpojis klientu
    int darbaLaikaBeigas;   //Laiks, kad frizieris beigs apgalpot klientu
    frizieris* next;        //Norâde uz nâkamo frizieri
};

//Objekts - klients
struct klients
{
    klients* prev;          //Norâde uz iepriekðçjo klientu
    int numurs;             //Klienta apkalpoðanas kârtas numurs
    int pierakstaLaiks;     //Laiks, kurâ klients ir pierakstîjies pie friziera
    int procedurasIlgums;   //Klienta procedûras ilgums
    int firzieraNr;         //Frizieris, kurð apkalpoja klientu
    klients* next;          //Norâde uz nâkamo klientu
};


int main()
{

    fstream input;
    fstream output;

    //Atver ievades failu
    input.open("hair.in");

    //Pârbauda, vai fails ir tukðs
    if (input.peek() == EOF)
    {
        //Ja ir, tad atver izvedes failu un ieraksta tur "nothing"
        output.open("hair.out", ios::out);
        output << "nothing";
        output.close();
    }

    //Norâde uz pirmo un pçdçjo frizieri
    //frizieru vienvirziena saistîtajâ sarakstâ
    frizieris* firstFriz = NULL;
    frizieris* lastFriz = NULL;

    //Norâde uz pirmo un pçdçjo klientu
    //Klientu divvirzienu saistîtajâ sarakstâ
    klients* firstKlients = NULL;
    klients* lastKlients = NULL;

    //Izveido "dummy" klientu
    klients* tempK = new klients;
    firstKlients = tempK;

    //Nolasa no faila, cik frizieri strâdâ frizçtavâ
    char temp;
    input.get(temp);

    int frizieruSk = temp - '0';

    int i = 0;

    //Nolasa pârçjo failu pa rindiòai
    while (!input.eof())
    {
        //Palîgmainîgie
        int ierLaiks;
        int klientaNr;
        int apkalposanasLaiks;

        //Pieðíir palîgmainîgajiem, no faila nolasîtâs vçrtîbas
        input >> ierLaiks >> klientaNr >> apkalposanasLaiks;

        //Ja ir sasniegta nulle, tad beidz faila lasîðanu
        if (ierLaiks == 0) break;

        //Palîgskaitîtâjs, kurð saskaita, cik klienti tiek pievienoti sarakstam
        i++;

        //Izveido norâdi uz jaunu kleintu
        klients* t = new klients;

        //Jaunajam klientam pievieno nolasîtâs vçrtîbas un pievieno izveidoto klientu saistîtajam sarakstam
        tempK->next = t;
        t->prev = tempK;
        t->numurs = klientaNr;
        t->firzieraNr = 0;
        t->pierakstaLaiks = ierLaiks;
        t->procedurasIlgums = apkalposanasLaiks;
        t->next = NULL;
        tempK = t;
        lastKlients = t;
    }

    //Aizver ievades failu
    input.close();
    tempK = firstKlients;
    //Pârvieto norâdi no "dummy" saraksta sâkumu uz îsto saraksta sâkumu
    firstKlients = firstKlients->next;
    firstKlients->prev = NULL;
    //Un izdzçð izveidoto dummy head
    delete(tempK);

    

    //Izveido pirmo frizieri (sâkums frizieru saistîtajam sarakstam)
    frizieris* p = new frizieris;
    
    p->numurs = 1;
    p->aiznemts = false;
    p->laiksBezKlienta = 0;
    p->darbaLaikaBeigas = 0;
    p->next = NULL;

    //Pârvieto norâdi uz saraksta pirmo elementu
    firstFriz = p;

    //Izveido atlikuðos frizierus
    for (int i = 1; i < frizieruSk; i++)
    {
        frizieris* temp = new frizieris;
        p->next = temp;
        temp->numurs = i + 1;
        temp->aiznemts = false;
        temp->laiksBezKlienta = 0;
        temp->darbaLaikaBeigas = 0;
        temp->next = NULL;
        lastFriz = temp;
        p = p->next;
    }


    frizieris* k = firstFriz;
    tempK = firstKlients;


    //Pârstaigâ klientus
    while (tempK != NULL)
    {
        //Pârvieto palîgnorâdi saraksta sâkumâ
        p = firstFriz;

        //While cikls, kas pârbauda vai visi frizieri ir aizòemti
        bool visiAiznemti = true;
        while (p != NULL)
        {
            if (p->aiznemts == false) 
            {
                visiAiznemti = false;
                break;
            }
            p = p->next;
        }
        
        
        p = firstFriz;
        long long int atrakasBeigasDarbam = 2000000000;
        frizieris* MinDL = firstFriz;

        //While cikls, kas atrod frizieri, kurð visâtrâk beigs apkalpot kâdu klientu
        while (p != NULL)
        {   
            if (p->darbaLaikaBeigas < atrakasBeigasDarbam)
            {
                MinDL = p;
                atrakasBeigasDarbam = p->darbaLaikaBeigas;
            }
            p = p->next;
        }
        
        //Palîgmainîgie, klienta pieraksta un procedûras beigu laikiem
        int startSimts = 0;
        int endSimts = 0;

        if (tempK->pierakstaLaiks > 99)
        {
            startSimts = tempK->pierakstaLaiks / 100 % 10;
        }
        if (tempK->pierakstaLaiks + tempK->procedurasIlgums > 99)
        {
            endSimts = tempK->pierakstaLaiks + tempK->procedurasIlgums;
            endSimts = endSimts / 100 % 10;
        }

        //Ja visi frizieri ir aizòemti un klienta pieraksta laiks, lielâks, âtrâkais laiks, kad kâds frizieris atbrîvosies
        //Tad tas frizieris vairs nav aizòemts un ir gaidîjis lîdz ðî klienta pieraksta brîdim
        if (visiAiznemti == true && tempK->pierakstaLaiks > MinDL->darbaLaikaBeigas)
        {

            //Klienta pieraksta laiks, ir jâmaina tikai tad, ja visi frizieri ir aizòemti un nav newviena, kurð varçtu apkalpot klientu

            MinDL->aiznemts = false;
            MinDL->laiksBezKlienta = tempK->pierakstaLaiks - MinDL->darbaLaikaBeigas;

            //Pârbauda, vai jaunais klienta pieraksta laiks nesakrît ar friziera pârtraukumu, ja sakrît
            //tad pieskaita 100 (pâtraukums) un atlikuðo daïu lîdz pârtraukumam
            if (startSimts == MinDL->numurs || endSimts == MinDL->numurs)
            {
                tempK->pierakstaLaiks = tempK->pierakstaLaiks + (100 - tempK->pierakstaLaiks % 100)+100;
            }
            if (startSimts < MinDL->numurs && endSimts > MinDL->numurs)
            {
                tempK->pierakstaLaiks = tempK->pierakstaLaiks + (100 - tempK->pierakstaLaiks % 100) + 100;
            }

        }
        else if (visiAiznemti == true && tempK->pierakstaLaiks < MinDL->darbaLaikaBeigas)
        {
            tempK->pierakstaLaiks = MinDL->darbaLaikaBeigas;
            MinDL->aiznemts = false;
            MinDL->laiksBezKlienta = tempK->pierakstaLaiks - MinDL->darbaLaikaBeigas;
        }


        p = firstFriz;
        //While cikls, kas pârstaigâ visus frizierus
        //Un visiem neaizòemtajiem frizieriem pieskaita gaidîðanas laiku jau esoðajam
        while (p != NULL)
        {
            if (p->aiznemts)
            {
                p = p->next;
                continue;
            }

            //Ja klients ir pirmais, tad gaidîðanas laikam pieskaita pirmâ klienta ieraðanâs laiku
            //Ja nav pirmais, tad pieskaita laika posmu no pçdçjâ klienta ieraðanâs laika lîdz tagadçjâ klienta ieraðanâs laika
            if (tempK->prev != NULL)
            {
                p->laiksBezKlienta += (tempK->pierakstaLaiks - tempK->prev->pierakstaLaiks);
            }
            else
            {
                p->laiksBezKlienta += tempK->pierakstaLaiks;
            }

            p = p->next;
        }


        p = firstFriz;
        k = firstFriz;
        long long int max = p->laiksBezKlienta;
        
        //While cikls, kurð pârstaigâ visus frizierus
        //Un atrod frizieri ar vislielâko gaidîðanas laiku
        //Reizç arî pârbauda, vai frizierim nesakrît pârtraukums ar pierakstu
        while (p != NULL)
        {
         
            //Ir 3 gadîjumi kâdos pieraksts var nonâkt problçmâs ar friziera pârtraukumu
            // 1) Pieraksts sâkâs friziera pârtraukumâ
            // 2) Pieraksts beidzâs friziera pârtraukumâ
            // 3) Pieraksts sâkas pirms pârtraukuma un beidzâs pçc pârtraukuma

            //Ja procedûras sâkuma simts vai procedûru beigu simts sakrît ar friziera numuru, tad pârvietojas uz nâkamo frizieri
            if (p->aiznemts || p->numurs == startSimts || p->numurs == endSimts)
            {
                p = p->next;
                continue;
            }
            //Ja procedûra sâkâs pirms pârtraukuma un beidzâs pçc pârtraukuma, tad pârvietojas uz nâkamo frizieri
            if (startSimts < p->numurs && endSimts > p->numurs)
            {
                p = p->next;
                continue;
            }
            else
            {
                if (p->laiksBezKlienta > max)
                {
                    max = p->laiksBezKlienta;
                    k = p;
                }
                p = p->next;
            }
        }

        //Pieðíir tagadçjam klientam friziera nr, kurð apkalpos klientu
        tempK->firzieraNr = k->numurs;
        //Frizieris ir aizòemts
        k->aiznemts = true;
        //Pievieno friziera darba beigas
        k->darbaLaikaBeigas = tempK->pierakstaLaiks + tempK->procedurasIlgums;
        //Un nodzçð friziera gaidîðanas laiku uz 0
        k->laiksBezKlienta = 0;


        tempK = tempK->next;
    }

    p = firstFriz;
    
    //Atver izvades failu
    output.open("hair.out", ios::out);

    //Palîgskaitîtâjs, lai zinâtu, cik klienti ir izdrukâti
    int checked = 0;

    //Novieto palîgnorâdi klientu saistîtâ saraksta sâkumâ
    tempK = firstKlients;

    //Pieòem, ka visâtrâk no frizçtavais aiziet pirmais klients
    int minKlients = tempK->pierakstaLaiks + tempK->procedurasIlgums - 1;

    //Pâlîgnorâde izdrukai
    klients* printing = firstKlients;

    //While cikls, kas darbosies tik reizes, cik klienti ir pierakstîjuðies frizçtavâ
    while (checked < i)
    {
        minKlients = firstKlients->pierakstaLaiks + firstKlients->procedurasIlgums - 1;
        
        tempK = firstKlients;

        //While cikls, kas atrod klientu, kurð visâtrâk tika apkalpots
        while (tempK != NULL)
        {
            if (tempK->pierakstaLaiks + tempK->procedurasIlgums - 1 < minKlients)
            {
                printing = tempK;
            }
            tempK = tempK->next;
        }
        
        output << printing->pierakstaLaiks + printing->procedurasIlgums - 1 << ' ' << printing->firzieraNr << ' ' << printing->numurs << endl;
        
        
        //Pçc drukâðanas klientu var dzçst ârâ no saraksta

        //Dzçðana, ja tiek dzçsts pçdçjais klients
        if (firstKlients->next == NULL && lastKlients->prev == NULL)
        {
            free(printing);
            break;
        }
        //Dzçðana, ja tiek dzçsts pirmais kleints
        if (printing->numurs == firstKlients->numurs) 
        {
            firstKlients = firstKlients->next;
            firstKlients->prev = NULL;
            free(printing);
        }
        //Dzçðana, ja tiek dzçsts pçdçjais klients
        else if (printing->numurs == lastKlients->numurs)
        {
            lastKlients = lastKlients->prev;
            lastKlients->next = NULL;
            free(printing);
        }
        //Dzçðana, ja klients atrodas saraksta vidû
        else
        {
            printing->prev->next = printing->next;
            printing->next->prev = printing->prev;
            printing->next = NULL;
            printing->prev = NULL;
            free(printing);
        }

        tempK = firstKlients;
        checked++;
        printing = firstKlients;    
    }
    //Aizver izvades failu
    output.close();

    //Izdzçð visus frizierus
    p = firstFriz;
    while (p != NULL)
    {
        p = p->next;
        free(firstFriz);
        firstFriz = p;
    }

    return 0;
}