#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, c, res;
int a[24], bag[24];
int dp[12][1 << 13][22];

int go(int cur, int collected, int capacity)
{
	if (cur == m) return 0;

	int& res = dp[cur][collected][capacity];
	if (res) return res;

	res = max(res, go(cur + 1, collected, c));
	for (int i = 0; i < n; i++)
	{
		bool isCollected = (1 << i) & collected;
		bool canCollect = (capacity - a[i]) >= 0;
		if (!isCollected && canCollect)
			res = max(res, go(cur, collected | (1 << i), capacity - a[i]) + 1);
	}
}


int main()
{
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << go(0, 0, c) << '\n';
}