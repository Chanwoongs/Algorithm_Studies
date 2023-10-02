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
		if (a[i].second <= idx) continue; // �κ����� ��������.
		if (idx < a[i].first)
		{
			// �ʿ��� �κ��� ����
			cnt = (a[i].second - a[i].first) / m + ((a[i].second - a[i].first) % m ? 1 : 0);
			// ��ġ�� �κ����� ���� �� ��ġ
			idx = a[i].first + cnt * m;
		}
		else // �����̰� �̹� ���� ������ �ִ� ���
		{
			// ������ �κ��� ���� ���
			cnt = (a[i].second - idx) / m + ((a[i].second - idx) % m ? 1 : 0);
			idx = idx + cnt * m;
		}
		res += cnt;
	}
	cout << res << '\n';
}