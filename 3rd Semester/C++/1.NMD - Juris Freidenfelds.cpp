/**********************************************
Noprogramm�t autom�tu, kas akcept� valodu L={w | w nesatur fragmentu cba, bet satur nep�ra skaitu b} alfab�t� sigma ={a, b, c}

-Dr�kst izmantot jebk�du programm��anas valodu
-Programm� j�b�t funkcijai, kas sa�em ievad� simbolu virkni (string) un atgrie� j� vai n� (boolean)
-J�iesniedz tikai koment�ts pirmkods
***********************************************/
#include <iostream>
#include <string>
using namespace std;

bool checkIfWordIsInLanguage(string& name)
{
    if(name == "")return false;     //Ja padotais v�rds ir epsilons, tad tiek atgriezts false, jo s�kuma st�voklis nav akcept�jo�s
    int i = 0;                      //Pal�gmain�gais priek� v�rda p�rstaig��anai
    char position = 'A';

    //While cikls, kur� p�rstaig� katru v�rda simbolu
    while (name[i]){

    /**     T� k� no katra st�vok�a ir j�b�t 3 iesp�jamajiem variantiem - a, b vai c, jo autom�ts ir visur defin�ts
            Lai pie katra so�a neb�tu j�raksta, kas tur notiek ideja ir t�da:
            M�s non�kam st�vokl� un tad skatamies, kas mums ir par burtu
            Un attiec�gi tam burtam samainam st�vokli
            Piem�ram Esam A st�vokl� un mums ir burts b, tad m�s p�rvietojamies uz B st�vokli  **/

        switch (position)
       {
                //A st�voklis ir s�kuma st�voklis
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

                //Miskastes st�voklis, �eit v�rds nok��st tikai tad, ja v�rd� ir sastopams fragments "cba"
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

    //Akcept�jo�ie st�vok�i ir B, C un F
    if (position == 'B')return true;
    if (position == 'C') return true;
    if (position == 'F') return true;

    //P�r�jie visi st�vok�i ir noraido�i
    return false;
}

int main()
{
    int ok;
    string name;

    //Do / while cikls, kur� at�auj izmantot programmu atk�rtoti, to neaizverot
    do
    {
        //V�rda ievade. Tiek pie�emts, ka dati tiek ievad�ti korekti
        cout << "Enter a name" << endl;
        getline (cin,name);

        //Funckijas checkIfWordIsInlanguage izsauk�ana
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


/********************Testu Pl�ns************************
    Ievad�tais v�rds        |       Gaid�mais rezult�ts

        Tuk� v�rds          |       Nepieder valodai
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
