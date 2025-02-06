#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n, m, a, b, c;
int indegree[104];
int dp[104][104];
vector<pair<int, int>> adj[104];
queue<int> q;
set<int> basic;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[b].push_back({ a, c });
        indegree[a]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            basic.insert(i);
            q.push(i);
            dp[i][i] = 1;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto& a : adj[cur])
        {
            int next = a.first;
            int cnt = a.second;

            for (int i = 1; i <= n; i++)
            {
                dp[next][i] += dp[cur][i] * cnt;
            }

            indegree[next]--;
            if (indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    for (auto& b : basic)
    {
        cout << b << ' ' << dp[n][b] << '\n';
    }
}