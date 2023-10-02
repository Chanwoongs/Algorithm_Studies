#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define prev aaa

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int a[104][104], visited[104][104];
vector<pair<int, int>> prev;
int n, m, t;

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

	while (true)
	{
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		prev.clear();

		queue<pair<int, int>> q;
		visited[0][0] = 1;
		q.push({ 0, 0 });

		bool flag = false;

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

				if (a[ny][nx] == 0)
				{
					visited[ny][nx] = 1;
					q.push({ ny, nx });
				}
				else if (a[ny][nx] == 1)
				{
					visited[ny][nx] = 1;
					prev.push_back({ ny, nx });
				}
			}
		}
		t++;
		for (pair<int, int> p : prev)
		{
			a[p.first][p.second] = 0;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] != 0)
				{
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		if (!flag) break;
	}

	cout << t << '\n';
	cout << prev.size() << '\n';
}