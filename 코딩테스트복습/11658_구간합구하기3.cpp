#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int a, b, c, d, e;
int nums[1030][1030], bit[1030][1030];

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
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{ 
			cin >> nums[i][j];
			update(i, j, nums[i][j]);
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a;
		if (a == 1)
		{
			int y1, x1, y2, x2;
			cin >> y1 >> x1 >> y2 >> x2;
			cout << sum(y2, x2) - sum(y1 - 1, x2) - sum(y2, x1 - 1) + sum(y1 - 1, x1 - 1) << '\n';
		}
		else
		{
			int y, x, value;
			cin >> y >> x >> value;
			update(y, x, value - nums[y][x]);
			nums[y][x] = value;
		}
	}
}