#include <iostream>
#include <queue>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
const int INF = 987654321;
int res = INF;
int n, m;
int a[1004][1004];
int visited[1004][1004][2];

int BFS(int y, int x)
{
	queue<pair<pair<int, int>, int>> q;

	q.push({ {y, x}, 0 });
	visited[y][x][0] = 1;

	while (q.size())
	{
		pair<int, int> here = q.front().first;
		int hasBroken = q.front().second;
		q.pop();

		if (here.first == n - 1 && here.second == m - 1)
		{
			return visited[here.first][here.second][hasBroken];
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

			if (a[ny][nx] == 0 && !visited[ny][nx][hasBroken])
			{
				visited[ny][nx][hasBroken] = visited[here.first][here.second][hasBroken] + 1;
				q.push({ {ny, nx}, hasBroken });
			}
			else if (a[ny][nx] == 1 && !hasBroken)
			{
				visited[ny][nx][hasBroken + 1] = visited[here.first][here.second][hasBroken] + 1;
				q.push({ {ny, nx}, hasBroken + 1 });
			}
		}
	}

	return -1;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[j] - '0';
		}
	}

	cout << BFS(0, 0) << '\n';
}