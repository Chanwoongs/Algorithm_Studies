#include <iostream>
#include <string>
using namespace std;

string str;
int cnt[100];

int main()
{
    cin >> str;
    
    int i = 0;
    for (char let : str)
    {
        cnt[let - 'a']++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        cout << cnt[i] << ' ';
    }
}    
