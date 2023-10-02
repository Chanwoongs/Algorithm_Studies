#include <iostream>
#include <queue>
using namespace std;

const int INF = 987654321;
int n, m, sx, sy, res;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int a[1004][1004];
int fireCheck[1004][1004];
int personCheck[1004][1004];

int main()
{
	queue<pair<int, int>> q;
	fill(&fireCheck[0][0], &fireCheck[0][0] + 1004 * 1004, INF);

	cin >> n >> m;
	for (int i = 0; i < n; i++) 
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) 
		{
			a[i][j] = s[j];
			if (a[i][j] == 'F') 
			{
				fireCheck[i][j] = 1; 
				q.push({ i, j });
			}
			else if (a[i][j] == 'J') 
			{
				sy = i; sx = j;
			}
		}
	} 

	while (q.size())
	{
		pair<int, int> here = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (fireCheck[ny][nx] != INF || a[ny][nx] == '#') continue;

			fireCheck[ny][nx] = fireCheck[here.first][here.second] + 1;
			q.push({ ny, nx });
		}
	}

	personCheck[sy][sx] = 1;
	q.push({ sy, sx });

	while (q.size())
	{
		pair<int, int> here = q.front();
		q.pop();

		if (here.first == n - 1 || here.second == m - 1 || here.first == 0 || here.second == 0)
		{
			res = personCheck[here.first][here.second];
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

			if (personCheck[ny][nx] || a[ny][nx] == '#') continue;
			if (personCheck[here.first][here.second] + 1 >= fireCheck[ny][nx]) continue; // 불이 더 빠르다면
			
			personCheck[ny][nx] = personCheck[here.first][here.second] + 1;
			q.push({ ny, nx });
		}
	}

	if (res != 0) cout << res << '\n';
	else cout << "IMPOSSIBLE" << '\n';
}