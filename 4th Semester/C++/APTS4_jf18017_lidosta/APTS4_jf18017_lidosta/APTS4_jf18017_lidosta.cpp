#include <fstream>
using namespace std;

struct Laiks
{
    int stundas[2];
    int minutes[2];
};

struct Reiss 
{
    int no;
    int uz;
    Laiks izlido;
    Laiks ielido;
    
    Reiss* next;
    
    bool used = false;
};

//Funkcija, kura "notîra" palîg'masîvu
void clearTemp(char *arr)
{
    for (int i = 0; i < 5; i++)
    {
        arr[i] = '\0';
    }
}

//Funkcija, kura nolasa skaitli no faila
int getIntFromFile(fstream& file, char *temp)
{
    
    char s;
    int cnt = 0;
    clearTemp(temp);
    file.get(s);

    //Izlaiþ visas atstarpes un beigu simbolus
    for (;;)
    {
        if (s == ' ' || s == '\n')
        {
            file.get(s);
        }
        else
        {
            break;
        }
    }
    temp[cnt] = s;
    //Nolasa skaitli no faila, pa vienam ciparam
    for (;;)
    {
        file.get(s);
        if (s == ' ' || s == '\n');
        {
            break;
        }
        temp[cnt] = s;
        cnt++;
    }
    int res = atoi(temp);
    return res;
}

//Funkcija, kura nolasa Laika objektu no faila
Laiks getLaiksFromFile(fstream& file)
{
    Laiks jaunsLaiks;
    char s;
    file.get(s);
    //Izlaiþ visas atstarpes un domuzîmes, kas atrodas pirms laika objekta (vai pa vidu)
    for (;;) 
    {
        if (s == ' ' || s == '-')
        {
            file.get(s);
        }
        else
        {
            break;
        }
    }
    

    jaunsLaiks.stundas[0] = ((int)s) - 48;
    file.get(s);
    jaunsLaiks.stundas[1] = ((int)s) - 48;
    file.get(s);
    //izvairâs no kola
    file.get(s);
    jaunsLaiks.minutes[0] = ((int)s) - 48;
    file.get(s);
    jaunsLaiks.minutes[1] = ((int)s) - 48;

    return jaunsLaiks;
}

//Funkcija, kura pârveido Laika objektu uz int tipa mainîgo
int fromLaiksToInt(Laiks laiks)
{
    int res = 0;
    res += laiks.stundas[0] * 1000;
    res += laiks.stundas[1] * 100;
    res += laiks.minutes[0] * 10;
    res += laiks.minutes[1];
    return res;
}

//Funkcija, kura izrçíina, cik ilgi jâgaida lidostâ, lîdz konkrçtam reisam
int addTimesTogether(Laiks adder, Laiks sum) 
{
    int one = fromLaiksToInt(adder);
    int two = fromLaiksToInt(sum);

    if (two <= one)
    {
        return one - two;
    }
    else
    {
        two = 2400 - two;
        return one + two;
    }   
}

//Funkcija, kura ïoti íçpîgâ veidâ pieskaita Laika objektam 1 minûti
void addMinute(Laiks& laiks)
{
    if (laiks.minutes[1] == 9 && laiks.minutes[0] == 5) 
    {
        laiks.minutes[0] = 0;
        laiks.minutes[1] = 0;

        if (laiks.stundas[0] == 2 && laiks.stundas[1] == 3)
        {
            laiks.stundas[0] = 0;
            laiks.stundas[1] = 0;
        }
        else
        {
            if (laiks.stundas[1] == 9)
            {
                laiks.stundas[1] = 0;
                laiks.stundas[0] += 1;
            }
            else
            {
                laiks.stundas[1] += 1;
            }
        }
    }
    else
    {
        if (laiks.minutes[1] == 9)
        {
            laiks.minutes[0] += 1;
            laiks.minutes[1] = 0;
        }
        else
        {
            laiks.minutes[1] += 1;
        }
    }
}


int main()
{
	fstream input;
	fstream output;
    
    //Atver ievades failu
	input.open("lidostas.in");

    //Pârbauda, vai fails ir tukðs
    if (input.peek() == EOF)
    {
        //Ja ir, tad atver izvedes failu un ieraksta tur "nothing"
        output.open("lidostas.out", ios::out);
        output << "nothing";
        output.close();
        input.close();
        return 0;
    }

    int airportCount;

    //Nolasa lidostu skaitu
    input >> airportCount;

    
    int startAirport;
    int endAirport;

    //Nolasa ceïojuma sâkuma punktu un galapunkti
    input >> startAirport >> endAirport;

    char s;

    input.get(s); // Izvairâs no beigu simbola

    //Nolasa ceïojuma sâkuma laiku
    Laiks startTime = getLaiksFromFile(input);
  
    input.get(s); // Izvairâs no beigu simbola
    

    //Dinamiski izveidots masîvs ar norâdçm uz visiem reisîem ko piedâvâ lidosta
    //Atkarîgs no failâ ierakstîtajâm lidostâm
    Reiss** visiReisi = new Reiss * [airportCount+1];
    
    //Katrâ masîva vietâ pievieno jaunu reisu
    for (int i = 1; i <= airportCount; i++)
    {
        visiReisi[i] = new Reiss;
        visiReisi[i]->next = NULL;
    }


    char temp[5] = { '\0' }; //Palîg'masîvs
    int cnt = 0;             //Palîg'skaitîtâjs
    int lidostaNo;
    int lidostaUz;
    
    //Nolasa lîdz faila beigâm, visus izvedotos reisus
    while (!input.eof())
    {   
        //Nolasa, no kuras lidostas atiet reiss
        lidostaNo = getIntFromFile(input, temp);

        //Ja ðî lidosta ir 0, tad ir sasniegtas faila beigas
        if(lidostaNo == 0)
        {
            break;
        }
        
        //Nolasa, uz kuru lidostu ir jâtiek
        lidostaUz = getIntFromFile(input, temp);

        //Nolasa skaitli, cik reisi ir nolasâmi vienâ rindiòâ
        int loop = getIntFromFile(input, temp);

        cnt = 0;
        //Nolasa visus reisusu, kuri ir sastopami teksta rindiòâ
        while (cnt != loop)
        {
            //Izveido norâdi uz jaunu objektu
            Reiss* tempReiss = new Reiss;
            //Pievieno tam informâciju par lidostâm no kuras un uz kuru lido reiss
            tempReiss->no = lidostaNo;
            tempReiss->uz = lidostaUz;
            //Iegûst laiku, kad reiss izlido
            tempReiss->izlido = getLaiksFromFile(input);
            //Un, kad reiss ielido galamçríî
            tempReiss->ielido = getLaiksFromFile(input);
            tempReiss->next = NULL;

            //Papildus pârbaude, vai nav jâbeidz 
            if (lidostaNo == 0)break;

            //Pârbauda, vai ðis ir pirmais objekts konkrçtai lidostai
            if (visiReisi[lidostaNo]->next == NULL)
            {
                visiReisi[lidostaNo]->next = tempReiss;   
            }
            else
            {
                //Ja nav tad novieto norâdi saraksta beigâs un tikai tad pievieno objektu
                //Ðo var optimizçt ar last/tail norâdi
                Reiss* t = new Reiss;
                t = visiReisi[lidostaNo]->next;
                while (t->next != NULL)
                {
                    t = t->next;
                }
                t->next = tempReiss;
            }
            cnt++;
        }
    }
    //Aizver ievades failu
    input.close();
    
    Laiks currTime; //Cik ir pulkstenis?
   
    currTime.stundas[0] = startTime.stundas[0];
    currTime.stundas[1] = startTime.stundas[1];
    currTime.minutes[0] = startTime.minutes[0];
    currTime.minutes[1] = startTime.minutes[1];

    int curAirport = startAirport;
    
    //Atver izvades failu
    output.open("lidostas.out", ios::out);
    //Ievada tajâ sâkuma lidostu
    output << startAirport << ' ';
    //Un cikos ierodas tajâ
    output << startTime.stundas[0] << startTime.stundas[1] << ':' << startTime.minutes[0] << startTime.minutes[1] << endl;
    //Pieskaita klât minûti
    addMinute(currTime);

    //Cikls, kurð darbosies, kamçr netiks sasniegts galamçríis
    //(Paðreizçjâ lidosta ir vienâda ar galamçría lidostu)
    while (curAirport != endAirport)
    {
        int min = 4800; //Tiek pieòemts, ka minimâlâ vçrtîba ir 4800 (kas jebkurâ gadîjumâ nebûs minimâlais)
        bool allVisited = true; //Bool tipa mainîgais, kurð noteiks, vai ir iespçjams nonâkt galamçríî
        
        Reiss* temp = visiReisi[curAirport]->next;
        Reiss* minNo = visiReisi[curAirport]->next;

        //Pârstaigâ konkrçtas lidostas reisus
        while (temp != NULL)
        {
            //Ja reiss jau ir izmantots, tad to izlaiþ
            if (temp->used == true)
            {
                temp = temp->next;
                continue;
            }
            else
            {
                allVisited = false;
            }
            
            //Laiks no tagadçjâ, lîdz izlidoðanas
            int lidzIzlidosanai = addTimesTogether(temp->izlido, currTime);
            
            //Atrod mazâko gaidîðanas laiku
            if (lidzIzlidosanai <= min)
            {
                min = lidzIzlidosanai;
                minNo = temp;
            }
            temp = temp->next;
        }
        //Ja norâde nav NULL
        if (minNo != NULL) 
        {
            
            minNo->used = true;         //Atzîmç, ka reiss ir izmantots
            curAirport = minNo->uz;     //Nomaina paðreizçjo lidostu
            currTime = minNo->ielido;   //Izmaina tagadçjo laiku, uz lidmaðînas ieraðanâs laiku
            addMinute(currTime);        //Pieskaita minûti tagadçjam laikam

            //un tiek izdrukâta rindiòa izvades failâ
            output << minNo->no << "->" << minNo->uz << ' ';
            output << minNo->izlido.stundas[0] << minNo->izlido.stundas[1];
            output << ':';
            output << minNo->izlido.minutes[0] << minNo->izlido.minutes[1];
            output << '-';
            output << minNo->ielido.stundas[0] << minNo->ielido.stundas[1];
            output << ':';
            output << minNo->ielido.minutes[0] << minNo->ielido.minutes[1];
            output << endl;
            
        }
   
        if (allVisited == true)
        {
            output.close();
            
            output.open("lidostas.out", ios::out);
            output << "Impossible";
            output.close();
            break;
        }
        

    }
    output.close();

    delete[] visiReisi;
    
    return 0;

}