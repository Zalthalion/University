#include<iostream>
#include<fstream>
#include<list>
using namespace std;
void print(const list<int> &a) {
    for(auto i=a.begin();i!=a.end();i++) {
        cout<<*i<<" ";   }
    cout<<endl;
}
void insertlast2(list<int> &a, int n){
if(a.size()==1)return;
a.emplace(prev(a.end(),2), n);
}

int main() {
    list<int> a;
    a.push_back(8);
//    a.push_back(4);
//    a.push_back(6);
//    a.push_back(5);
    print(a);
    insertlast2(a, 99);
    print(a);
    a.push_back(1);
    insertlast2(a, 99);
    print(a);

    a.erase(a.begin(),a.end());
    print(a);
}

