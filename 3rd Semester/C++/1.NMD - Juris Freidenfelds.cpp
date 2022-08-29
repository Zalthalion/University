/**********************************************
Noprogrammçt automâtu, kas akceptç valodu L={w | w nesatur fragmentu cba, bet satur nepâra skaitu b} alfabçtâ sigma ={a, b, c}

-Drîkst izmantot jebkâdu programmçðanas valodu
-Programmâ jâbût funkcijai, kas saòem ievadâ simbolu virkni (string) un atgrieþ jâ vai nç (boolean)
-Jâiesniedz tikai komentçts pirmkods
***********************************************/
#include <iostream>
#include <string>
using namespace std;

bool checkIfWordIsInLanguage(string& name)
{
    if(name == "")return false;     //Ja padotais vârds ir epsilons, tad tiek atgriezts false, jo sâkuma stâvoklis nav akceptçjoðs
    int i = 0;                      //Palîgmainîgais priekð vârda pârstaigâðanai
    char position = 'A';

    //While cikls, kurð pârstaigâ katru vârda simbolu
    while (name[i]){

    /**     Tâ kâ no katra stâvokïa ir jâbût 3 iespçjamajiem variantiem - a, b vai c, jo automâts ir visur definçts
            Lai pie katra soïa nebûtu jâraksta, kas tur notiek ideja ir tâda:
            Mçs nonâkam stâvoklî un tad skatamies, kas mums ir par burtu
            Un attiecîgi tam burtam samainam stâvokli
            Piemçram Esam A stâvoklî un mums ir burts b, tad mçs pârvietojamies uz B stâvokli  **/

        switch (position)
       {
                //A stâvoklis ir sâkuma stâvoklis
           case 'A':
               {
                    if(name[i]=='a') position = 'A';
                    if(name[i]=='b') position = 'B';
                    if(name[i]=='c') position = 'E';
                break;
               }

           case 'B':
                {
                    if(name[i]=='a') position = 'B';
                    if(name[i]=='b') position = 'A';
                    if(name[i]=='c') position = 'C';
                break;
                }

           case 'C':
                {
                    if(name[i]=='a') position = 'A';
                    if(name[i]=='b') position = 'D';
                    if(name[i]=='c') position = 'B';
                break;
                }

           case 'D':
                {
                    if(name[i]=='a') position = 'X';
                    if(name[i]=='b') position = 'B';
                    if(name[i]=='c') position = 'E';
                break;
                }

           case 'E':
                {
                    if(name[i]=='a') position = 'A';
                    if(name[i]=='b') position = 'F';
                    if(name[i]=='c') position = 'E';
                break;
                }

           case 'F':
                {
                    if(name[i]=='a') position = 'X';
                    if(name[i]=='b') position = 'A';
                    if(name[i]=='c') position = 'E';
                break;
                }

                //Miskastes stâvoklis, ðeit vârds nokïûst tikai tad, ja vârdâ ir sastopams fragments "cba"
           case 'X':
                {
                    if(name[i]=='a') position = 'X';
                    if(name[i]=='b') position = 'X';
                    if(name[i]=='c') position = 'X';
                break;
                }
        }
    i++;
    }

    //Akceptçjoðie stâvokïi ir B, C un F
    if (position == 'B')return true;
    if (position == 'C') return true;
    if (position == 'F') return true;

    //Pârçjie visi stâvokïi ir noraidoði
    return false;
}

int main()
{
    int ok;
    string name;

    //Do / while cikls, kurð atïauj izmantot programmu atkârtoti, to neaizverot
    do
    {
        //Vârda ievade. Tiek pieòemts, ka dati tiek ievadîti korekti
        cout << "Enter a name" << endl;
        getline (cin,name);

        //Funckijas checkIfWordIsInlanguage izsaukðana
        if(checkIfWordIsInLanguage(name)== 1)
        {
            cout << "The name DOES belong to this language" << endl;
        }
        else
        {
            cout << "This name DOES NOT belong to thisi language" << endl;
        }


        cout << "Do you want to use the programm again? (1 == Yes and 0 == N0): ";
        cin>>ok;

        cin.ignore();
        cout << endl;

    }while (ok==1);

    return 0;
}


/********************Testu Plâns************************
    Ievadîtais vârds        |       Gaidâmais rezultâts

        Tukð vârds          |       Nepieder valodai
        {a}                 |       Nepieder valodai
        {b}                 |       Pieder valodai
        {c}                 |       Nepieder valodai
        {ab}                |       Pieder valodai
        {cb}                |       Pieder valodai
        {bb}                |       Nepieder valodai
        {cba}               |       Nepieder valodai
        {abccaaabc}         |       Nepieder valodai
        {abbbcbbacc}        |       Pieder valodai
        {ababababababab}    |       Pieder valodai
        {cabcabcabcabcba}   |       Nepieder valodai
*******************************************************/
