#include <iostream>
#include <string>
#include <map>

using namespace std;

int testCnt, n;
string a, b;
long long res;

int main()
{
    cin >> testCnt;
    for (int i = 0; i < testCnt; i++)
    {
        map<string, int> m;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            //getline(cin, temp);
            //int pos = temp.find(' ');
            cin >> a >> b;
            m[b]++;
        }
        res = 1;
        for (auto it : m)
        {
            res *= (it.second + 1);    
        }
        cout << res - 1 << '\n';
    }
}