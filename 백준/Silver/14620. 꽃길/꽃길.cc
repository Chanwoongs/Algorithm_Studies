#include <iostream>
#include <vector>
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0 ,-1 };

int n;
int flo[20][20];
int cost[20][20];
int res = 987654321;

int setFlower(int y, int x)
{
	flo[y][x] = 1;
	int s = cost[y][x];

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		flo[ny][nx] = 1;
		s += cost[ny][nx];
	}
	return s;
}

bool check(int y, int x)
{
	if (flo[y][x]) return false;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n || flo[ny][nx]) return false;
	}
	return true;
}

void eraseFlower(int y, int x)
{
	flo[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		flo[ny][nx] = 0;
	}
}

void flower(int cnt, int sum)
{
	if (cnt == 3)
	{
		res = std::min(res, sum);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check(i, j))
			{
				flower(cnt + 1, sum + setFlower(i, j));
				eraseFlower(i, j);
			}
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> cost[i][j];
		}
	}

	flower(0, 0);
	cout << res;
}