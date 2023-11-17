#include <iostream>
#include <cstring>
using namespace std;

const int INF = 99999999;
int n, res;
int dp[5004];

int main()
{
	cin >> n;

	fill(dp, dp + 5004, 0);
	dp[1] = dp[2] = dp[4] = INF;
	dp[3] = 1;
	dp[5] = 1;

	for (int i = 6; i <= n; i++)
	{
		dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
	}

	if (dp[n] == 0 || dp[n] >= INF) cout << -1 << '\n';
	else cout << dp[n] << '\n';
}