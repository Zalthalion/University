/*************************************************
MD9. Lietot�js ievada 20 veselus skait�us. Noskaidrot, cik no tiem vien�di ar p�d�jo ievad�to skaitli.
*************************************************/
#include <iostream>
#include "lvfriendly.h"
using namespace std;

int main(){
int ar[19];

for(int i=0; i<20; i++){
    cout << "ievadi " << i+1 <<". skaitli!"<< endl;
    cin >> ar[i];
}
for (int i=0; i<20; i++){
    if (ar[i] == ar[i+1])
        cout << i+1 << " un "<< i+2 << ": " << ar[i] << endl;
}
delete[]ar;
}
