#include <iostream>
#include <queue>
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int a[104][104];
int visited[104][104];

int n, m, carrot;
int sy, sx;
int ey, ex;

void BFS(int y, int x)
{
	queue <pair<int, int>> q;
	for (int i = 0; i < 1; i++)
	{
		visited[y][x] = 1;
		q.push({ y, x });
	}

	while (q.size())
	{
		pair <int, int> here = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 0 || nx >= m || nx < 0 || ny >= n || a[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[here.first][here.second] + 1; // 방문 + 최단 거리를 담는 배열이 된다.
			q.push({ ny, nx });
		}
	}
}

int main()
{
	cin >> n >> m;
	cin >> sy >> sx;
	cin >> ey >> ex;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	
	BFS(sy, sx);

	cout << "Need Carrot : " << visited[ey][ex] << '\n';

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << visited[i][j] << ' ';
		cout << '\n';
	}
		

	return 0;
}