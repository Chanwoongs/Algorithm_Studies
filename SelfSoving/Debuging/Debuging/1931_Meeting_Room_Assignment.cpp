#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, res = 1, from, to;
vector<pair<int, int>> v;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> from >> to;
		v.push_back({ to, from });
	}
	sort(v.begin(), v.end());

	from = v[0].second; // second가 시작
	to = v[0].first; // first가 도착

	for (int i = 1; i < n; i++)
	{
		if (v[i].second < to) continue; // 겹쳐서 사용하지 못함
		from = v[i].second;
		to = v[i].first;
		res++;
	}
	cout << res << '\n';
}