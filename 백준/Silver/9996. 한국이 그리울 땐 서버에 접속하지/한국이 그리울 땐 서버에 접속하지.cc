#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string pat;
string str;
string pfix;
string sfix;
int cnt;
int starIdx;

void findKeys()
{
    starIdx = pat.find('*');
    
    pfix = pat.substr(0, starIdx);
    sfix = pat.substr(starIdx + 1);
}

void checkFiles()
{
    for (int i = 0; i < cnt; i++)
    {
        cin >> str;
        
        if (pfix.size() + sfix.size() > str.size()) 
        {
            cout << "NE" << '\n';
            continue;
        }
        
        if ((str.substr(0, starIdx) == pfix)
        &&
        (str.substr(str.length() - sfix.length()) == sfix))
        {
            cout << "DA" << '\n';
        }
        else cout << "NE" << '\n';
    }
}

int main()
{
    cin >> cnt;
    cin >> pat;
    
    findKeys();
    checkFiles();
}