#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define y1 aaa

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m, k;
int x1, y1, x2, y2;
int a[104][104], visited[104][104];
vector<int> res;

int DFS(int y, int x)
{
	visited[y][x] = 1;

	int res = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx])
			continue;
		if (a[ny][nx] == 1) continue;
		res += DFS(ny, nx);
	}
	return res;
}

int main()
{
	cin >> n >> m >> k;
	fill(&a[0][0], &a[0][0] + 104 * 104, 0);

	for (int i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; j++)
		{
			for (int k = x1; k < x2; k++)
			{
				a[j][k] = 1;
			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0 && !visited[i][j])
			{
				res.push_back(DFS(i, j));
			}
		}
	}

	cout << res.size() << '\n';
	sort(res.begin(), res.end());
	for (auto& ele : res)
		cout << ele << ' ';
}