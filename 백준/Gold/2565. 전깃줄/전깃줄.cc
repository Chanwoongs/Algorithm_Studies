#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, a, b, len, lis[504];
vector<pair<int, int>> v;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back({ a, b });
	}

	// 한쪽 정렬
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		auto it = lower_bound(lis, lis + len, v[i].second);
		if (*it == 0) len++;
		*it = v[i].second;
	}
	cout << n - len << '\n';
}