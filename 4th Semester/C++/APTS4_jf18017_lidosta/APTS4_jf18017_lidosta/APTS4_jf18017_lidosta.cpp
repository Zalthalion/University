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

//Funkcija, kura "not�ra" pal�g'mas�vu
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

    //Izlai� visas atstarpes un beigu simbolus
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
    //Izlai� visas atstarpes un domuz�mes, kas atrodas pirms laika objekta (vai pa vidu)
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
    //izvair�s no kola
    file.get(s);
    jaunsLaiks.minutes[0] = ((int)s) - 48;
    file.get(s);
    jaunsLaiks.minutes[1] = ((int)s) - 48;

    return jaunsLaiks;
}

//Funkcija, kura p�rveido Laika objektu uz int tipa main�go
int fromLaiksToInt(Laiks laiks)
{
    int res = 0;
    res += laiks.stundas[0] * 1000;
    res += laiks.stundas[1] * 100;
    res += laiks.minutes[0] * 10;
    res += laiks.minutes[1];
    return res;
}

//Funkcija, kura izr��ina, cik ilgi j�gaida lidost�, l�dz konkr�tam reisam
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

//Funkcija, kura �oti ��p�g� veid� pieskaita Laika objektam 1 min�ti
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

    //P�rbauda, vai fails ir tuk�s
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

    //Nolasa ce�ojuma s�kuma punktu un galapunkti
    input >> startAirport >> endAirport;

    char s;

    input.get(s); // Izvair�s no beigu simbola

    //Nolasa ce�ojuma s�kuma laiku
    Laiks startTime = getLaiksFromFile(input);
  
    input.get(s); // Izvair�s no beigu simbola
    

    //Dinamiski izveidots mas�vs ar nor�d�m uz visiem reis�em ko pied�v� lidosta
    //Atkar�gs no fail� ierakst�taj�m lidost�m
    Reiss** visiReisi = new Reiss * [airportCount+1];
    
    //Katr� mas�va viet� pievieno jaunu reisu
    for (int i = 1; i <= airportCount; i++)
    {
        visiReisi[i] = new Reiss;
        visiReisi[i]->next = NULL;
    }


    char temp[5] = { '\0' }; //Pal�g'mas�vs
    int cnt = 0;             //Pal�g'skait�t�js
    int lidostaNo;
    int lidostaUz;
    
    //Nolasa l�dz faila beig�m, visus izvedotos reisus
    while (!input.eof())
    {   
        //Nolasa, no kuras lidostas atiet reiss
        lidostaNo = getIntFromFile(input, temp);

        //Ja �� lidosta ir 0, tad ir sasniegtas faila beigas
        if(lidostaNo == 0)
        {
            break;
        }
        
        //Nolasa, uz kuru lidostu ir j�tiek
        lidostaUz = getIntFromFile(input, temp);

        //Nolasa skaitli, cik reisi ir nolas�mi vien� rindi��
        int loop = getIntFromFile(input, temp);

        cnt = 0;
        //Nolasa visus reisusu, kuri ir sastopami teksta rindi��
        while (cnt != loop)
        {
            //Izveido nor�di uz jaunu objektu
            Reiss* tempReiss = new Reiss;
            //Pievieno tam inform�ciju par lidost�m no kuras un uz kuru lido reiss
            tempReiss->no = lidostaNo;
            tempReiss->uz = lidostaUz;
            //Ieg�st laiku, kad reiss izlido
            tempReiss->izlido = getLaiksFromFile(input);
            //Un, kad reiss ielido galam�r��
            tempReiss->ielido = getLaiksFromFile(input);
            tempReiss->next = NULL;

            //Papildus p�rbaude, vai nav j�beidz 
            if (lidostaNo == 0)break;

            //P�rbauda, vai �is ir pirmais objekts konkr�tai lidostai
            if (visiReisi[lidostaNo]->next == NULL)
            {
                visiReisi[lidostaNo]->next = tempReiss;   
            }
            else
            {
                //Ja nav tad novieto nor�di saraksta beig�s un tikai tad pievieno objektu
                //�o var optimiz�t ar last/tail nor�di
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
    //Ievada taj� s�kuma lidostu
    output << startAirport << ' ';
    //Un cikos ierodas taj�
    output << startTime.stundas[0] << startTime.stundas[1] << ':' << startTime.minutes[0] << startTime.minutes[1] << endl;
    //Pieskaita kl�t min�ti
    addMinute(currTime);

    //Cikls, kur� darbosies, kam�r netiks sasniegts galam�r�is
    //(Pa�reiz�j� lidosta ir vien�da ar galam�r�a lidostu)
    while (curAirport != endAirport)
    {
        int min = 4800; //Tiek pie�emts, ka minim�l� v�rt�ba ir 4800 (kas jebkur� gad�jum� neb�s minim�lais)
        bool allVisited = true; //Bool tipa main�gais, kur� noteiks, vai ir iesp�jams non�kt galam�r��
        
        Reiss* temp = visiReisi[curAirport]->next;
        Reiss* minNo = visiReisi[curAirport]->next;

        //P�rstaig� konkr�tas lidostas reisus
        while (temp != NULL)
        {
            //Ja reiss jau ir izmantots, tad to izlai�
            if (temp->used == true)
            {
                temp = temp->next;
                continue;
            }
            else
            {
                allVisited = false;
            }
            
            //Laiks no tagad�j�, l�dz izlido�anas
            int lidzIzlidosanai = addTimesTogether(temp->izlido, currTime);
            
            //Atrod maz�ko gaid��anas laiku
            if (lidzIzlidosanai <= min)
            {
                min = lidzIzlidosanai;
                minNo = temp;
            }
            temp = temp->next;
        }
        //Ja nor�de nav NULL
        if (minNo != NULL) 
        {
            
            minNo->used = true;         //Atz�m�, ka reiss ir izmantots
            curAirport = minNo->uz;     //Nomaina pa�reiz�jo lidostu
            currTime = minNo->ielido;   //Izmaina tagad�jo laiku, uz lidma��nas iera�an�s laiku
            addMinute(currTime);        //Pieskaita min�ti tagad�jam laikam

            //un tiek izdruk�ta rindi�a izvades fail�
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