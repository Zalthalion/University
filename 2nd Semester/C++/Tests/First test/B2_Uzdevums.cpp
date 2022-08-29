#include <iostream>
#include <fstream>
#include<cctype>
#include "lvfriendly.h"
using namespace std;
int countlines(ifstream &f, ofstream &f2){
    string s;
    int cnt = 0;
    while(getline(f,s))
    {
        for(int i=0; i<s.length();i++)
        {
            if (isdigit(s[i]))
            {
                cnt++;
                f2<<s<<endl;
                break;
            }
        }
    }

return cnt;
}
    int main()
    {
    ifstream f("digits.txt");
    ofstream f2("digits2.txt");
    cout<<countlines(f, f2)<< endl;
    f.close();
    f2.close();

return 0;
}
