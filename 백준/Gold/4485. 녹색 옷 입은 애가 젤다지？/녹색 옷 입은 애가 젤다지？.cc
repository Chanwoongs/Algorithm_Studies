#include <iostream>
#include <queue>

using namespace std;

const int max_n = 130;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int t, n, INF = 987654321;
int a[max_n][max_n], dist[max_n][max_n];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	while (++t)
	{
		cin >> n;
		if (n == 0) return 0;
		fill(&a[0][0], &a[0][0] + max_n * max_n, 0);
		fill(&dist[0][0], &dist[0][0] + max_n * max_n, INF);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}

		pq.push({ a[0][0], 0 });
		dist[0][0] = a[0][0];

		while (pq.size())
		{
			int hereY = pq.top().second / 1000;
			int hereX = pq.top().second % 1000;
			int hereDist = pq.top().first;
			pq.pop();
			if (dist[hereY][hereX] != hereDist) continue;

			for (int i = 0; i < 4; i++)
			{
				int ny = hereY + dy[i];
				int nx = hereX + dx[i];
				int thereDist = a[ny][nx];

				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

				if (dist[ny][nx] > dist[hereY][hereX] + thereDist)
				{
					dist[ny][nx] = dist[hereY][hereX] + thereDist;
					pq.push({ dist[ny][nx], (ny * 1000) + nx });
				}
			}
		}
		cout << "Problem " << t << ": " << dist[n - 1][n - 1] << '\n';
	}
}