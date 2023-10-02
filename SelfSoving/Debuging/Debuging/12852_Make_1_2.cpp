#include <iostream>

using namespace std;

int dp[1000004], n;
const int INF = 987654321;

void go(int here)
{
	// 1이 되는 순간
	if (here == 0) return;
	cout << here << ' ';

	if (here % 3 == 0 && dp[here] == (dp[here / 3] + 1)) go(here / 3);
	else if (here % 2 == 0 && dp[here] == (dp[here / 2] + 1)) go(here / 2);
	else if (here - 1 >= 0 && dp[here] == (dp[here - 1] + 1)) go(here - 1);
	return;
}

int main()
{
	cin >> n;
	fill(dp, dp + 1000004, INF);
	dp[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		// 3, 2로 나누어 진다면
		if (!(i % 3)) dp[i] = std::min(dp[i / 3] + 1, dp[i]);
		if (!(i % 2)) dp[i] = std::min(dp[i / 2] + 1, dp[i]);
		dp[i] = std::min(dp[i - 1] + 1, dp[i]);
	}
	cout << dp[n] << '\n';
	go(n);
}