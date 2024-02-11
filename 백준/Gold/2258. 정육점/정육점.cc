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

    int totalWei = 0;
    int totalPri = 0;
    int prev = -1;

    for (int i = 0; i < v.size(); i++)
    {
        if (totalWei < m)
        {
            if (prev == v[i].second)
                totalPri += v[i].second;
            else
                prev = totalPri = v[i].second;
        }
        else
        {
            if ((prev != v[i].second) && (totalPri >= v[i].second))
                prev = totalPri = v[i].second;
        }
        totalWei += v[i].first;
    }

    cout << (totalWei < m ? -1 : totalPri) << '\n';
}