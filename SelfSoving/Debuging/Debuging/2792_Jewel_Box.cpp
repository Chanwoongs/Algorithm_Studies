#include <iostream>

using namespace std;
typedef long long ll;

ll n, m, res = 1e18;
ll a[300004];

bool check(ll mid)
{
	ll num = 0;
	for (int i = 0; i < m; i++)
	{
		num += a[i] / mid;
		if (a[i] % mid) num++;
	}
	return n >= num;
}

int main()
{
	cin >> n >> m;
	ll lo = 1, hi = 0, mid;
	
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		hi = std::max(hi, a[i]);
	}
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (check(mid))
		{
			res = std::min(res, mid);
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << res << '\n';
}

