#include <iostream>
#include <cstring>

using namespace std;
#define prev pp
typedef long long ll;
int n, m, dp[41], cnt[41], temp;

int go(int here)
{
	if (here >= n - 1) return 1; // 모든 탐색을 하였다.
	if (cnt[here]) return go(here + 1); // vip 좌석이다.

	// 메모이제이션
	if (~dp[here]) return dp[here];
	int& res = dp[here];
	res = 0;

	if (!cnt[here + 1]) res += (go(here + 2) + go(here + 1)); // 둘다 바꾸기 가능
	else res += go(here + 1); // 바꾸려는 좌석이 VIP일때

	return res;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		cnt[temp - 1] = 1;
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0) << '\n';
}