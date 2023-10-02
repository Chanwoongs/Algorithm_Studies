#include<iostream>
#include<vector>

using namespace std;
int n, m, k, t, a, b, cnt[301], dp[301][301];
vector<pair<int, int>> v;

int go(int here, int num, int prev) // ���� idx, ���� ���԰��� ��, ���� ���Լ�
{
	if (here == v.size()) return 0;
	if (dp[here][num]) return dp[here][num];

	int cost = std::max(0, t - v[here].second); // ���� �ʿ��� ����� �� cost
	int realCost = (prev >= cost) ? 0 : cost - prev; // ���� �̹� ������ �ο��� ���� �Ѵٸ� ���� X

	int& res = dp[here][num];
	if (num - realCost >= 0) // ���� �ؾ��Ѵٸ�
	{
		return res = std::max(go(here + 1, num - realCost, realCost) + v[here].first, // �����ϰų�
			go(here + 1, num, 0)); // ���� X
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
			v.push_back({ _count, temp }); // cnt�� �޶����� ������ üũ�Ͽ� �ֱ�
			_count = 0;
			temp = cnt[i];
		}
		_count++;
	}
	v.push_back({ _count, temp });
	cout << go(0, k, 0) << '\n';
}