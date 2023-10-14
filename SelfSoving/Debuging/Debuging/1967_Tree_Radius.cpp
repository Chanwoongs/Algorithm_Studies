#include <iostream>
#include <queue>
using namespace std;


int n, res, a, b, c, deepNode, maxCost = -1;
vector<pair<int, int>> adj[10004];

void DFS(int cur, int prev, int cost)
{
	if (cost > maxCost)
	{
		maxCost = cost;
		deepNode = cur;
	}

	for (int i = 0; i < adj[cur].size(); i++)
	{
		if (adj[cur][i].first != prev)
		{
			DFS(adj[cur][i].first, cur, cost + adj[cur][i].second);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	DFS(1, 0, 0);
	maxCost = -1;
	DFS(deepNode, 0, 0);
	cout << maxCost << '\n';
}