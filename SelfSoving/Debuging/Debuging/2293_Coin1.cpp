#include <iostream>

using namespace std;

int n, k, temp;
int dp[10004];

int main()
{
	cin >> n >> k;
	dp[0] = 1; // 아무 동전도 안씀
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		if (temp >= 10001) continue;

		for (int j = temp; j <= k; j++)
		{
			dp[j] += dp[j - temp];
		}
	}
	cout << dp[k] << '\n';
}