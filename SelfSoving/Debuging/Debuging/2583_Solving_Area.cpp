#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int a[101][101], visited[101][101];
int n, m, k;
vector<int> res;

int DFS(int y, int x)
{
	visited[y][x] = 1;
	int res = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
		if (visited[ny][nx]) continue;

		if (a[ny][nx] == 1) continue;
		res += DFS(ny, nx);
	}

	return res;
}

int main()
{
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int ly, lx, ry, rx;
		cin >> lx >> ly >> rx >> ry;

		for (int j = lx; j < rx; j++)
		{
			for (int w = ly;  w < ry;  w++)
			{
				a[w][j] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != 1 && visited[i][j] == 0)
			{
				res.push_back(DFS(i, j));
			}
		}
	}

	sort(res.begin(), res.end());

	cout << res.size() << '\n';
	for (int ele : res)
	{
		cout << ele << ' ';
	}
}