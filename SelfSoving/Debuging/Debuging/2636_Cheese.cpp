#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { -0, 1, 0, -1 };
int a[104][104], visited[104][104];
vector<pair<int, int>> v;
int n, m, t, meltCheese, remain;

void go(int y, int x)
{
	visited[y][x] = 1;

	if (a[y][x] == 1)
	{
		v.push_back({ y, x });
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visited[ny][nx]) continue;
		go(ny, nx);
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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
		v.clear();
		go(0, 0);
		meltCheese = v.size();
		for (pair<int, int> ele : v)
		{
			a[ele.first][ele.second] = 0;
		}
		bool flag = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] != 0) flag = 1;
			}
		}
		t++;
		if (!flag) break;
	}

	cout << t << '\n' << meltCheese << '\n';

}