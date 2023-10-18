#include <iostream>
#include <vector>

using namespace std;
#define max_n 200004
#define ll long long
const ll mod = 1e9 + 7;
int n, value;
ll res = 1, _prev;
vector<ll> tree_cnt(max_n, 0), tree_sum(max_n, 0);

ll _sum(vector<ll>& tree, int value)
{
	ll _ret = 0;
	int i = value;
	while (i) 
	{
		_ret += tree[i];
		i -= (i & -i);
	}
	return _ret;
}

ll sum(vector<ll>& tree, int s, int e)
{
	if (s > e) return 0;
	return (_sum(tree, e) - _sum(tree, s - 1));
}

void update(vector<ll>& tree, int x, int value)
{
	int i = x;
	while (i <= max_n) 
	{
		tree[i] += value;
		i += (i & -i);
	}
	return;
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> value; 
		value++;
		if (i != 1)
		{
			ll left = value * sum(tree_cnt, 1, value - 1) - sum(tree_sum, 1, value - 1);
			ll right = sum(tree_sum, value + 1, max_n - 1) - value * sum(tree_cnt, value + 1, max_n - 1);
			res *= (left + right) % mod;
			res %= mod;
		}
		update(tree_cnt, value, 1);
		update(tree_sum, value, value);
	}
	cout << res << '\n';
}