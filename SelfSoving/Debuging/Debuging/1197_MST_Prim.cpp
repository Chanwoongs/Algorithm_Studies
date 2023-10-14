#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> pii;

int V, E, a, b, c;
int u, v, w;
long long res;
int visited[10001];
vector<pii> graph[10001];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	// 가중치, 노드
	pq.push({ 0, 1 });

	while (!pq.empty())
	{
		int w = pq.top().first;
		int u = pq.top().second;

		pq.pop();

		if (visited[u]) continue;
		visited[u] = 1;

		res += w;

		for (auto w : graph[u])
		{
			if (!visited[w.first])
			{
				pq.push({ w.second, w.first });
			}
		}
	}

	cout << res << '\n';
}