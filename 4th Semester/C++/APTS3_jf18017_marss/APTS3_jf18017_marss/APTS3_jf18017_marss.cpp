#include <iostream>
#include <fstream>
using namespace std;

//Objekts Alien, kuram ir divas norâdes
//Viena uz bçrnu-labroci
//Otra uz bçrnu-kreili
//Un marsieða unikâlu ID
struct Alien
{
    Alien* left = NULL;
    Alien* right = NULL;
    int id;
};

//Objekts InOrder, kurð kalpos kâ divvirziena saistîtâ sarkasta objekts
struct InOrder
{
    InOrder* prev = NULL;
    long long int inorder;
    InOrder* next = NULL;
};


//Funkcija, kura atgrieþ norâdi uz virsotni, kurai id sakrît ar meklçto
Alien* findNode(Alien* root, int info)
{
    if (root == NULL) return NULL;

    if (root->id == info) return root;

    Alien* found = findNode(root->left, info);
    if (found != NULL) return found;

    return findNode(root->right, info);
}


//Funkcija, kura izveido divvirziena saistîto sarakstu, priekð virsotòu apmeklçðanas InOrder
//Nepietika laika izdomât kâ izdarît ðo bez saistîtâ saraksta, jo koks neveidojas kâ BST
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

    //Pârbauda, vai fails ir tukðs
    if (input.peek() == EOF)
    {
        //Ja ir, tad atver izvedes failu un ieraksta tur "nothing"
        output.open("aliens.out", ios::out);
        output << "nothing";
        output.close();
        input.close();
        return 0;
    }
    
    
    //Nolasa pirmâ elementa vçrtîbu (root / Ancesstor)
    
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

        //Ja komanda ir tikusi nolasîta kâ F, tad programma beidz darboties
        if (komanda == 'F')
        {
            break;
        }

        //Ja ir nolasîts L, tad
        else if (komanda == 'L')
        {
            for (int i = 0; i < 6; i++)
            {
                oldBerns[i] = '\0';
                oldVecaks[i] = '\0';
            }
            input.get(simb);

            //Nolasa Pirmo skaitli (vecâku)
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
            
            //Nolasa ortru skaitli (bçrnu)
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
            
            //Ja bçrns ir ar tâdu paðu numuru kâ vecâks, tad izvades failâ ieraksta error1
            if (vecaks == berns)
            {
                output << "error1" << endl;
                continue;
            }

            //Pârbauda vai vecâks eksistç jau kokâ, ja neeksistç tad izvades failâ ieraksta error2
            Alien* err = findNode(Ancestor, vecaks);
            
            if (err == NULL)
            {
                output << "error2" << endl;
                continue;
            }

            //Pârbauda vai bçrns jau eksistç kokâ, ja eksistç tad izvades failâ ieraksta error3
            if (findNode(Ancestor, berns) != NULL) 
            {
                output << "error3" << endl;
                continue;
            }

            curr = findNode(Ancestor, vecaks);

            //Pârbauda vai vecâka bçrns-kreilis jau eksistç, ja eksistç, tad izvades failâ ieraksta error4
            if (curr->left != NULL)
            {
                output << "error4" << endl;
                continue;
            }
            else
            {
                //Ja neeksistç, taad pievieno bçrnu - kreili
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

        //Ja nolasa ?, tad ir jâatrod marsieða mîïâkie vecâki (prev un next inorder)
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
            
            //Ja nolasîtiâ virsotne neeksistç kokâ, izvads failâ ieraksta error0
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


            //Pârstaigâ visas virsotnes inorder un ieraksta failâ  prev un next
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
