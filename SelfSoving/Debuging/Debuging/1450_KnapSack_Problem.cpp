#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, c, a[31], res;
vector<int> v, v2;

void go(int here, int _n, vector<int>& v, int sum)
{
	if (sum > c) return;
	if (here > _n)
	{
		v.push_back(sum);
		return;
	}

	// 담는 경우
	go(here + 1, _n, v, sum + a[here]);
	// 안담는 경우
	go(here + 1, _n, v, sum);

	return;
}

int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	go(0, n / 2 - 1, v, 0);
	go(n / 2, n - 1, v2, 0);

	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());

	for (int b : v2)
	{
		if (b > c) continue;
		res += (int)(upper_bound(v.begin(), v.end(), c - b) - v.begin());

		
	}

	cout << res << '\n';
}