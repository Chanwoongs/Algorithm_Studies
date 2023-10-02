#include <iostream>

using namespace std;
typedef long long int ll;
int n, m, c, a[24], backpack[24], dp[24][1 << 14][24];

int go(int here, int jewels, int capacity)
{
	if (here == m) return 0;
	int& res = dp[here][jewels][capacity];
	if (res) return res;

	// 이 가방에 넣지 않고 go
	res = max(res, go(here + 1, jewels, c));

	for (int i = 0; i < n; i++)
	{
		bool has = (1 << i) & jewels;
		bool canPut = (capacity - a[i]) >= 0;

		if (!has && canPut) res = std::max(res, go(here, jewels | (1 << i), capacity - a[i]) + 1);
	}
	return res;
}

int main()
{
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << go(0, 0, c) << '\n';
}
