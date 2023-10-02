#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654322; // 모든 간선을 짝수로 만들기 위해 맨뒤 2인 수로 초기화
int T, dist[2004], n, m, t, s, g, h, a, b, d;

int main()
{
	cin >> T;
	while (T--)
	{
		vector<pair<int, int>> adj[2004];
		cin >> n >> m >> t >> s >> g >> h;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> d;
			d *= 2; // 모든 간선을 짝수로 만든다
			if (a == g && b == h) d--; // 지나간 곳은 홀수로
			else if (a == h && b == g) d--;
			adj[a].push_back({ d, b });
			adj[b].push_back({ d, a });
		}
		int candidate[104];
		for (int i = 0; i < t; i++)
		{
			cin >> candidate[i];
		}
		sort(candidate, candidate + t);
		fill(dist, dist + 2004, INF);

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0, s });
		dist[s] = 0;
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
		for (int i = 0; i < t; i++)
		{
			if (dist[candidate[i]] % 2 == 1) cout << candidate[i] << '\n';
		}
	}
}