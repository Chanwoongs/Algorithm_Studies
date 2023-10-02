#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

char a[54][54];
int visited[54][54];

int n, m, mx;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void BFS(int y, int x)
{
	memset(visited, 0, sizeof(visited));
	visited[y][x] = 1;

	queue<pair<int,int>> q;
	q.push({ y, x });

	while (q.size())
	{
		pair<int, int> here = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (a[ny][nx] == 'L')
			{
				visited[ny][nx] = visited[here.first][here.second] + 1;
				q.push({ ny, nx });
				mx = max(mx, visited[ny][nx]);
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 'L') BFS(i, j);
		}
	}
	cout << mx - 1 << '\n';
}