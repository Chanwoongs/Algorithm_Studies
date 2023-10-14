#include <iostream>

using namespace std;

int parent[1000004];
int n, m, a, b, op;

int find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void _union(int x, int y)
{
	if (find(x) == find(y)) return;
	parent[find(x)] = find(y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> op >> a >> b;

		if (!op)
			_union(a, b);
		else
			find(a) == find(b) ? cout << "YES" << '\n' : cout << "NO" << '\n';
	}
}