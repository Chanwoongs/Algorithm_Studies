#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, idx, res, cnt;

int main()
{
	cin >> n >> m;

	vector<pair<int, int>> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		if (a[i].second <= idx) continue; // 널빤지로 가려졌다.
		if (idx < a[i].first)
		{
			// 필요한 널빤지 개수
			cnt = (a[i].second - a[i].first) / m + ((a[i].second - a[i].first) % m ? 1 : 0);
			// 설치한 널빤지의 가장 끝 위치
			idx = a[i].first + cnt * m;
		}
		else // 웅덩이가 이미 조금 가려져 있는 경우
		{
			// 가려진 부분을 빼고 계산
			cnt = (a[i].second - idx) / m + ((a[i].second - idx) % m ? 1 : 0);
			idx = idx + cnt * m;
		}
		res += cnt;
	}
	cout << res << '\n';
}