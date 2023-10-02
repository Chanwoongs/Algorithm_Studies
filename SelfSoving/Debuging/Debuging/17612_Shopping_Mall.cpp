#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, id, cost_time, _time, idx;
long long res;

struct Cashier {
    int id, maxTime, cashier_id;
};

struct comp {
	bool operator()(Cashier& a, Cashier& b)
	{
		if (a.maxTime == b.maxTime)
		{
			return a.cashier_id > b.cashier_id;
		}
		return a.maxTime > b.maxTime;
	}
};

bool cmp2(const Cashier& a, const Cashier& b)
{
	if (a.maxTime == b.maxTime)
	{
		return a.cashier_id > b.cashier_id;
	}
	return a.maxTime < b.maxTime;
}

priority_queue<Cashier, vector<Cashier>, comp> pq;
vector<Cashier> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> id >> cost_time;
		if (i < k) // �ʱ� �� ���� �ֱ�
		{
			pq.push({ id, cost_time, i + 1 });
			continue;
		}
		pq.push({ id, cost_time + pq.top().maxTime, pq.top().cashier_id });
		v.push_back(pq.top());
		pq.pop();
	}
	while (pq.size())
	{
		v.push_back(pq.top()); // ���� ��ȣ ������ �������� ������ �ϱ� ���� ����
		pq.pop();
	}
	sort(v.begin(), v.end(), cmp2);
	for (int i = 0; i < v.size(); i++)
	{
		res += 1LL * (i + 1) * v[i].id;
	}
	cout << res << '\n';
}