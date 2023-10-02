#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> lines[1000004];
int n, l, r, from, to, res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> from >> to;
		lines[i] = pair<int, int>(from, to);
	}
	sort(lines, lines + n);
	l = lines[0].first;
	r = lines[0].second;

	for (int i = 1; i < n; i++)
	{
		// 라인이 겹쳐져 있지 않다
		if (r < lines[i].first)
		{
			res += (r - l);
			l = lines[i].first;
			r = lines[i].second;
		}
		else if (lines[i].first <= r && lines[i].second >= r)
		{
			r = lines[i].second;
		}
	}
	res += r - l;
	cout << res << '\n';
}