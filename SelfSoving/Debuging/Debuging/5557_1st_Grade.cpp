#include <iostream>

using namespace std;

typedef long long ll;
ll n, a[104], dp[104][21];

ll go(int idx, int sum)
{
	if (sum < 0 || sum > 20) return 0;

	ll& res = dp[idx][sum];
	if (res) return res;

	if (idx == n - 2) 
	{
		if (sum == a[n - 1]) return 1;
		return 0;
	}

	res += go(idx + 1, sum + a[idx + 1]);
	res += go(idx + 1, sum - a[idx + 1]);

	return res;
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << go(0, a[0]) << "\n";
	return 0;
}