#include <iostream>
#include "lvfriendly.h"
using namespace std;

// Klase node - saraksta mezgls
class Node
{
public:
int num;
Node *next;
Node (int n) { num = n; next = NULL; };
};

class List
{
protected:
    Node *first;
    Node *last;
public:
    Node *current;
public:
    List () { first = last = current = NULL; };
    void add_element (int n);   //Pievieno elementu saraksta beigâs
    void delete_element();      //Izdzçð elementu no sâkuma
    bool is_empty() { return (first==NULL); };     //Pârbauda vai saraksts ir tukð
    void start() { current = first; };      //novieto norâdi current saraksta sâkumâ
    bool end() {return (current==NULL); };  //Pârbauda vai ir sasniegtas saraksta beigas
    void next() { if(!end())current = current -> next; };
    ///Metodes, kas pieliktas klât klasei List
    void deleteFirstNotUnique();
    void print();
};

int main()
{
    List l;
    int k;

    cout << "Ievadi saraksta elementu 0,lai beigtu"<<endl;
    cin >>k;
    while (k!=0)
    {
        l.add_element (k);
        cout << "Ievadi saraksta elementu 0,lai beigtu"<<endl;
        cin >> k;
    };

    cout << "Ievadîtais saraksts: ";
    l.print ();
    l.deleteFirstNotUnique();
    l.print();
    ///Saraksta izdzçðana
    while (!l.is_empty())
    {
        l.delete_element ();
    };
    l.print();

}

void List::add_element (int n)
{//Maina current vçrtîbu, lai râdîtu uz jebkuru elementu
    Node *p = new Node (n);
    if (first== NULL) first = last = p;
    else last = last -> next = p;
    current = p;
};

void List::delete_element()
{//saglabâ current vçrtîbu (nomaina uz sâkumu, ja râdîja izmetamo)
    Node *p = first;
    if(!is_empty())
    {
        if(current == first) current = first -> next;
        first = first -> next;
        delete p;
        if (is_empty()) last = NULL;
    }
};

void List::print()
{
    for(start(); !end();next())
        cout << current->num << ' ';
    cout << endl;
}


///Ðis ir actually viss ko man vajag kontroldarbam
void List::deleteFirstNotUnique()
{
    start();                    //Novieto norâdi current uz pirmo elementu
    current = current ->next;   //Pârvieto current uz nâkamo, lai programma nepârbaudîtu vai pirmais elements ir vienâds pats ar sevi
    while(1)
    {
        if(first->num==current->num)    //Ja pirmâ elementa vçrtîba ir vienâda ar current vçrtîbu tad no saraksta var izdzçst pirmo elementu
        {
            delete_element();
        }
    if(current->next == NULL)break;     //Ja nâkamais current ir NULL, tas nozîmç, ka ir sasniegtas saraksta beigas un cikls ir jâpârtrauc
    current = current -> next;
    }

}
