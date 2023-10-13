#include <iostream>

using namespace std;

const int INF = 987654321;
int n, m, r, t, a, b, l, res;
int dist[104][104];
int item[104];

int main()
{
    fill(&dist[0][0], &dist[0][0] + 104 * 104, INF);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        item[i] = t;
    }
    for (int i = 0; i < r; i++)
    {
        cin >> a >> b >> l;
        dist[a][b] = l;
        dist[b][a] = l;
    }

    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] != INF && dist[i][j] <= m)
            {
                sum += item[j];
            }
        }
        res = std::max(res, sum);
    }
    cout << res << '\n';
}