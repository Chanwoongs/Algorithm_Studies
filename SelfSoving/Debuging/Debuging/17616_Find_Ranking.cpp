#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;
using namespace std;
int n, m, x, a, b, visited[100005];
vector<int> l[100005], h[100005];

int bfs(int here, vector<int> adj[])
{
	queue<int> q;

	visited[here] = 1;
	q.push(here);
	int res = 0;
	while (q.size())
	{
		int _here = q.front();
		q.pop();
		for (int there : adj[_here])
		{
			if (visited[there]) continue;
			visited[there] = 1;
			q.push(there);
			res++;
		}
	}
	return res;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) 
	{
		cin >> a >> b;
		l[a].push_back(b);
		h[b].push_back(a);
	}
	int ans1 = bfs(x, h);
	fill(visited, visited + 100005, 0);
	int ans2 = bfs(x, l);

	cout << ans1 + 1 << " " << n - ans2 << "\n";

	return 0;
}