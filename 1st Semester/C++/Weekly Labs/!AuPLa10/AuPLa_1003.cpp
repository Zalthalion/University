#include<iostream>
#include"lvfriendly.h"
using namespace std;

int cipliel5(int n){
if(n == 0) return 0;
if ((n%10) > 5) return cipliel5(n/10)+n%10;
else return cipliel5(n/10);
}

int main(){
    int n;
    int rez;
    cout << "Ievadi skaitli" << endl;
    cin >> n;

    rez = cipliel5(n);
    cout << rez << endl;
    return 0;
}
