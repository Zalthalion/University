#include <iostream>
#include "lvfriendly.h"
using namespace std;

int main(){
int sk1, sk2, sk;
int vien1, vien2, vien3;
int cip1, cip2, cip3;

do{
        cout << "Ievadi pirmo skaitli:" << endl;
        cin >> sk1;
}while (sk1<0);

do{
        cout << "Ievadi otro skaitli:" << endl;
        cin >> sk2;
}while (sk2<0);

do{
        cout << "Ievadi treðo skaitli:" << endl;
        cin >> sk3;
}while (sk3<0);

    vien1 = 0;
    vien2 = 0;
    vien3 = 0;
do{
    cip = sk1%10;
    if (cip = 1) vien1++ ;
    sk = sk1/10;
}while (sk1=0);

do{
    cip = sk2%10;
    if (cip = 1) vien2++ ;
    sk = sk2/10;
}while (sk2=0);

do{
    cip = sk3%10;
    if (cip = 1) vien3++ ;
    sk = sk3/10;
}while (sk3=0);

if()
}
