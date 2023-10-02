#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int a, b, n, m, res = 987654321;
vector<int> adj[1004];
int visited[1004];

void BFS(int here)
{
	queue<int> q;
	q.push(here);
	visited[here] = 1;

	while (q.size())
	{
		int there = q.front();
		q.pop();

		if (there == b) { cout << visited[there] - 1; return; }

		for (int next : adj[there])
		{
			if (visited[next]) continue;
			visited[next] = visited[there] + 1;
			q.push(next);
		}
	}

	cout << -1;
	return;
}

int main()
{
	cin >> a >> b;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	BFS(a);
}