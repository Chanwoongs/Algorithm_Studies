#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, X, u, v, w, res;
vector<pair<int, int>> adj[1001], adj2[1001];
int dist[1001], dist2[1001];
bool visited[1001];
const int INF = 987654321;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int* dist, vector<pair<int, int>>* adj)
{
	pq.push({ 0, X });
	dist[X] = 0;
	while (pq.size())
	{
		int here = pq.top().second;
		int hereDist = pq.top().first;

		pq.pop();
		if (dist[here] != hereDist) continue;

		for (pair<int, int> there : adj[here])
		{
			int next = there.second;
			int nextDist = there.first;

			if (dist[next] > dist[here] + nextDist)
			{
				dist[next] = dist[here] + nextDist;
				pq.push({ dist[next], next });
			}
		}
	}
}

int main()
{
	cin >> N >> M >> X;
	fill(dist, dist + 1001, INF);
	fill(dist2, dist2 + 1001, INF);

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
		adj2[v].push_back({ w, u });
	}
	dijkstra(dist, adj);
	dijkstra(dist2, adj2);

	for (int i = 1; i <= N; i++)
	{
		if (i == X) continue;
		res = std::max(res, dist[i] + dist2[i]);
	}
	cout << res;
}