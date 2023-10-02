#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define max_n 75004
typedef long long ll;

int n, x, y, t;
vector<int> tree, _y;
vector<pair<int, int>> a;

int sum(int idx)
{
	int res = 0;
	while (idx > 0)
	{
		res += tree[idx];
		idx -= (idx & -idx);
	}
	return res;
}

void update(int pos, int value)
{
	int idx = pos;
	while (idx <= n)
	{
		tree[idx] += value;
		idx += (idx & -idx);
	}
}

int find_index(const vector<int>& _y, int value)
{
	int lo = 0, hi = _y.size() - 1;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (_y[mid] == value) return mid;
		if (_y[mid] < value) lo = mid + 1;
		else hi = mid - 1;
	}
}

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> n;
		a.clear(); _y.clear();
		tree.clear();
		tree.resize(n + 1);

		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;

			// 좌표를 뒤집기 위해 y * -1
			a.push_back({ x, y * -1 });
			_y.push_back(y * -1); // 이분 탐색을 위한 y 저장
		}
		sort(a.begin(), a.end());
		sort(_y.begin(), _y.end()); // -10억이 몇번째야?

		ll res = 0;
		// 펜윅 트리에 정점 카운팅
		update(find_index(_y, a[0].second) + 1, 1);

		for (int i = 1; i < n; i++)
		{
			int idx = find_index(_y, a[i].second) + 1;
			res += 1LL * sum(idx);
			update(idx, 1);
		}
		cout << res << '\n';
	}
}
