#include<iostream>
#include<map>
#include<vector>
#include"lvfriendly.h"
using namespace std;

int countwords(const vector<string>&v)
{
    map <string, int> m;
    for (const auto &i:v)
    {
        m[i]+=1;
    }
    auto pmin = m.begin();
    int min = pmin->second;
    for (auto it = m.begin(); it!=m.end();++it)
    {
        if(it->second<min)
        {
            min = it->second;
        }
    }
        for (auto it = m.begin(); it!=m.end();++it)
        {
            if(it->second==min)
            {
                cout << "Visretâk sastopamais vârds ir: ";
                cout<<it->first;
                cout <<" sastopams " <<it->second <<" reizes"<<endl;
            }
        }
}


int main()
{
    vector <string>s = {"life", "is", "life"};
    countwords(s);
    return 0;
}

