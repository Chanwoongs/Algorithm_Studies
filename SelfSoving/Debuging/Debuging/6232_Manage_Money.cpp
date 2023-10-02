#include <iostream>

using namespace std;

typedef long long ll;
ll n, m, a[100005], mx, res, lo, hi;

bool check(int mid)
{
	int cnt = 1; // 1번은 무조건 인출하기 때문에 1
	int temp = mid;
	for (int i = 0; i < n; i++)
	{
		// 인출을 한다.
		if (mid - a[i] < 0)
		{
			mid = temp;
			cnt++;
		}
		mid -= a[i];
	}
	return cnt <= m;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mx = std::max(a[i], mx);
	}
	lo = mx, hi = 1000000004;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (check(mid))
		{
			hi = mid - 1;
			res = mid;
		}
		else lo = mid + 1;
	}
	cout << res << '\n';
}