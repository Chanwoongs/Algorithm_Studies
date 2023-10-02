#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

int n, cost, m1, m2, cal;
int dp[100004];

int main()
{
	while (1)
	{
		scanf("%d %d.%d", &n, &m1, &m2);
		if (n == 0)break;
		int cost = m1 * 100 + m2;
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < n; i++)
		{
			scanf("%d %d.%d", &cal, &m1, &m2);
			int temp = m1 * 100 + m2;

			for (int j = temp; j <= cost; j++)
			{
				dp[j] = std::max(dp[j], dp[j - temp] + cal);
			}
		}
		printf("%d\n", dp[cost]);
	}
}