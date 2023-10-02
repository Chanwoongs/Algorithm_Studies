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

	from = v[0].second; // second�� ����
	to = v[0].first; // first�� ����

	for (int i = 1; i < n; i++)
	{
		if (v[i].second < to) continue; // ���ļ� ������� ����
		from = v[i].second;
		to = v[i].first;
		res++;
	}
	cout << res << '\n';
}