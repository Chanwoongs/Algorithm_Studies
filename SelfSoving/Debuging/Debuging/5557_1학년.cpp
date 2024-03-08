#include <iostream>
#include <cstring>
using namespace std;

int n;
long long num[104];
long long dp[104][24];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];

	memset(dp, 0, sizeof(dp));

	dp[0][num[0]] = 1;

	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (j + num[i] <= 20)
				dp[i][j + num[i]] += dp[i - 1][j];
			if (j - num[i] >= 0)
				dp[i][j - num[i]] += dp[i - 1][j];
		}
	}

	cout << dp[n - 2][num[n - 1]] << '\n';
}