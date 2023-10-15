#include <iostream>
#include <map>
using namespace std;

int main()
{ 
    int n, m;
    map<string,string> mp;
    string a, b;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;

        mp[a] = b;
    }

    for(int i = 0; i < m; i++)
    {
        cin >> a;

        cout << mp[a] << '\n';
    }

    return 0;
}