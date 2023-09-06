#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int a[10][10], visited[10][10];
int n, m, res;
vector<pair<int, int>> virusList;
vector<pair<int, int>> wallList;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void DFS(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visited[ny][nx] == 1) continue;
		if (a[ny][nx] == 0)
		{
			DFS(ny, nx);
		}
	}
}

int solve()
{
	fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);

	for (pair<int, int> v : virusList)
	{
		DFS(v.first, v.second);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0 && !visited[i][j]) cnt++;
		}
	}
	return cnt;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 2) virusList.push_back({ i, j });
			if (a[i][j] == 0) wallList.push_back({ i, j });
		}
	}

	for (int i = 0; i < wallList.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < j; k++)
			{
				a[wallList[i].first][wallList[i].second] = 1;
				a[wallList[j].first][wallList[j].second] = 1;
				a[wallList[k].first][wallList[k].second] = 1;

				res = max(res, solve());

				a[wallList[i].first][wallList[i].second] = 0;
				a[wallList[j].first][wallList[j].second] = 0;
				a[wallList[k].first][wallList[k].second] = 0;
			}
		}
	}
	cout << res << '\n';
}
