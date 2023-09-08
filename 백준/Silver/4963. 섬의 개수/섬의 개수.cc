#include <iostream>

using namespace std;

int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int a[54][54], visited[54][54];
int h, w, cnt;

void DFS(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
		if (visited[ny][nx]) continue;

		if (a[ny][nx] == 1) DFS(ny, nx);
	}
}

int main()
{
	while (true)
	{
		fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);

		cnt = 0;

		cin >> w >> h;
		if (w == 0 && h == 0)
		{
			break;
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (a[i][j] == 1 && !visited[i][j])
				{
					DFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}