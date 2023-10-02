#include <iostream>

using namespace std;
typedef long long ll;
ll s, c, a[1000004], res, sum, resCnt;

bool check(int mid)
{
	ll cnt = 0;
	for (int i = 0; i < s; i++)
	{
		cnt += a[i] / mid;
	}
	return cnt >= c; // 모든 파닭을 처리할 수 있는가
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> c;
	for (int i = 0; i < s; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	ll lo = 1, hi = 1e9;
	while (lo <= hi)
	{
		ll mid = (lo + hi) / (1LL * 2);
		if (check(mid))
		{
			lo = mid + 1;
			res = mid;
		}
		else hi = mid - 1;
	}
	cout << sum - res * c << '\n';
}