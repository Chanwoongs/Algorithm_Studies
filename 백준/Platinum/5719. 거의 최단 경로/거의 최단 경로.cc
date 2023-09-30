#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int n, m, x, y, z, s, e;
int a[504][504], dist[504];
const int INF = 987654321;

void dijkstra()
{
	fill(dist, dist + 504, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, s)); // (거리, 정점)
	dist[s] = 0;

	while (pq.size())
	{
		int here = pq.top().second;
		int hereDist = pq.top().first;
		pq.pop();

		if (dist[here] != hereDist) continue;
		for (int i = 0; i < n; i++)
		{
			if (a[here][i] == -1) continue; // 색칠해놓은 곳이면 패쓰
			int _dist = a[here][i];
			if (dist[i] > dist[here] + _dist)
			{
				dist[i] = dist[here] + _dist;
				pq.push(make_pair(dist[i], i));
			}
		}
	}
}

void eraseEdge()
{
	queue<int> q;
	q.push(e);
	while (q.size())
	{
		int cx = q.front();
		q.pop();
		for (int i = 0; i < n; i++)
		{
			// 최단거리의 의미
			if (dist[cx] - dist[i] == a[i][cx] && a[i][cx] != -1)
			{
				a[i][cx] = -1;
				q.push(i);
			}
		}
	}
}

int main()
{
	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		cin >> s >> e;
		memset(a, -1, sizeof(a));

		for (int i = 0; i < m; i++)
		{
			cin >> x >> y >> z;
			a[x][y] = z;
		}
		dijkstra();
		eraseEdge();
		dijkstra();

		cout << (dist[e] == INF ? -1 : dist[e]) << '\n';
	}
}