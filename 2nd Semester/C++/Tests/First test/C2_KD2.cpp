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
    List();             //Konstruktors izveido tuk�u sarakstu
    ~List();            //Destruktors iztuk�o sarakstu un atbr�vo atmi�u
    void add_element (T n); //Pieliek mezglu saraksta beig�s
    void delete_element (); //Izmet mezglu no saraksta s�kuma
    bool is_empty();        //Noskaidro vai saraksts ir tuk�s
    Node<T> *begin();       //Atgrie� r�d�t�ju uz saraksta s�kumu
    Node<T> *end();         //Atgrie� r�d�t�ju uz saraksta beig�m (p�c p�d�j� elementa)
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

    cout << "Ievadi cik elementus v�lies ievad�t: ";
    cin >> elemSk;

    cout << endl;

    for (int i = 0; i<elemSk; i=i+1)
    {
        cout << "Ievadi saraksta " << i+1 << ". elementu: ";
        cin >> a;
        v.add_element(a);

    }
cout << endl;
cout << "Ievad�tais saraksts:";
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
void List<T>::add_element (T n) // pieliek mezglu saraksta beig�s
{
 Node<T> *p = new Node<T> (n);
 if (first == NULL) first = last = p;
 else last = last -> next = p;
 current =p; // maina current v�rt�bu, lai r�d�tu uz jauno elementu
}

///Delete element
template <typename T>
void List<T>::delete_element () // izmet mezglu no saraksta s�kuma
{
 Node<T> *p = first;
 if(!is_empty())
 { if (current == first) current = first-> next;// saglab� current v�rt�bu (nomaina uz s�kumu,ja r�d�ja uz izmetamo)
 first = first -> next;
 delete p;
 if(is_empty())last = NULL;
 }
};

template <typename T>
bool List<T>::is_empty () // noskaidro, vai saraksts ir tuk�s
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
void List<T>::print()  // izdruk� saraksta elementus
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
