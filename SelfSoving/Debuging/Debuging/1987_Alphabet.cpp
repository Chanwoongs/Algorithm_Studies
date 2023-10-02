#include <iostream>
#include <queue>
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

char a[24][24];
int visited[26];
int r, c, res;

void go(int y, int x, int cnt)
{
	visited[(int)a[y][x] - 'A'] = 1;

	res = std::max(res, cnt);

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;

		int next = (int)(a[ny][nx] - 'A');

		if (visited[next] == 0)
		{
			visited[next] == 1;
			go(ny, nx, cnt + 1);
			visited[next] = 0;
		}
	}
}

int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
		}
	}

	go(0, 0, 1);

	cout << res << '\n';
}