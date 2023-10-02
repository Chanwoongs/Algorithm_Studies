#include <iostream>

using namespace std;

int n, k, s, e, a, b, t;
int dist[404][404];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		dist[a][b] = -1;
		dist[b][a] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][k] == 1 && dist[k][j] == 1) dist[i][j] = 1;
				else if (dist[i][k] == -1 && dist[k][j] == -1) dist[i][j] = -1;
			}
		}
	}
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> s >> e;
		cout << dist[s][e] << '\n';
	}
}