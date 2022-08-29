#include<iostream>
#include<fstream>
#include<list>
using namespace std;
void print(const list<int> &a) {
    for(auto i=a.begin();i!=a.end();i++) {
        cout<<*i<<" ";
       }
    cout << endl;
}

bool monotounusstrong( list<int> &a) {
bool ismono;
auto it = a.begin();
auto nx = next(it, 1);

for(auto i=it;i!=prev(a.end(),1);i++) {
        if(*i<*next(i,1)){ismono = true;
        }else{
        ismono = false;
        break;}
}return ismono;}

int main() {
    list<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(9);
    a.push_back(12);
    print(a);
    cout << monotounusstrong(a) << endl;
    a.push_back(1);
    print(a);
    cout << monotounusstrong(a) << endl;
    a.erase(a.begin(), a.end());
    print(a);
    }
