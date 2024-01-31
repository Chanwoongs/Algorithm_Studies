#include<iostream>

using namespace std;

int n, m, a, b;
int parent[500004];

int find(int x)
{
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y) return true;

    parent[x] = y;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    
    for (int i = 0; i < 500004; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        if (merge(a, b))
        {
            cout << i << '\n';
            return 0;
        }
    }
    cout << '0' << '\n';
}