#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a, b, c, res, mx, parent[100004];

int find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y) parent[x] = y;
}

bool cmpParent(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return true;
    else return false;
}

int main()
{
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> graph(m);
    for (int i = 0; i < 100004; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[i] = { {a, b}, c };
    }
    sort(graph.begin(), graph.end(),
        [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
        {
            return a.second < b.second;
        });

    for (int i = 0; i < m; i++)
    {
        int a = graph[i].first.first;
        int b = graph[i].first.second;
        int c = graph[i].second;

        if (!cmpParent(a, b))
        {
            mx = max(mx, c);
            res += c;
            merge(a, b);
        }
    }
    cout << res - mx;
}