#include <iostream>
#include <queue>
using namespace std;

int a[304][304], visited[304][304];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int n, m;
int sy, sx, ey, ex, res;

int main()
{
	cin >> n >> m;
	cin >> sy >> sx >> ey >> ex;
	sy--; sx--; ey--; ex--;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[j];
		}
	}

	queue<int> q;

	q.push(1000 * sy + sx);
	visited[sy][sx] = 1;
	int cnt = 0;
	while (a[ey][ex] != '0') // 목표 지점이 0이 아닐때 까지
	{
		cnt++;
		queue<int> temp;

		while (q.size())
		{
			int y = q.front() / 1000;
			int x = q.front() % 1000;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				if (visited[ny][nx]) continue;

				visited[ny][nx] = cnt;

				if (a[ny][nx] != '0')
				{
					a[ny][nx] = '0';
					temp.push(1000 * ny + nx); // 0이 아니라면 temp에 push
				}
				else q.push(1000 * ny + nx);
			}
		}
		q = temp;
	}
	cout << visited[ey][ex];
}