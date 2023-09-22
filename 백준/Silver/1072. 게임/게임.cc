#include <iostream>

using namespace std;
typedef long long ll;

ll x, y, mid, p, res = -1, lo, hi;

int main()
{
	cin >> x >> y;

	p = y * 100 / x;

	lo = 1;
	hi = 1e9;

	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if ((y + mid) * 100 / (x + mid) > p)
		{
			hi = mid - 1;
			res = mid;
		}
		else lo = mid + 1;
	}
	cout << res << '\n';
}