#include<iostream>

using namespace std;

#define max_n 1025
int n, m;
int a[max_n][max_n], bit[max_n][max_n];

void update(int y, int x, int value)
{
	while (y <= n)
	{
		int j = x;
		while (j <= n)
		{
			bit[y][j] += value;
			j += (j & -j);
		}
		y += (y & -y);
	}
	return;
}

int sum(int y, int x)
{
	int res = 0;

	while (y > 0)
	{
		int j = x;
		while (j > 0)
		{
			res += bit[y][j];
			j -= (j & -j);
		}
		y -= (y & -y);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			update(i, j, a[i][j]);
		}
	}
	for (int i = 0; i < m; i++)
	{
		int type;
		cin >> type;

		if (type)
		{
			int y1, x1, y2, x2;
			cin >> y1 >> x1 >> y2 >> x2;
			cout << sum(y2, x2) - sum(y1 - 1, x2) - sum(y2, x1 - 1) + sum(y1 - 1, x1 - 1) << '\n';
		}
		else
		{
			int y, x, value;
			cin >> y >> x >> value;
			update(y, x, value - a[y][x]);
			a[y][x] = value;
		}
	}
}