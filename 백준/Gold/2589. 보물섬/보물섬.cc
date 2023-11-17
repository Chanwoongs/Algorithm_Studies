#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int a[54][54], visited[54][54];
char c;
int n, m, res = -1;

void BFS(int y, int x)
{
	fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
	visited[y][x] = 1;

	queue<pair<int, int>> q; 
	q.push({ y, x });

	while (q.size())
	{
		tie(y, x) = q.front(); q.pop();
	
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx])
				continue;
			if (a[ny][nx] == 1) continue;
			
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
			res = max(res, visited[ny][nx]);
		}
	}
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
			if (s[j] == 'W') a[i][j] = 1;
			else a[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0)
			{
				BFS(i, j);
			}
		}
	}

	cout << res - 1 << '\n';
}