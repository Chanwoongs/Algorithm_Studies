#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
const int INF = 987654321;
int n, mp, mf, ms, mv;
int b, c, d, e, res = INF, sum;
map<int, vector<vector<int>>> res_v;

struct A
{
	int mp, mf, ms, mv, cost;
} a[16];

int main()
{
	cin >> n;
	cin >> mp >> mf >> ms >> mv;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
	}

	for (int i = 1; i < (1 << n); i++)
	{
		b = c = d = e = sum = 0;
		vector<int> v;

		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				v.push_back(j + 1);
				b += a[j].mp;
				c += a[j].mf;
				d += a[j].ms;
				e += a[j].mv;
				sum += a[j].cost;
			}
		}
		if (b >= mp && c >= mf && d >= ms && e >= mv)
		{
			if (res >= sum)
			{
				res = sum;
				res_v[res].push_back(v);
			}
		}
	}
	if (res == INF) cout << -1 << '\n';
	else
	{
		sort(res_v[res].begin(), res_v[res].end());
		cout << res << '\n';
		for (int ele : res_v[res][0])
		{
			cout << a << ' ';
		}
	}
}