#include <iostream>
using namespace std;

template <typename T>

class Node
{
public:
    T val;
    Node <T> *next;
    Node (T n) { val = n; next = NULL; };
};

template <typename T>

class List
{
protected:
    Node<T>  *first, *last;
public:
    Node<T> *current;
public:
    List();             //Konstruktors izveido tukðu sarakstu
    ~List();            //Destruktors iztukðo sarakstu un atbrîvo atmiòu
    void add_element (T n); //Pieliek mezglu saraksta beigâs
    void delete_element (); //Izmet mezglu no saraksta sâkuma
    bool is_empty();        //Noskaidro vai saraksts ir tukðs
    Node<T> *begin();       //Atgrieþ râdîtâju uz saraksta sâkumu
    Node<T> *end();         //Atgrieþ râdîtâju uz saraksta beigâm (pçc pçdçjâ elementa)
    List& operator++(int i=0);
    void firstNotUnique();
    void print ();
};

int main()
{
    List<int> v;
    List<float> p;

    int elemSk;
    int a;

    cout << "Ievadi cik elementus vçlies ievadît: ";
    cin >> elemSk;

    cout << endl;

    for (int i = 0; i<elemSk; i=i+1)
    {
        cout << "Ievadi saraksta " << i+1 << ". elementu: ";
        cin >> a;
        v.add_element(a);

    }
cout << endl;
cout << "Ievadîtais saraksts:";
v.print();

v.firstNotUnique();
cout << endl;
cout <<"Atjaunotais saraksts: ";
v.print();
while(!v.is_empty()){
            v.delete_element();
        };

        return 0;
}


template <typename T>
List<T>::List()
{
    first = last = current = NULL;
}

template <typename T>
List<T>::~List()
{
     while(!is_empty()){delete_element ();}
}

///Add element
template <typename T>
void List<T>::add_element (T n) // pieliek mezglu saraksta beigâs
{
 Node<T> *p = new Node<T> (n);
 if (first == NULL) first = last = p;
 else last = last -> next = p;
 current =p; // maina current vçrtîbu, lai râdîtu uz jauno elementu
}

///Delete element
template <typename T>
void List<T>::delete_element () // izmet mezglu no saraksta sâkuma
{
 Node<T> *p = first;
 if(!is_empty())
 { if (current == first) current = first-> next;// saglabâ current vçrtîbu (nomaina uz sâkumu,ja râdîja uz izmetamo)
 first = first -> next;
 delete p;
 if(is_empty())last = NULL;
 }
};

template <typename T>
bool List<T>::is_empty () // noskaidro, vai saraksts ir tukðs
 {return (first == NULL);};

template <typename T>
Node<T> *List<T>::begin()
{
    return first;
}

template <typename T>
Node<T> *List<T>::end()
{
    return NULL;
}

template <typename T>
List<T>& List<T>::operator++(int i=0)
{
    if (current !=NULL) current = current->next;
    return *this;
}
template <typename T>
void List<T>::print()  // izdrukâ saraksta elementus
 {
     for (current=begin();current!=end();current = (current!=end()?current -> next:current))
         cout<<current->val<<' ';
 }

 template <typename T>
 void List<T>::firstNotUnique()
 {
      Node<T> *p = first;
      int vertiba = p->val;
      current = begin();
      current = current->next;
      for (current;current!=end();current = (current!=end()?current -> next:current))
      {
        if(vertiba == current->val)
        {
            delete_element();
            return;
        }
      }

 }
