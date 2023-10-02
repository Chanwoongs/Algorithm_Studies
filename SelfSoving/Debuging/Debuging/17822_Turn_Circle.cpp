#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


int a[54][54], visited[54][54];
int n, m, T, x, d, k, res;
bool flag = 1;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void _rotate(int y, int dir, int k)
{
	vector<int> v;
	for (int i = 0; i < m; i++) v.push_back(a[y][i]);

	if (dir == 1) rotate(v.begin(), v.begin() + k, v.end());
	else rotate(v.rbegin(), v.rbegin() + k, v.rend());
	for (int i = 0; i < m; i++) a[y][i] = v[i];
	return;
}

void DFS(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = (x + dx[i] + m) % m;

		if (ny < 0 || ny >= n) continue;
		if (visited[ny][nx]) continue;
		if (a[y][x] == a[ny][nx])
		{
			visited[y][x] = visited[ny][nx] = 1;
			flag = 0;
			DFS(ny, nx);
		}
	}
}

bool findAdj()
{
	flag = 1;
	memset(visited, 0, sizeof(visited));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0) continue;
			if (visited[i][j]) continue;
			DFS(i, j);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j]) a[i][j] = 0;
		}
	}
	return flag;
}

void setAverage()
{
	int sum = 0;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0) continue;
			sum += a[i][j];
			cnt++;
		}
	}
	double av = (double)sum / (double)cnt;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0) continue;
			if ((double)a[i][j] > av) a[i][j]--;
			else if ((double)a[i][j] < av) a[i][j]++;
		}
	}
}

int main()
{
	cin >> n >> m >> T;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < T; i++)
	{
		cin >> x >> d >> k;
		for (int j = x - 1; j < n; j += x)
		{
			_rotate(j, d, k);
		}
		if (findAdj()) setAverage();
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			res += a[i][j];
		}
	}
	cout << res << '\n';
}