#include<iostream>
#include"lvfriendly.h"
using namespace std;

int maxSk(int x){
int cip;
int max = 0;
cip = x%10;
if(cip > max) max = cip;
cip = cip / 10;
return max;
}


int main(){
    int x, rez, ok;
    do{

    cout << "ievadi skaitli!" << endl;
        cin >> x;
        rez = maxSk(x);
        cout << rez << endl;


    cout << "vai v�laties izpild�t programmu v�lreiz> (j� = 1 un n� = 0)" << endl;
    cin >> ok;
    }while(ok == 1);
}
