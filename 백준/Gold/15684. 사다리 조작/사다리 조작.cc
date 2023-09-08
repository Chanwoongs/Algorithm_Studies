#include <iostream>
#include <queue>
using namespace std;

const int INF = 987654321;
int visited[34][34];
int n, m, h, res = INF;
vector<pair<int, int>> v;

bool check()
{
	for (int i = 1; i <= n; i++)
	{
		int start = i;
		for (int j = 1; j <= h; j++)
		{
			if (visited[j][start]) start++;
			else if (visited[j][start - 1]) start--;
		}
		if (start != i) return false;
	}
	return true;
}

void go(int here, int cnt)
{
	if (cnt > 3 || cnt >= res) return;

	if (check())
	{
		res = std::min(res, cnt);
		return;
	}
	for (int i = here; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
			visited[i][j] = 1;
			go(i, cnt + 1);
			visited[i][j] = 0;
		}
	}
}

int main()
{
	cin >> n >> m >> h;

	for (int i = 0; i < m; i++)
	{
		int y, x;
		cin >> y >> x;

		visited[y][x] = 1;
	}

	go(1, 0);
	cout << ((res == INF) ? -1 : res) << '\n';
}