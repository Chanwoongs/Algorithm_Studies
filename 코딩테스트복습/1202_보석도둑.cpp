#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

vector<pair<ll, ll>> jewels;
vector<ll> bags;
ll n, k, res;

int main()
{
	cin >> n >> k;
	for (ll i = 0; i < n; i++)
	{
		ll w, v;
		cin >> w >> v;
		jewels.push_back({ w, v });
	}
	sort(jewels.begin(), jewels.end());
	for (ll i = 0; i < k; i++)
	{
		ll w;
		cin >> w;
		bags.push_back(w);
	}
	sort(bags.begin(), bags.end());

	priority_queue<ll> pq;
	ll j = 0;
	for (ll i = 0; i < k; i++)
	{
		while (j < n && jewels[j].first <= bags[i])
		{
			pq.push(jewels[j++].second);
		}
		if (pq.size())
		{
			res += pq.top(); pq.pop();
		}
	}
	cout << res << '\n';
}