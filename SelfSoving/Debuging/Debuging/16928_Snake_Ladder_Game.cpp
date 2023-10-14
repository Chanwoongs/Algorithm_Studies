#include <iostream>
#include <queue>

using namespace std;

int map[104];
int d[104];

int n, m, a, b;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        map[a] = b;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        map[a] = b;
    }
    d[1] = 0;
    queue<int> q;
    q.push(1);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++)
        {
            int y = x + i;
            if (y > 100) continue;
            if (map[y] != 0) y = map[y];
            if (d[y] == 0)
            {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }
    cout << d[100] << '\n';
}