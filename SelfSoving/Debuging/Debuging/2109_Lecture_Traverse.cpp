#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, a, b, res;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back({ b, a }); // day�� ���� �������� ����
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		pq.push(v[i].second);
		if (pq.size() > v[i].first)
		{
			pq.pop(); // �ּҸ� ��� ���鼭 �ִ븦 ũ�� �����.
		}
	}
	while (pq.size())
	{
		res += pq.top();
		pq.pop();
	}
	cout << res << '\n';
}