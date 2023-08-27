#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str, ret;
int cnt[104];
int num;

int main()
{
    cin >> num;
        
    for (int i = 0; i < num; i++)
    {
        cin >> str;
        cnt[str[0] - 'a']++;
    }
    
    for (int i = 0; i < 104; i++)
    {
        if (cnt[i] >= 5) 
        {
            ret += i + 'a';
        }
    }
    
    if (ret.size()) cout << ret << '\n';
    else cout << "PREDAJA" << '\n';
}