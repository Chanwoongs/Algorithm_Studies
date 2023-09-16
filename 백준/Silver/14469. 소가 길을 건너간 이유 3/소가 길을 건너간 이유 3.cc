#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int n, t;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());

	t = v[0].first + v[0].second;

	for (int i = 1; i < v.size(); i++)
	{
		t = std::max(t, v[i].first);
		t += v[i].second;
	}
	cout << t << '\n';
}