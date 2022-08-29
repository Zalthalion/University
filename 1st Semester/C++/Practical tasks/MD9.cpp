/*************************************************
MD9. Lietotâjs ievada 20 veselus skaitïus. Noskaidrot, cik no tiem vienâdi ar pçdçjo ievadîto skaitli.
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
