#include <iostream>
#include <cstring>

using namespace std;
#define prev pp
typedef long long ll;
int n, m, dp[41], cnt[41], temp;

int go(int here)
{
	if (here >= n - 1) return 1; // ��� Ž���� �Ͽ���.
	if (cnt[here]) return go(here + 1); // vip �¼��̴�.

	// �޸������̼�
	if (~dp[here]) return dp[here];
	int& res = dp[here];
	res = 0;

	if (!cnt[here + 1]) res += (go(here + 2) + go(here + 1)); // �Ѵ� �ٲٱ� ����
	else res += go(here + 1); // �ٲٷ��� �¼��� VIP�϶�

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