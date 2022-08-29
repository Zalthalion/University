#include<iostream>
#include"lvfriendly.h"
using namespace std;


int pirmsk(int a){
bool b1;
int vd, dali = 1;
int daliSk = 0;
    do{vd=a%dali;
    if(vd==0) daliSk++;
    dali++;
    }while (dali <= a);
    b1 = daliSk == 2;
    return b1 ;
}

int main(){
    int sk, primsum, test;
    primsum = 0;
for(int i = 0; i<10; i++){
cout << "ievadi "<< i+1 << ". skaitli" << endl;
cin >> sk;
test = pirmsk(sk);
if (test == 1) primsum = primsum + sk;
}
cout << primsum << endl;
}
