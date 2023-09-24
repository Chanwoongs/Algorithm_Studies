#include <iostream>
#include <vector>
using namespace std;

int n, k, temp;
int dp[10004];
const int INF = 987654321;

int main()
{
	cin >> n >> k;
	fill(dp, dp + 10004, INF); // 최솟값은 최댓값으로 초기화
	dp[0] = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		for (int j = temp; j <= k; j++)
		{
			dp[j] = std::min(dp[j], dp[j - temp] + 1);
		}
	}
	if (dp[k] == INF) cout << -1 << '\n';
	else cout << dp[k] << '\n';
}