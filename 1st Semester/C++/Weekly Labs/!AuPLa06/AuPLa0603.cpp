
#include<iostream>
#include"lvfriendly.h"
using namespace std;


int main(){
int *arr;
int *maxV;
int n, ok;
int maks = 0;
int maksskaits = 0;

do{
do{
cout<< "Ievadi mas�va izm�ru" << endl;
cin >> n;
if (n<1) cout << "Skaitlim ir j�b�t liel�kam par 0" << endl;
}while (n<1);

arr = new int[n];
maxV = new int[n];

for(int i = 0; i<n; i++){
    cout << "Ievadi " << i+1 <<". skaitli" << endl;
    cin >> arr[i];
}
for(int i = 0; i<n; i++){
    if (arr[i]>maks) maks = arr[i];
}
for (int i=0;i<n;i++)
    {
        if(arr[i]==maks)
            {maxV[maksskaits]=i;maksskaits++;}
    }
    cout << "Maksim�l� v�rt�ba: " << maks << endl;
    cout << "Atra�an�s poz�cija: " << endl;
for (int i = 0;i<maksskaits;i++)
    {
        cout << maxV[i] + 1 << ' ';
    }
    delete []arr;
    delete []maxV;
    cout << endl;
    cout << "V�lreiz? (j�=1 un n� =0)" << endl;
    cin >> ok;
}while(ok==1);
}
