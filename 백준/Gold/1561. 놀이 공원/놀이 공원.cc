#include <iostream>

using namespace std;

#define MAX_N 60000000004
#define MAX_M 10004

typedef long long ll;
ll n, m, a[MAX_M], lo, hi = MAX_N, res, mid, temp;

bool check(ll mid)
{
	temp = m; // 처음에 다 태운다.

	// 뒤에 비는 시간에 다 태운다.
	for (int i = 0; i < m; i++)
	{
		temp += mid / a[i];
	} 
	return temp >= n;
}

int main()
{
	cin >> n >> m;
	for (ll i = 0; i < m; i++)
	{
		cin >> a[i];
	}

	// 놀이 기구가 충분하다
	if (n <= m)
	{
		cout << n << '\n';
		return 0;
	}
	
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (check(mid))
		{
			res = mid; // n을 다 태울 수 있는 최소 시간
			hi = mid - 1;
		}
		else lo = mid + 1;
	}

	// 최소 시간 1초 전에 탄 아이의 수
	temp = m;
	for (ll i = 0; i < m; i++)
	{
		temp += ((res - 1) / a[i]);
	}

	// 최소 시간에 순차적으로 탑승하여 마지막 아이의 놀이기구를 구한다
	for (ll i = 0; i < m; i++)
	{
		if (res % a[i] == 0) temp++; // 한명씩 태운다
		if (temp == n) // 다 태웠다
		{
			cout << i + 1 << '\n';
			return 0;
		}
	}
}