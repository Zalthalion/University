#include <iostream>
#include <fstream>
using namespace std;

//Objekts - frizieris
struct frizieris
{
    int numurs;             //Friziera numurs
    bool aiznemts;          //Bool main�gais, kas par�da, vai frizieris ir pieejams (vai str�d�, vai ir p�rtraukum�)
    int laiksBezKlienta;    //Laiks, cik ilgi frizieris nav apkalpojis klientu
    int darbaLaikaBeigas;   //Laiks, kad frizieris beigs apgalpot klientu
    frizieris* next;        //Nor�de uz n�kamo frizieri
};

//Objekts - klients
struct klients
{
    klients* prev;          //Nor�de uz iepriek��jo klientu
    int numurs;             //Klienta apkalpo�anas k�rtas numurs
    int pierakstaLaiks;     //Laiks, kur� klients ir pierakst�jies pie friziera
    int procedurasIlgums;   //Klienta proced�ras ilgums
    int firzieraNr;         //Frizieris, kur� apkalpoja klientu
    klients* next;          //Nor�de uz n�kamo klientu
};


int main()
{

    fstream input;
    fstream output;

    //Atver ievades failu
    input.open("hair.in");

    //P�rbauda, vai fails ir tuk�s
    if (input.peek() == EOF)
    {
        //Ja ir, tad atver izvedes failu un ieraksta tur "nothing"
        output.open("hair.out", ios::out);
        output << "nothing";
        output.close();
    }

    //Nor�de uz pirmo un p�d�jo frizieri
    //frizieru vienvirziena saist�taj� sarakst�
    frizieris* firstFriz = NULL;
    frizieris* lastFriz = NULL;

    //Nor�de uz pirmo un p�d�jo klientu
    //Klientu divvirzienu saist�taj� sarakst�
    klients* firstKlients = NULL;
    klients* lastKlients = NULL;

    //Izveido "dummy" klientu
    klients* tempK = new klients;
    firstKlients = tempK;

    //Nolasa no faila, cik frizieri str�d� friz�tav�
    char temp;
    input.get(temp);

    int frizieruSk = temp - '0';

    int i = 0;

    //Nolasa p�r�jo failu pa rindi�ai
    while (!input.eof())
    {
        //Pal�gmain�gie
        int ierLaiks;
        int klientaNr;
        int apkalposanasLaiks;

        //Pie��ir pal�gmain�gajiem, no faila nolas�t�s v�rt�bas
        input >> ierLaiks >> klientaNr >> apkalposanasLaiks;

        //Ja ir sasniegta nulle, tad beidz faila las��anu
        if (ierLaiks == 0) break;

        //Pal�gskait�t�js, kur� saskaita, cik klienti tiek pievienoti sarakstam
        i++;

        //Izveido nor�di uz jaunu kleintu
        klients* t = new klients;

        //Jaunajam klientam pievieno nolas�t�s v�rt�bas un pievieno izveidoto klientu saist�tajam sarakstam
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
    //P�rvieto nor�di no "dummy" saraksta s�kumu uz �sto saraksta s�kumu
    firstKlients = firstKlients->next;
    firstKlients->prev = NULL;
    //Un izdz�� izveidoto dummy head
    delete(tempK);

    

    //Izveido pirmo frizieri (s�kums frizieru saist�tajam sarakstam)
    frizieris* p = new frizieris;
    
    p->numurs = 1;
    p->aiznemts = false;
    p->laiksBezKlienta = 0;
    p->darbaLaikaBeigas = 0;
    p->next = NULL;

    //P�rvieto nor�di uz saraksta pirmo elementu
    firstFriz = p;

    //Izveido atliku�os frizierus
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


    //P�rstaig� klientus
    while (tempK != NULL)
    {
        //P�rvieto pal�gnor�di saraksta s�kum�
        p = firstFriz;

        //While cikls, kas p�rbauda vai visi frizieri ir aiz�emti
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

        //While cikls, kas atrod frizieri, kur� vis�tr�k beigs apkalpot k�du klientu
        while (p != NULL)
        {   
            if (p->darbaLaikaBeigas < atrakasBeigasDarbam)
            {
                MinDL = p;
                atrakasBeigasDarbam = p->darbaLaikaBeigas;
            }
            p = p->next;
        }
        
        //Pal�gmain�gie, klienta pieraksta un proced�ras beigu laikiem
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

        //Ja visi frizieri ir aiz�emti un klienta pieraksta laiks, liel�ks, �tr�kais laiks, kad k�ds frizieris atbr�vosies
        //Tad tas frizieris vairs nav aiz�emts un ir gaid�jis l�dz �� klienta pieraksta br�dim
        if (visiAiznemti == true && tempK->pierakstaLaiks > MinDL->darbaLaikaBeigas)
        {

            //Klienta pieraksta laiks, ir j�maina tikai tad, ja visi frizieri ir aiz�emti un nav newviena, kur� var�tu apkalpot klientu

            MinDL->aiznemts = false;
            MinDL->laiksBezKlienta = tempK->pierakstaLaiks - MinDL->darbaLaikaBeigas;

            //P�rbauda, vai jaunais klienta pieraksta laiks nesakr�t ar friziera p�rtraukumu, ja sakr�t
            //tad pieskaita 100 (p�traukums) un atliku�o da�u l�dz p�rtraukumam
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
        //While cikls, kas p�rstaig� visus frizierus
        //Un visiem neaiz�emtajiem frizieriem pieskaita gaid��anas laiku jau eso�ajam
        while (p != NULL)
        {
            if (p->aiznemts)
            {
                p = p->next;
                continue;
            }

            //Ja klients ir pirmais, tad gaid��anas laikam pieskaita pirm� klienta iera�an�s laiku
            //Ja nav pirmais, tad pieskaita laika posmu no p�d�j� klienta iera�an�s laika l�dz tagad�j� klienta iera�an�s laika
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
        
        //While cikls, kur� p�rstaig� visus frizierus
        //Un atrod frizieri ar visliel�ko gaid��anas laiku
        //Reiz� ar� p�rbauda, vai frizierim nesakr�t p�rtraukums ar pierakstu
        while (p != NULL)
        {
         
            //Ir 3 gad�jumi k�dos pieraksts var non�kt probl�m�s ar friziera p�rtraukumu
            // 1) Pieraksts s�k�s friziera p�rtraukum�
            // 2) Pieraksts beidz�s friziera p�rtraukum�
            // 3) Pieraksts s�kas pirms p�rtraukuma un beidz�s p�c p�rtraukuma

            //Ja proced�ras s�kuma simts vai proced�ru beigu simts sakr�t ar friziera numuru, tad p�rvietojas uz n�kamo frizieri
            if (p->aiznemts || p->numurs == startSimts || p->numurs == endSimts)
            {
                p = p->next;
                continue;
            }
            //Ja proced�ra s�k�s pirms p�rtraukuma un beidz�s p�c p�rtraukuma, tad p�rvietojas uz n�kamo frizieri
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

        //Pie��ir tagad�jam klientam friziera nr, kur� apkalpos klientu
        tempK->firzieraNr = k->numurs;
        //Frizieris ir aiz�emts
        k->aiznemts = true;
        //Pievieno friziera darba beigas
        k->darbaLaikaBeigas = tempK->pierakstaLaiks + tempK->procedurasIlgums;
        //Un nodz�� friziera gaid��anas laiku uz 0
        k->laiksBezKlienta = 0;


        tempK = tempK->next;
    }

    p = firstFriz;
    
    //Atver izvades failu
    output.open("hair.out", ios::out);

    //Pal�gskait�t�js, lai zin�tu, cik klienti ir izdruk�ti
    int checked = 0;

    //Novieto pal�gnor�di klientu saist�t� saraksta s�kum�
    tempK = firstKlients;

    //Pie�em, ka vis�tr�k no friz�tavais aiziet pirmais klients
    int minKlients = tempK->pierakstaLaiks + tempK->procedurasIlgums - 1;

    //P�l�gnor�de izdrukai
    klients* printing = firstKlients;

    //While cikls, kas darbosies tik reizes, cik klienti ir pierakst�ju�ies friz�tav�
    while (checked < i)
    {
        minKlients = firstKlients->pierakstaLaiks + firstKlients->procedurasIlgums - 1;
        
        tempK = firstKlients;

        //While cikls, kas atrod klientu, kur� vis�tr�k tika apkalpots
        while (tempK != NULL)
        {
            if (tempK->pierakstaLaiks + tempK->procedurasIlgums - 1 < minKlients)
            {
                printing = tempK;
            }
            tempK = tempK->next;
        }
        
        output << printing->pierakstaLaiks + printing->procedurasIlgums - 1 << ' ' << printing->firzieraNr << ' ' << printing->numurs << endl;
        
        
        //P�c druk��anas klientu var dz�st �r� no saraksta

        //Dz��ana, ja tiek dz�sts p�d�jais klients
        if (firstKlients->next == NULL && lastKlients->prev == NULL)
        {
            free(printing);
            break;
        }
        //Dz��ana, ja tiek dz�sts pirmais kleints
        if (printing->numurs == firstKlients->numurs) 
        {
            firstKlients = firstKlients->next;
            firstKlients->prev = NULL;
            free(printing);
        }
        //Dz��ana, ja tiek dz�sts p�d�jais klients
        else if (printing->numurs == lastKlients->numurs)
        {
            lastKlients = lastKlients->prev;
            lastKlients->next = NULL;
            free(printing);
        }
        //Dz��ana, ja klients atrodas saraksta vid�
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

    //Izdz�� visus frizierus
    p = firstFriz;
    while (p != NULL)
    {
        p = p->next;
        free(firstFriz);
        firstFriz = p;
    }

    return 0;
}