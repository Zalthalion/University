#include<iostream>
#include"lvfriendly.h"
using namespace std;

int cip_skaits(int n)
{
    int cskaits=0;
    if (n<0)n=-n;
    do
    {
     n/=10;
     cskaits++;
    }while(n>0);
    return cskaits;
}

int main(){
    int n;
    int *skaitli;
    int *cipskaiti;
    int ok;
    do{
cout << "ievadi masîva izmçru" << endl;
cin >> n;

    skaitli = new int[n];
    cipskaiti = new int[n];

    for (int i=0;i<n;i++)
    {
        cout << "Ievadiet " <<i+1<< ". veselu skaitli:" << endl;
        cin >> skaitli[i];

    }
    for(int i=0;i<n;i++)
    {
        cipskaiti[i]=cip_skaits(skaitli[i]); //izveido jaunu masîvu, kuram locekïi ir ciparu skaiti
    }
    cout << "Katra ievadîtâ skaitïa ciparu skaiti:" <<endl;
    for (int i=0;i<n;i++)
    {
        cout << cipskaiti[i] << ' ';
    }

    delete []skaitli;
    delete [] cipskaiti;
    cout << endl;
    cout<< "vçlreiz?" << endl;
    cin >> ok;
    }while (ok==1);
}
