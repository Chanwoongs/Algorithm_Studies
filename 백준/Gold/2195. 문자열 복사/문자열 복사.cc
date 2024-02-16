#include <iostream>
#include <string>
using namespace std;

string s, p;

int main() 
{
    cin >> s >> p;
    int cnt = 0;
    
    for(int i = 0; i < p.length();)
    {
        int maxLen = 0;
        for(int j = 0; j < s.length(); j++)
        {
            int tmp = 0;
            
            while(s[j + tmp] == p[i + tmp])
                tmp++;
            
            maxLen = max(maxLen, tmp);
        }
        i += maxLen;
        cnt++;
    }
    cout << cnt << '\n';
	return 0;
}