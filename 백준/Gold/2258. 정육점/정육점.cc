#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int n, m, a, b;
vector<pii> v;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back({ a, b });
    }

    sort(v.begin(), v.end(), [](pii& a, pii& b) {
        if (a.second == b.second)
            return a.first > b.first;

        return a.second < b.second;
        });

    int total = 0;
    int price = 0;
    int ans = 2147483647;
    bool flag = false;

    for (int i = 0; i < v.size(); i++)
    {
        total += v[i].first;

        if (i != 0 && v[i - 1].second == v[i].second)
            price += v[i].second;
        else
            price = 0;

        if (total >= m)
        {
            ans = min(ans, price + v[i].second);
            flag = true;
        }
    }

    cout << (flag ? ans : -1) << '\n';
}