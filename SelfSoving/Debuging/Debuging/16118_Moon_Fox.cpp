#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

const int INF = 987654321;
int n, m, a, b, d, res, here, cnt, dist[4001], dist_wolf[4001][2];
vector<pair<int, int>> adj[4001];


void dijkstraFox()
{
	fill(dist, dist + 4001, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
	dist[1] = 0;
	pq.push({ 0, 1 });

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

void dijkstraWolf()
{
	fill(&dist_wolf[0][0], &dist_wolf[0][0] + 4001 * 2, INF);
	priority_queue<tuple<int, int, bool>, vector<tuple<int, int, bool>>, greater<tuple<int, int, bool>>> pq;
	dist_wolf[1][0] = 0;
	pq.push({ 0, 1, 0 });

	while (pq.size())
	{
		int here, hereDist, flag;
		tie(hereDist, here, flag) = pq.top();
		pq.pop();

		if (dist_wolf[here][flag] != hereDist) continue;
		for (pair<int, int> there : adj[here])
		{
			int next = there.second;
			int nextDist = !flag ? there.first / 2 : there.first * 2;

			if (dist_wolf[next][!flag] > dist_wolf[here][flag] + nextDist)
			{
				dist_wolf[next][!flag] = dist_wolf[here][flag] + nextDist;
				pq.push({ dist_wolf[next][!flag], next, !flag });
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> d;
		adj[a].push_back({ d * 2, b });
		adj[b].push_back({ d * 2, a });
	}
	dijkstraFox();
	dijkstraWolf();

	for (int i = 2; i <= n; i++)
	{
		int d = std::min(dist_wolf[i][0], dist_wolf[i][1]);
		if (d > dist[i]) res++;
	}
	cout << res << '\n';
}