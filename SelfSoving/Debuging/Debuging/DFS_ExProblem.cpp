#include <iostream>
#include <vector>
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int n, m, res;

int a[104][104];
int visited[104][104];

void DFS(int inY, int inX)
{
	visited[inY][inX] = 1;
	cout << inY << ":" << inX << '\n';
	for (int i = 0; i < 4; i++)
	{
		int ny = inY + dy[i];
		int nx = inX + dx[i];

		if (ny < 0 || nx >= m || nx < 0 || ny >= n) continue;
		if (a[ny][nx] && visited[ny][nx] == 0) DFS(ny, nx);
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
			if (a[i][j] && visited[i][j] == 0)
			{
				cout << i << ":" << j << "dfs가 시작됩니다.\n";
				res++;
				DFS(i, j);
			}
		}
	}

	cout << res << '\n';
}