#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

vector<pii> v;
ll n;

int main()
{
    ll n, res = 1;
    cin >> n;

    for (ll i = 0; i < n; ++i)
    {
        ll a, b;
        cin >> a >> b;
        auto ele = make_pair(a, b);
        v.push_back(ele);
    }

    sort(v.begin(), v.end(), [](pii a, pii b) -> bool {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second < b.second;
        });

    ll ed = v[0].second;
    for (ll i = 1; i < n; ++i)
    {
        if (v[i].first < ed) continue;

        ++res;
        ed = v[i].second;
    }

    cout << res << '\n';
}