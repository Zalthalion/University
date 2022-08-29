#include<iostream>
#include<fstream>
#include<cctype>
#include "lvfriendly.h"
using namespace std;
int countDigitLines(fstream &f){
    string s;
    int cnt = 0;
    while(getline(f,s))
    {

    for(int i=0; i<s.length();i++)
        {
            if (isdigit(s[i]))
            {
                cnt++;
                break;
            }
        }

    }return cnt;
}
int main(){

 fstream f("digits.txt");


 cout << countDigitLines(f) << endl;


return 0;
}
