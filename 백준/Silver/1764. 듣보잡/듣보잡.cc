#include <iostream>
#include <map>
#include <string>
#include <vector>


using namespace std;

map<string, int> mp;
vector<string> v;
int n, m, cnt;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        mp[s]++;
    }

    for (auto ele : mp)
    {
        if (ele.second >= 2)
        {
            v.push_back(ele.first);
            cnt++;
        }
    }

    cout << cnt << '\n';
    for (auto ele : v)
    {
        cout << ele << '\n';
    }
}