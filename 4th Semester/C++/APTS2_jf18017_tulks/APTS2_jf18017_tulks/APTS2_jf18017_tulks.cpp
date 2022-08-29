#include <iostream>
#include <fstream>
using namespace std;

//Objekts Tulkojums, kur? tiks glab?ts valodas A un valodas B tulkojums
//Katrs objekts ir sast?vda?a no bin?ra mekl??anas koka
struct Tulkojums
{
    Tulkojums* left = NULL;
    char valoda_A[21] = { '\0' };
    char valoda_B[21] = { '\0' };
    Tulkojums* right = NULL;
    Tulkojums* next = NULL;
};

//Tulkojam? teksta saist?tais saraksts
struct Vards
{
    char vards[21] = { '\0' };
    Vards* next = NULL;
};


int main()
{
    fstream input;
    fstream output;

    char simbols;               //Pal?gmain?gais priek? nolas?t? simbola
    char virziens[3];           //Char mas?vs, priek? tulko?anas virziena saglab??anas

    input.open("tulks.in");         //Atver ievades failu
    if (input.peek() == EOF)        //Parbauda vai fails nav tukss
    {
        output.open("tulks.out", ios::out);     //Atver izvades failu
        output << "nothing";                    //Ieraksta zinojumu
        output.close();                         //Aizver izvades failu
    }

    int count = 0; // Pal?gskait?t?js
    //Cikls, kas atrod tulko?anas virzienu
    for (istreambuf_iterator<char> it(input), end; it != end; ++it)
    {
        if (count > 2) break;
        if (*it == '>' || *it == '<' || *it == '-')
        {
            virziens[count] = *it;
            count++;
        }
    }
    input.get(simbols); // rindas beigu simbolu

    //T? k? tulkojamais teksts ir uzreiz aiz tulkojam? virziena, to ar? nolasa un saglab? saist?taj? sarakst?
    Vards* first = new Vards;

    int l = 0; //Pal?gskait?t?js

    //Nolasa pirmo v?rdu no tulkojam? teksta
    while (!input.eof())
    {
        input.get(simbols);     //Nolasa simbolu

        if (simbols == ' ')     //Ja sastapta atstarpe, tad beidz las??anu
        {
            break;
        }
        first->vards[l] = simbols;  //ieraksta simbolu pirm? v?rda char mas?v?
        l++;
    }


    Vards* curr = new Vards;
    first->next = curr;
    l = 0;

    //Nolasa atliku?os v?rdus
    while (!input.eof())
    {
        input.get(simbols);

        if (simbols == ' ' || simbols == '\n') //Pie katras atstarpes vai rindas beig?m tiek izveidots jauns v?rds
        {
            curr->next = new Vards;
            curr->vards[l] = '\0';
            l = 0;
            curr = curr->next;
            continue;
        }
        curr->vards[l] = simbols;
        l++;
    }

    //curr->vards[l-1] = '\0'; //TEST IF WORKS

    //Novieto las??anas pointeri faila s?kum?
    input.clear();
    input.seekg(0, input.beg);

    //Izveido bin?r? mekl??anas koka sakni no pirm? nolas?t? tulkojuma
    //Neskatoties uz to, no kuras valodas uz kuru tulko, pirmais tulkojums ir sakne kokam
    Tulkojums* root = new Tulkojums;
    Tulkojums* tRoot = NULL;

    int a = 0;

    //Nolasa pirmo pusi tulkojumam
    while (1)
    {
        input.get(simbols);

        if (simbols == ' ')
        {
            break;
        }
        root->valoda_A[a] = simbols;
        a++;
    }

    a = 0;
    //Nolasa otru pusi tulkojumam
    while (1)
    {
        input.get(simbols);
        if (simbols == ' ')
        {
            continue;
        }
        if (simbols == '\n')
        {
            break;
        }
        root->valoda_B[a] = simbols;
        a++;
    }
    tRoot = root;

    Tulkojums* leftRoot = root;     //Kreis? apak?koka "ce?ojo?? sakne"
    Tulkojums* rightRoot = root;    //Lab? apak?koka "ce?ojo?? sakne"
    Tulkojums* stepBack = root;     //Nor?de uz iepriek??jo elementu 
    Tulkojums* tLeft = root;        //Nor?de uz pa?reiz?jo elementu (izmantots, lai p?rstaig?tu sarakstu, kur? ir visi tulkojuma v?rdi, kuri s?kas ar elementa s?kuma burtu)
    Tulkojums* tRight = root;       //Nor?de uz pa?reiz?jo elementu (izmantots, lai p?rstaig?tu sarakstu, kur? ir visi tulkojuma v?rdi, kuri s?kas ar elementa s?kuma burtu)

    bool beidzlasit = false;

    //Izveido bin?ro mekl??anas koku
    while (true)
    {
        Tulkojums* t = new Tulkojums;
        bool ieliktsVieta = false;

        char A;
        int a = 0;

        //Nolasa pirmo da?u no tulkojuma
        while (true)
        {
            input.get(A);   //Nolasa simbolu no faila
            //P?rbauda, vai nav sasniegta vieta fail?, kur beidzas tulkojumi (pirms tulko?anas virziena)
            if (A == '-' || A == '<' || A == '>')
            {
                beidzlasit = true;
                break;
            }
            //Ja ir atstarpe, tad ir nolas?ta pirm? tulkoja da?a
            if (A == ' ')
            {
                break;
            }
            t->valoda_A[a] = A;
            a++;
        }

        char B;
        int b = 0;
        //Nolasa otro da?u no tulkojuma
        while (true)
        {
            if (beidzlasit)
            {
                break;
            }

            input.get(B);   //Nolasa simbolu no faila
            if (B == ' ')
            {
                continue;
            }
            if (B == '\n')  //ja ir sasniegtas rindas beigas, tad tikko izveidotais elements ir j?pievieno kokam
            {
                //Izv?l?s virzienu, k?d? veidos koku (vai k?rtots tiks p?c A valodas vai B valodas)
                if (virziens[2] == '>')
                {
                    //P?rbauda, vai jaun? izveidot? tulkojuma pirmais burts sakr?t ar saknes pirmo burtu
                    //Ja sakr?t, tad jauno tulkojumu pievieno saknes saist?t? saraksta beig?s
                    if (t->valoda_A[0] == root->valoda_A[0])
                    {
                        tRoot->next = t;
                        tRoot = tRoot->next;
                        break;
                    }



                    if ((int)t->valoda_A[0] < (int)root->valoda_A[0])
                    {
                        if (root->left == NULL)
                        {
                            root->left = t;
                            break;
                        }
                        leftRoot = root->left;
                        while (1)
                        {
                            if (t->valoda_A[0] == leftRoot->valoda_A[0])
                            {
                                tLeft = leftRoot;
                                while (tLeft != NULL)
                                {
                                    stepBack = tLeft;
                                    tLeft = tLeft->next;
                                }
                                stepBack->next = t;
                                ieliktsVieta = true;
                                break;
                            }
                            if ((int)t->valoda_A[0] < (int)leftRoot->valoda_A[0])
                            {
                                if (leftRoot->left == NULL)
                                {
                                    leftRoot->left = t;
                                    leftRoot = root->left;
                                    ieliktsVieta = true;
                                    break;
                                }
                                else
                                {
                                    leftRoot = leftRoot->left;
                                    continue;
                                }
                            }
                            else
                            {
                                if (leftRoot->right == NULL)
                                {
                                    leftRoot->right = t;
                                    leftRoot = root->left;
                                    ieliktsVieta = true;
                                    break;
                                }
                                else
                                {
                                    leftRoot = leftRoot->right;
                                    continue;
                                }
                            }
                        }
                        if (ieliktsVieta)
                        {
                            break;
                        }
                    }
                    else
                    {
                        if (root->right == NULL)
                        {
                            root->right = t;
                            break;
                        }
                        rightRoot = root->right;
                        while (1)
                        {
                            if (t->valoda_A[0] == rightRoot->valoda_A[0])
                            {
                                tRight = rightRoot;
                                while (true)
                                {
                                    if (tRight->next == NULL)
                                    {
                                        tRight->next = t;
                                        ieliktsVieta = true;
                                        break;
                                    }
                                    tRight = tRight->next;
                                }
                                if (ieliktsVieta)
                                {
                                    break;
                                }

                            }
                            if ((int)t->valoda_A[0] < (int)rightRoot->valoda_A[0])
                            {
                                if (rightRoot->left == NULL)
                                {
                                    rightRoot->left = t;
                                    rightRoot = root->right;
                                    ieliktsVieta = true;
                                    break;
                                }
                                else
                                {
                                    rightRoot = rightRoot->left;
                                    continue;
                                }
                            }
                            else
                            {
                                if (rightRoot->right == NULL)
                                {
                                    rightRoot->right = t;
                                    rightRoot = root->left;
                                    ieliktsVieta = true;
                                    break;
                                }
                                else
                                {
                                    rightRoot = rightRoot->right;
                                    continue;
                                }
                            }
                        }
                        if (ieliktsVieta)
                        {
                            break;
                        }
                    }
                }
                else //Means from B TO A
                {

                    {
                        if (t->valoda_B[0] == root->valoda_B[0])
                        {
                            tRoot->next = t;
                            tRoot = tRoot->next;
                            break;
                        }



                        if ((int)t->valoda_B[0] < (int)root->valoda_B[0])
                        {
                            if (root->left == NULL)
                            {
                                root->left = t;
                                break;
                            }
                            leftRoot = root->left;
                            while (1)
                            {
                                if (t->valoda_B[0] == leftRoot->valoda_B[0])
                                {
                                    tLeft = leftRoot;
                                    while (tLeft != NULL)
                                    {
                                        stepBack = tLeft;
                                        tLeft = tLeft->next;
                                    }
                                    stepBack->next = t;
                                    ieliktsVieta = true;
                                    break;
                                }
                                if ((int)t->valoda_B[0] < (int)leftRoot->valoda_B[0])
                                {
                                    if (leftRoot->left == NULL)
                                    {
                                        leftRoot->left = t;
                                        leftRoot = root->left;
                                        ieliktsVieta = true;
                                        break;
                                    }
                                    else
                                    {
                                        leftRoot = leftRoot->left;
                                        continue;
                                    }
                                }
                                else
                                {
                                    if (leftRoot->right == NULL)
                                    {
                                        leftRoot->right = t;
                                        leftRoot = root->left;
                                        ieliktsVieta = true;
                                        break;
                                    }
                                    else
                                    {
                                        leftRoot = leftRoot->right;
                                        continue;
                                    }
                                }
                            }
                            if (ieliktsVieta)
                            {
                                break;
                            }
                        }
                        else
                        {
                            if (root->right == NULL)
                            {
                                root->right = t;
                                break;
                            }
                            rightRoot = root->right;
                            while (1)
                            {
                                if (t->valoda_B[0] == rightRoot->valoda_B[0])
                                {
                                    tRight = rightRoot;
                                    while (true)
                                    {
                                        if (tRight->next == NULL)
                                        {
                                            tRight->next = t;
                                            ieliktsVieta = true;
                                            break;
                                        }
                                        tRight = tRight->next;
                                    }
                                    if (ieliktsVieta)
                                    {
                                        break;
                                    }

                                }
                                if ((int)t->valoda_B[0] < (int)rightRoot->valoda_B[0])
                                {
                                    if (rightRoot->left == NULL)
                                    {
                                        rightRoot->left = t;
                                        rightRoot = root->right;
                                        ieliktsVieta = true;
                                        break;
                                    }
                                    else
                                    {
                                        rightRoot = rightRoot->left;
                                        continue;
                                    }
                                }
                                else
                                {
                                    if (rightRoot->right == NULL)
                                    {
                                        rightRoot->right = t;
                                        rightRoot = root->left;
                                        ieliktsVieta = true;
                                        break;
                                    }
                                    else
                                    {
                                        rightRoot = rightRoot->right;
                                        continue;
                                    }
                                }
                            }
                            if (ieliktsVieta)
                            {
                                break;
                            }
                        }
                    }
                }
            }
            t->valoda_B[b] = B;
            b++;
        }

        if (beidzlasit)
        {
            break;
            input.close();
        }

    }
    output.open("tulks.out", ios::out);

    /*curr = first;
    while (curr != NULL)
    {
        wordPrint(curr->vards);
        curr = curr->next;
    }*/


    if (virziens[2] == '>') //Means FROM A TO B
    {

        curr = first;

        while (curr->next->next != NULL)
        {
            bool exists = false;
            if (curr->vards[0] == root->valoda_A[0])
            {

                tRoot = root;

                while (tRoot != NULL)
                {

                    stepBack = tRoot;
                    int cnt = 0;
                    for (int i = 0; i < 21; i++)
                    {
                        if (curr->vards[i] == tRoot->valoda_A[i])
                        {
                            exists = true;
                        }
                        else
                        {
                            exists = false;
                            break;
                        }
                    }
                    if (exists)
                    {
                        break;
                    }
                    tRoot = tRoot->next;
                }
                if (exists)
                {
                    for (int i = 0; i < 21; i++)
                    {
                        if (tRoot->valoda_B[i] == '\0')
                        {
                            output << ' ';
                            break;

                        }
                        output << tRoot->valoda_B[i];
                    }
                }
                else
                {
                    output << '?';
                    for (int i = 0; i < 21; i++)
                    {
                        if (curr->vards[i] == '\0')
                        {
                            output << ' ';
                            break;
                        }
                        output << curr->vards[i];
                    }
                    curr = curr->next;
                }
            }



            if ((int)curr->vards[0] < (int)root->valoda_A[0])
            {

                leftRoot = root->left;
                while (true)
                {



                    if (curr->vards[0] == leftRoot->valoda_A[0])
                    {
                        tLeft = leftRoot;
                        while (tLeft != NULL)
                        {
                            int cnt = 0;
                            for (int i = 0; i < 21; i++)
                            {
                                if (curr->vards[i] == tLeft->valoda_A[i])
                                {

                                    exists = true;
                                }
                                else
                                {
                                    exists = false;
                                    break;
                                }
                            }
                            if (exists)
                            {
                                break;
                            }
                            tLeft = tLeft->next;
                        }
                        if (exists)
                        {
                            for (int i = 0; i < 21; i++)
                            {
                                if (tLeft->valoda_B[i] == '\0')
                                {
                                    output << ' ';
                                    break;
                                }
                                output << tLeft->valoda_B[i];
                            }
                        }
                        else
                        {
                            output << '?';
                            for (int i = 0; i < 21; i++)
                            {
                                if (curr->vards[i] == '\0')
                                {
                                    output << ' ';
                                    break;
                                }
                                output << curr->vards[i];
                            }

                            break;
                        }
                    }

                    if (leftRoot->left == NULL && leftRoot->right == NULL && exists == false)
                    {

                        output << '?';
                        for (int i = 0; i < 21; i++)
                        {

                            if (curr->vards[i] == '\0')
                            {
                                output << ' ';
                                break;
                            }
                            output << curr->vards[i];
                        }
                    }

                    if ((int)curr->vards[0] < (int)leftRoot->valoda_A[0])
                    {
                        if (leftRoot->left == NULL)
                        {

                            break;

                        }
                        leftRoot = leftRoot->left;
                    }
                    else
                    {
                        if (leftRoot->right == NULL)
                        {

                            break;
                        }
                        leftRoot = leftRoot->right;
                    }


                }

            }
            else
            {

                rightRoot = root->right;
                while (true)
                {




                    if (curr->vards[0] == rightRoot->valoda_A[0])
                    {

                        tRight = rightRoot;
                        while (tRight != NULL)
                        {
                            int cnt = 0;
                            for (int i = 0; i < 21; i++)
                            {

                                if (curr->vards[i] == tRight->valoda_A[i])
                                {

                                    cnt++;
                                }
                                else
                                {
                                    cnt = 0;
                                    break;
                                }
                            }


                            if (cnt == 21)
                            {
                                exists = true;
                                break;
                            }
                            else
                            {
                                tRight = tRight->next;
                            }

                        }
                        if (exists)
                        {
                            for (int i = 0; i < 21; i++)
                            {
                                if (tRight->valoda_B[i] == '\0')
                                {
                                    output << ' ';
                                    break;
                                }
                                output << tRight->valoda_B[i];
                            }
                        }
                        else
                        {
                            output << '?';
                            for (int i = 0; i < 21; i++)
                            {
                                if (curr->vards[i] == '\0')
                                {
                                    output << ' ';
                                    break;
                                }
                                output << curr->vards[i];
                            }
                            break;
                        }

                    }
                    if (rightRoot->left == NULL && rightRoot->right == NULL && exists == false)
                    {

                        output << '?';
                        for (int i = 0; i < 21; i++)
                        {

                            if (curr->vards[i] == '\0')
                            {
                                output << ' ';
                                break;
                            }
                            output << curr->vards[i];
                        }
                    }

                    if ((int)curr->vards[0] < (int)rightRoot->valoda_A[0])
                    {
                        if (rightRoot->left == NULL)
                        {
                            break;
                        }
                        rightRoot = rightRoot->left;
                    }
                    else
                    {
                        if (rightRoot->right == NULL)
                        {
                            break;
                        }
                        rightRoot = rightRoot->right;
                    }

                }
            }
            curr = curr->next;
        }
    }
    else
    {

        curr = first;

        while (curr->next->next != NULL)
        {
            bool exists = false;
            if (curr->vards[0] == root->valoda_B[0])
            {

                tRoot = root;

                while (tRoot != NULL)
                {

                    stepBack = tRoot;
                    int cnt = 0;
                    for (int i = 0; i < 21; i++)
                    {
                        if (curr->vards[i] == tRoot->valoda_B[i])
                        {
                            cnt++;
                        }
                        else
                        {
                            cnt = 0;
                            break;
                        }
                    }
                    if (cnt == 21)
                    {
                        exists = true;
                        break;
                    }
                    tRoot = tRoot->next;
                }
                if (exists)
                {
                    for (int i = 0; i < 21; i++)
                    {
                        if (tRoot->valoda_A[i] == '\0')
                        {
                            output << ' ';
                            break;
                        }
                        output << tRoot->valoda_A[i];
                    }
                }
                else
                {
                    output << '?';
                    for (int i = 0; i < 21; i++)
                    {
                        if (curr->vards[i] == '\0')
                        {
                            output << ' ';
                            break;
                        }
                        output << curr->vards[i];
                    }
                    curr = curr->next;
                }
            }



            if ((int)curr->vards[0] < (int)root->valoda_B[0])
            {

                leftRoot = root->left;
                while (true)
                {



                    if (curr->vards[0] == leftRoot->valoda_B[0])
                    {
                        tLeft = leftRoot;
                        while (tLeft != NULL)
                        {
                            int cnt = 0;
                            for (int i = 0; i < 21; i++)
                            {
                                if (curr->vards[i] == tLeft->valoda_B[i])
                                {
                                    cnt++;
                                }
                                else
                                {
                                    cnt = 0;
                                    break;
                                }
                            }
                            if (cnt == 21)
                            {
                                exists = true;
                                break;
                            }
                            tLeft = tLeft->next;
                        }
                        if (exists)
                        {
                            for (int i = 0; i < 21; i++)
                            {
                                if (tLeft->valoda_A[i] == '\0')
                                {
                                    output << ' ';
                                    break;
                                }

                                output << tLeft->valoda_A[i];
                            }
                        }
                        else
                        {
                            output << '?';
                            for (int i = 0; i < 21; i++)
                            {
                                if (curr->vards[i] == '\0')
                                {
                                    output << ' ';
                                    break;
                                }
                                output << curr->vards[i];
                            }

                            break;
                        }
                    }

                    if (leftRoot->left == NULL && leftRoot->right == NULL && exists == false)
                    {

                        output << '?';
                        for (int i = 0; i < 21; i++)
                        {

                            if (curr->vards[i] == '\0')
                            {
                                output << ' ';
                                break;
                            }
                            output << curr->vards[i];
                        }
                    }

                    if ((int)curr->vards[0] < (int)leftRoot->valoda_B[0])
                    {
                        if (leftRoot->left == NULL)
                        {

                            break;

                        }
                        leftRoot = leftRoot->left;
                    }
                    else
                    {
                        if (leftRoot->right == NULL)
                        {

                            break;
                        }
                        leftRoot = leftRoot->right;
                    }


                }

            }
            else
            {

                rightRoot = root->right;
                while (true)
                {




                    if (curr->vards[0] == rightRoot->valoda_B[0])
                    {

                        tRight = rightRoot;
                        while (tRight != NULL)
                        {
                            int cnt = 0;
                            for (int i = 0; i < 21; i++)
                            {

                                if (curr->vards[i] == tRight->valoda_B[i])
                                {

                                    cnt++;
                                }
                                else
                                {
                                    cnt = 0;
                                    break;
                                }
                            }


                            if (cnt == 21)
                            {
                                exists = true;
                                break;
                            }
                            else
                            {
                                tRight = tRight->next;
                            }

                        }
                        if (exists)
                        {
                            for (int i = 0; i < 21; i++)
                            {
                                if (tRight->valoda_A[i] == '\0')
                                {
                                    output << ' ';
                                    break;

                                }
                                output << tRight->valoda_A[i];
                            }
                        }
                        else
                        {
                            output << '?';
                            for (int i = 0; i < 21; i++)
                            {
                                if (curr->vards[i] == '\0')
                                {
                                    output << ' ';
                                    break;
                                }
                                output << curr->vards[i];
                            }
                            break;
                        }

                    }
                    if (rightRoot->left == NULL && rightRoot->right == NULL && exists == false)
                    {

                        output << '?';
                        for (int i = 0; i < 21; i++)
                        {

                            if (curr->vards[i] == '\0')
                            {
                                output << ' ';
                                break;
                            }
                            output << curr->vards[i];
                        }
                    }

                    if ((int)curr->vards[0] < (int)rightRoot->valoda_B[0])
                    {
                        if (rightRoot->left == NULL)
                        {
                            break;
                        }
                        rightRoot = rightRoot->left;
                    }
                    else
                    {
                        if (rightRoot->right == NULL)
                        {
                            break;
                        }
                        rightRoot = rightRoot->right;
                    }

                }
            }
            curr = curr->next;
        }
    }
    output.close();         //Aizver 
}
