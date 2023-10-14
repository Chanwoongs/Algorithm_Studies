#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int V, E, a, b, c;
int u, v, w;
int parent[10004];
long long res;
bool check;
vector<tuple<int, int, int>> graph;
vector<tuple<int, int, int>> resGraph;

int find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void _union(int x, int y)
{
	int a = find(x);
	int b = find(y);

	check = false;

	if (a == b) return;
	if (a < b) parent[b] = find(a);
	else parent[a] = b;
	check = true;
}

int main()
{
	cin >> V >> E;

	for (int i = 1; i <= V; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		graph.push_back({ c, a, b });
	}
	sort(graph.begin(), graph.end());

	for (int i = 0; i < E; i++)
	{
		_union(get<1>(graph[i]), get<2>(graph[i]));

		if (check)
		{
			resGraph.push_back({ get<1>(graph[i]), get<2>(graph[i]), get<0>(graph[i]) });
			res += get<0>(graph[i]);
		}
	}

	//for (auto x : resGraph)
	//{
	//	cout << get<1>(x) << ' ' << get<2>(x) << '\n';
	//}
	cout << res << '\n';
}
