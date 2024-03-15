#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 99999999

typedef pair<int, int> pii;

struct cmp
{
    bool operator()(pii& a, pii& b)
    {
        return a.second > b.second;
    }
};
 
int n, m, dist[1004], a, b, c, s, e;
priority_queue<pii, vector<pii>, cmp> pq;
vector<pair<int, int>> adj[1004];

int main()
{
    cin >> n >> m;
    fill(dist, dist + 1004, INF);
  
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;

        adj[a].push_back({ b, c });
    }

    cin >> s >> e;

    pq.push({ s, 0 });
    dist[s] = 0;

    while (pq.size())
    {
        int src = pq.top().first;
        int d = pq.top().second;
        pq.pop();

        if (dist[src] < d) continue;

        for (auto& next : adj[src])
        {
            int n = next.first;
            int nd = next.second;

            if (dist[n] > nd + d)
            {
                dist[n] = nd + d;
                pq.push({ n, dist[n] });
            }
        }
    }
    cout << dist[e] << '\n';
}