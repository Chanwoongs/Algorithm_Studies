#include <iostream>
#include <vector>
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int a[5][5], visited[5][5];
int r, c, k, res;
vector<int> v;

void go(int y, int x)
{
	if (y == 0 && x == c - 1)
	{
		v.push_back(visited[y][x]);
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if (visited[ny][nx]) continue;

		if (a[ny][nx] == '.')
		{
			visited[ny][nx] = visited[y][x] + 1;
			go(ny, nx);
			visited[ny][nx] = 0;
		}
	}
}

int main()
{
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			a[i][j] = s[j];
		}
	}
	visited[r - 1][0] = 1;
	go(r - 1, 0);
	
	for (auto ele : v)
	{
		if (ele == k) res++;
	}
	cout << res << '\n';
}