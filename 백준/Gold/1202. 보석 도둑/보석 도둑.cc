#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

long long n, k, res;
vector<pair<int, int>> je;
vector<int> bag;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		je.push_back({ a, b });
	}
	sort(je.begin(), je.end());

	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		bag.push_back(a);
	}
	sort(bag.begin(), bag.end());

	priority_queue<long long> pq;

	int j = 0;
	for (int i = 0; i < k; i++)
	{
		while (j < n && je[j].first <= bag[i])
		{
			pq.push(je[j++].second);
		}
		if (pq.size())
		{
			res += pq.top();
			pq.pop();
		}
	}
	cout << res << '\n';
}