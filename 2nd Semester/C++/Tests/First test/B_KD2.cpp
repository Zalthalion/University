#include <iostream>
#include "lvfriendly.h"
#include <map>
#include <vector>
using namespace std;

int countOfMostFrequentWordInSentence(const vector<string> &v)
{
    map<string, int> m;
    int maks = 0;

    for(const auto &i: v)
    {
        m[i]+=1;
    }

    for (auto it = m.begin(); it != m.end(); ++it)
    {
    if (it->second > maks)
        {
        maks = it->second;
        }
    }
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        if(it->second==maks)
        {
        cout << "Visbieþâk sastopamais vârd ir: ";
        cout << it->first;
        cout << " (sastopams " << it->second << " reizes)" << endl;
        }
    }
}

int main() {
    vector<string> s={"life","is","ok","but","life","is","life"};
    countOfMostFrequentWordInSentence(s);

}


