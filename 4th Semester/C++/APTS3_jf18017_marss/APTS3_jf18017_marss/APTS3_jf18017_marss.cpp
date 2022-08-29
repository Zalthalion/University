#include <iostream>
#include <fstream>
using namespace std;

//Objekts Alien, kuram ir divas nor�des
//Viena uz b�rnu-labroci
//Otra uz b�rnu-kreili
//Un marsie�a unik�lu ID
struct Alien
{
    Alien* left = NULL;
    Alien* right = NULL;
    int id;
};

//Objekts InOrder, kur� kalpos k� divvirziena saist�t� sarkasta objekts
struct InOrder
{
    InOrder* prev = NULL;
    long long int inorder;
    InOrder* next = NULL;
};


//Funkcija, kura atgrie� nor�di uz virsotni, kurai id sakr�t ar mekl�to
Alien* findNode(Alien* root, int info)
{
    if (root == NULL) return NULL;

    if (root->id == info) return root;

    Alien* found = findNode(root->left, info);
    if (found != NULL) return found;

    return findNode(root->right, info);
}


//Funkcija, kura izveido divvirziena saist�to sarakstu, priek� virsot�u apmekl��anas InOrder
//Nepietika laika izdom�t k� izdar�t �o bez saist�t� saraksta, jo koks neveidojas k� BST
void findPredecessor(Alien* root, InOrder* &start, InOrder* &t, InOrder* &last)
{
    if (root == NULL)
        return;

    findPredecessor(root->left, start, t, last);

    t = new InOrder;
    start->next = t;
    t->prev = start;
    t->inorder = root->id;
    start = start->next;

    findPredecessor(root->right, start, t, last);
}


int main()
{
	fstream input;
	fstream output;

	input.open("aliens.in");        //Atver ievades failu

    //P�rbauda, vai fails ir tuk�s
    if (input.peek() == EOF)
    {
        //Ja ir, tad atver izvedes failu un ieraksta tur "nothing"
        output.open("aliens.out", ios::out);
        output << "nothing";
        output.close();
        input.close();
        return 0;
    }
    
    
    //Nolasa pirm� elementa v�rt�bu (root / Ancesstor)
    
    char s;
    char CharAncestor[6] = { '\0' };
    
    int i = 0;
    while (true)
    {
        input.get(s);
        if (s == ' ' || s == '\n')
        {
            break;
        }
        CharAncestor[i] = s;
        i++;
    }
    
    int anc = atoi(CharAncestor); 

    
    //izveido root objektu
    Alien* Ancestor = new Alien;
    Ancestor->id = anc;
    Ancestor->left = NULL;
    Ancestor->right = NULL;


    char oldVecaks[6] = { '\0' };
    char oldBerns[6] = { '\0' };

    int vecaks;
    int berns;
    char simb;

    output.open("aliens.out", ios::out);

    Alien* curr = NULL;
    while (!input.eof())
    {
        char komanda;

        input.get(komanda);
        if (komanda == '\n') continue;

        //Ja komanda ir tikusi nolas�ta k� F, tad programma beidz darboties
        if (komanda == 'F')
        {
            break;
        }

        //Ja ir nolas�ts L, tad
        else if (komanda == 'L')
        {
            for (int i = 0; i < 6; i++)
            {
                oldBerns[i] = '\0';
                oldVecaks[i] = '\0';
            }
            input.get(simb);

            //Nolasa Pirmo skaitli (vec�ku)
            int a = 0;
            while (true)
            {
                input.get(simb);
                
                if (simb == ' ' || simb == '\n')
                {
                    break;
                }

                oldVecaks[a] = simb;
                a++;
            }
            vecaks = atoi(oldVecaks);
            
            //Nolasa ortru skaitli (b�rnu)
            a = 0;
            while (true)
            {
                input.get(simb);
                if (simb == ' ')continue;
                else
                {
                   
                    if (simb == '\n')
                    {
                        break;
                    }
                    oldBerns[a] = simb;
                    a++;
                }
            }
            berns = atoi(oldBerns);
            
            //Ja b�rns ir ar t�du pa�u numuru k� vec�ks, tad izvades fail� ieraksta error1
            if (vecaks == berns)
            {
                output << "error1" << endl;
                continue;
            }

            //P�rbauda vai vec�ks eksist� jau kok�, ja neeksist� tad izvades fail� ieraksta error2
            Alien* err = findNode(Ancestor, vecaks);
            
            if (err == NULL)
            {
                output << "error2" << endl;
                continue;
            }

            //P�rbauda vai b�rns jau eksist� kok�, ja eksist� tad izvades fail� ieraksta error3
            if (findNode(Ancestor, berns) != NULL) 
            {
                output << "error3" << endl;
                continue;
            }

            curr = findNode(Ancestor, vecaks);

            //P�rbauda vai vec�ka b�rns-kreilis jau eksist�, ja eksist�, tad izvades fail� ieraksta error4
            if (curr->left != NULL)
            {
                output << "error4" << endl;
                continue;
            }
            else
            {
                //Ja neeksist�, taad pievieno b�rnu - kreili
                curr->left = new Alien;
                curr->left->id = berns;
                continue;
            }

        }

        //Tas pats, kas kreilim, tikai labrocim
        else if (komanda == 'R')
        {
            input.get(simb);
            for (int i = 0; i < 6; i++)
            {
                oldBerns[i] = '\0';
                oldVecaks[i] = '\0';
            }
            //input.get(simb);
            int a = 0;
            while (true)
            {
                input.get(simb);
                
                if (simb == ' ' || simb == '\n')
                {
                    break;
                }

                oldVecaks[a] = simb;
                a++;

            }
            vecaks = atoi(oldVecaks);
            
            a = 0;
            while (true)
            {
                input.get(simb);
                if (simb == ' ')continue;
                else
                {

                    if (simb == '\n')
                    {
                        break;
                    }
                    oldBerns[a] = simb;
                    a++;
                }
            }
            berns = atoi(oldBerns);
            
            

            if (vecaks == berns)
            {
                output << "error1" << endl;
                continue;
            }

            
            Alien* err = findNode(Ancestor, vecaks);

            if (err == NULL)
            {
                output << "error2" << endl;
                continue;
            }

            if (findNode(Ancestor, berns) != NULL)
            {
                output << "error3" << endl;
                continue;
            }

            curr = findNode(Ancestor, vecaks);

            if (curr->right != NULL)
            {
                output << "error5" << endl;
                continue;
            }
            else
            {
                curr->right = new Alien;
                curr->right->id = berns;
                continue;
            }

            
        }

        //Ja nolasa ?, tad ir j�atrod marsie�a m���kie vec�ki (prev un next inorder)
        else if (komanda == '?')
        {
            
            for (int i = 0; i < 6; i++)
            {
            oldBerns[i] = '\0';
            }
            int a = 0;

            //Nolasa, kurai virsotnei atrast prev un next inorder virsotnes
            while (true)
            {
                input.get(simb);

                berns = (int)simb - 48;
                if (simb == '\n')
                {
                    break;
                }
                oldBerns[a] = simb;
                a++;
            }
            berns = atoi(oldBerns);
            
            //Ja nolas�ti� virsotne neeksist� kok�, izvads fail� ieraksta error0
            if (findNode(Ancestor, berns) == NULL)
            {
                output << "error0" << endl;
                continue;
            }


            InOrder* start = new InOrder;
            InOrder* t;
            InOrder* last;

            findPredecessor(Ancestor, start, t, last);
            
            long long int predecessor = 0;
            long long int successor = 0;


            //P�rstaig� visas virsotnes inorder un ieraksta fail�  prev un next
            while (t->prev != NULL) 
            {
                if (t->inorder == berns)
                {
                    if (t->prev->prev != NULL)
                    {
                        predecessor = t->prev->inorder;
                    }
                    if (t->next != NULL)
                    {
                        successor = t->next->inorder;
                    }
                    break;
                }
                
                t = t->prev;
            }
            
            output << predecessor << ' ' << successor << endl;
        }   
    }
    output.close();
    return 0;
}
