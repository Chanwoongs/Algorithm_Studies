#include <iostream>

using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int a[54][54];
int visited[54][54];
int tc, n, m, cnt, res;

void DFS(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx >= m || nx < 0 || ny >= n) continue;

		if (a[ny][nx] && visited[ny][nx] == 0)
			DFS(ny, nx);
	}
}

int main()
{
	cin >> tc;
	
	while(tc--)
	{
		fill(&a[0][0], &a[0][0] + 54 * 54, 0);
		fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
		res = 0;

		cin >> m >> n >> cnt;

		for (int i = 0; i < cnt; i++)
		{
			int x, y;
			cin >> x >> y;
			a[y][x] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 1 && !visited[i][j])
				{
					DFS(i, j);
					res++;
				}
			}
		}
		cout << res << '\n';
	}
}