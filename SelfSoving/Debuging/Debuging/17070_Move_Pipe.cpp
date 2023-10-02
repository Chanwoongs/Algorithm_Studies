#include <iostream>

using namespace std;

#define MAX_N 24

int n;
int a[MAX_N][MAX_N], dp[MAX_N][MAX_N][3];

// �� �� �ִ��� Check
bool check(int y, int x, int d)
{
	if (d == 0 || d == 2)
	{
		if (!a[y][x]) return true;
	}
	else if (d == 1)
	{
		if (!a[y][x] && !a[y - 1][x] && !a[y][x - 1]) return true;
	}
	return false;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}

	dp[1][2][0] = 1; // (1, 2)�� ù ������ 0

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// ����������
			if (check(i, j + 1, 0))dp[i][j + 1][0] += dp[i][j][0];
			if (check(i, j + 1, 0))dp[i][j + 1][0] += dp[i][j][1];

			// �Ʒ�������
			if (check(i + 1, j, 2))dp[i + 1][j][2] += dp[i][j][1];
			if (check(i + 1, j, 2))dp[i + 1][j][2] += dp[i][j][2];

			// �밢������
			if (check(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][0];
			if (check(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][1];
			if (check(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][2];
		}
	}
	int res = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
	cout << res << '\n';
}