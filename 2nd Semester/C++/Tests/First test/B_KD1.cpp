#include <fstream>
#include <iostream>
using namespace std;

int countLinesSymetric(fstream &f)
{
    string rin;
    int countLines = 0;
    f.open("f.txt", ios::in);
    getline (f,rin);
    while(f)
    {
        int rinIzm = rin.size();
        int i = 0;
        int j = rinIzm-1;
        while(i!=rinIzm/2)
        {
        if(rin[i]==rin[j])
        {
        i++;
        j--;


        if(i==rinIzm/2 ||j==rinIzm/2)
        {
            countLines++;
            break;
        }
        }else break;

        }

        getline(f,rin);
    }
    cout << countLines;
}


int main()
{
    fstream f;

    countLinesSymetric(f);
}
