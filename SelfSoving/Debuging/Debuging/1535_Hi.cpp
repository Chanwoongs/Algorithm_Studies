#include <iostream>

using namespace std;

int n, dp[101], cost[101], hap[101];
double temp;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> cost[i];
	for (int i = 0; i < n; i++) cin >> hap[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 100; j > cost[i]; j--) // j�� cost�� ���� ���� ü���� 0�� �ȴ�.
		{
			dp[j] = std::max(dp[j], dp[j - cost[i]] + hap[i]);
		}
	}
	cout << dp[100] << '\n';
}