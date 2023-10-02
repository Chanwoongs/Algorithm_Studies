#include<iostream>
#include<vector>

using namespace std;
int n, m, k, t, a, b, cnt[301], dp[301][301];
vector<pair<int, int>> v;

int go(int here, int num, int prev) // 현재 idx, 현재 투입가능 수, 이전 투입수
{
	if (here == v.size()) return 0;
	if (dp[here][num]) return dp[here][num];

	int cost = std::max(0, t - v[here].second); // 현재 필요한 사람의 수 cost
	int realCost = (prev >= cost) ? 0 : cost - prev; // 만약 이미 투입한 인원이 충족 한다면 투입 X

	int& res = dp[here][num];
	if (num - realCost >= 0) // 투입 해야한다면
	{
		return res = std::max(go(here + 1, num - realCost, realCost) + v[here].first, // 투입하거나
			go(here + 1, num, 0)); // 투입 X
	}
	else return res = go(here + 1, num, 0);
}

int main()
{
	cin >> n >> m >> k >> t;
	for (int j = 0; j < m; j++)
	{
		cin >> a >> b;
		for (int i = a; i < b; i++)
		{
			cnt[i] = min(t, ++cnt[i]);
		}
	}
	int temp = cnt[1];
	int _count = 1;
	for (int i = 2; i <= n; i++)
	{
		if (temp != cnt[i])
		{
			v.push_back({ _count, temp }); // cnt가 달라지는 지점을 체크하여 넣기
			_count = 0;
			temp = cnt[i];
		}
		_count++;
	}
	v.push_back({ _count, temp });
	cout << go(0, k, 0) << '\n';
}