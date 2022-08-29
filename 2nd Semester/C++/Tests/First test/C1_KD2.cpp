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
    void add_element (int n);   //Pievieno elementu saraksta beig�s
    void delete_element();      //Izdz�� elementu no s�kuma
    bool is_empty() { return (first==NULL); };     //P�rbauda vai saraksts ir tuk�
    void start() { current = first; };      //novieto nor�di current saraksta s�kum�
    bool end() {return (current==NULL); };  //P�rbauda vai ir sasniegtas saraksta beigas
    void next() { if(!end())current = current -> next; };
    ///Metodes, kas pieliktas kl�t klasei List
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

    cout << "Ievad�tais saraksts: ";
    l.print ();
    l.deleteFirstNotUnique();
    l.print();
    ///Saraksta izdz��ana
    while (!l.is_empty())
    {
        l.delete_element ();
    };
    l.print();

}

void List::add_element (int n)
{//Maina current v�rt�bu, lai r�d�tu uz jebkuru elementu
    Node *p = new Node (n);
    if (first== NULL) first = last = p;
    else last = last -> next = p;
    current = p;
};

void List::delete_element()
{//saglab� current v�rt�bu (nomaina uz s�kumu, ja r�d�ja izmetamo)
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


///�is ir actually viss ko man vajag kontroldarbam
void List::deleteFirstNotUnique()
{
    start();                    //Novieto nor�di current uz pirmo elementu
    current = current ->next;   //P�rvieto current uz n�kamo, lai programma nep�rbaud�tu vai pirmais elements ir vien�ds pats ar sevi
    while(1)
    {
        if(first->num==current->num)    //Ja pirm� elementa v�rt�ba ir vien�da ar current v�rt�bu tad no saraksta var izdz�st pirmo elementu
        {
            delete_element();
        }
    if(current->next == NULL)break;     //Ja n�kamais current ir NULL, tas noz�m�, ka ir sasniegtas saraksta beigas un cikls ir j�p�rtrauc
    current = current -> next;
    }

}
