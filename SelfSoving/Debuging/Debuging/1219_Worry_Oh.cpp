#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, s, e, m, visited[104], candi[104], a, b, c, ok;
vector<pair<int, int>> adj[104];
long long dist[104], sal[104];
const long long INF = 1e18;
queue<int> q;

int main()
{
	cin >> n >> s >> e >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}
	for (int i = 0; i < n; i++)
	{
		cin >> sal[i];
	}
	fill(dist, dist + n, -INF);

	dist[s] = sal[s];

	for (int i = 0; i < n; i++)
	{
		for (int here = 0; here < n; here++)
		{
			for (pair<int, int> there : adj[here])
			{
				int _dist = there.second; // there로 갈때 드는 비용
				int _there = there.first; // there의 위치
				if (dist[here] != -INF && dist[here] + sal[_there] - _dist > dist[_there])
				{
					dist[_there] = dist[here] + sal[_there] - _dist;
					if (i == n - 1) q.push(here); // 사이클이 생기는 경우 q에 push
				}
			}
		}
	}
	while (q.size())
	{
		int here = q.front();
		q.pop();
		for (pair<int, int> there : adj[here])
		{
			if (there.first == e)
			{
				ok = 1; break;
			}

			if (!visited[there.first])
			{
				visited[there.first] = 1;
				q.push(there.first);
			}
		}
		if (ok) break;
	}
	if (dist[e] == -INF) puts("gg"); // 도착을 안했다.
	else if (ok) puts("Gee"); // 사이클 존재
	else cout << dist[e] << '\n';
}