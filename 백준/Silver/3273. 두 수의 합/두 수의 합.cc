#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int l, r;
ll n, x, res;
vector<ll> v;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		v.push_back(a);
	}
	cin >> x;

	sort(v.begin(), v.end());

	l = 0;
	r = v.size() - 1;
	while (l < r)
	{
		int sum = v[l] + v[r];

		if (sum == x)
		{
			r--;
			res++;
		}
		else if (sum >= x) r--;
		else if (sum < x) l++;
	}
	cout << res << '\n';
}