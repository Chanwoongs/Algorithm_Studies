#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define INF 99999999

int tc, n, m, w, s, e, t;
int dist[504];

int main()
{
    cin >> tc;

    while (tc--)
    {
        cin >> n >> m >> w;
        vector<pair<int, int>> adj[504];
        memset(dist, INF, sizeof(dist));
        for (int i = 0; i < m; i++)
        {
            cin >> s >> e >> t;
            adj[s].push_back({ e, t });
            adj[e].push_back({ s, t });
        }
        for (int i = 0; i < w; i++)
        {
            cin >> s >> e >> t;
            adj[s].push_back({ e, -t });
        }

        
        dist[1] = 0;
        bool isUpdated = false;

        for (int k = 0; k < n; k++)
        {
            isUpdated = false;
            for (int i = 1; i <= n; i++)
            {
                for (auto& a : adj[i])
                {
                    if (dist[a.first] > dist[i] + a.second)
                    {
                        dist[a.first] = dist[i] + a.second;
                        isUpdated = true;
                    }
                }
            }
        }

        if (isUpdated)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}