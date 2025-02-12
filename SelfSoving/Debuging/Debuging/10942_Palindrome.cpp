#include <iostream>

using namespace std;
int n, a[2004], dp[2004][2004], t, from, to;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		// 자기자신은 무조건 팰린드롬
		dp[i][i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		// 연속된 것이 같다면 팰린드롬
		if (a[i] == a[i + 1]) dp[i][i + 1] = 1;
	}
	// 모든 쌍의 팰린드롬 확인
	for (int _size = 2; _size <= n; _size++)
	{
		for (int i = 1; i <= n - _size; i++)
		{
			if (a[i] == a[i + _size] && dp[i + 1][i + _size - 1]) dp[i][i + _size] = 1;
		}
	}

	cin >> t;
	while (t--)
	{
		cin >> from >> to;
		cout << dp[from][to] << '\n';
	}
}