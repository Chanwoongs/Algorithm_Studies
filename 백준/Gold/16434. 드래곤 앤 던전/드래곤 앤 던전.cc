#include <iostream>

using namespace std;

typedef long long ll;
ll n, attack, t[130005], a[130005], h[130005], lo, hi, res;

bool check(ll mid)
{
	ll mxHP = mid;
	ll initAttack = attack;
	for (int i = 0; i < n; i++)
	{
		if (t[i] == 2)
		{
			mid = std::min(mxHP, mid + h[i]); // 최대 hp 보단 작아야한다.
			initAttack += a[i];
		}
		else
		{
			ll cnt = h[i] / initAttack + (h[i] % initAttack ? 1 : 0);
			mid -= (cnt - 1) * a[i];
		}
		// 용사가 죽었다.
		if (mid <= 0) return false;
	}
	return true;
}

int main()
{
	cin >> n >> attack;

	for (int i = 0; i < n; i++)
	{
		cin >> t[i] >> a[i] >> h[i];
	}
	lo = 1;
	hi = 1e18 + 4;
	while (lo <= hi)
	{
		ll mid = (lo + hi) / 2;
		if (check(mid))
		{
			hi = mid - 1;
			res = mid;
		}
		else lo = mid + 1;
	}
	cout << res << '\n';
}