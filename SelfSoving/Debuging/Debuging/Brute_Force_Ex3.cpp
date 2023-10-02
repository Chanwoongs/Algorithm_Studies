#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, temp, res = -1, cnt, mod = 11;
vector<int> v;

void go(int idx, int sum)
{
	if (res == 10) return; // 백트래킹

	if (idx == n)
	{
		res = max(res, sum % mod);
		cnt++;
		return;
	}
	go(idx + 1, sum + v[idx]);
	go(idx + 1, sum);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	go(0, 0);
	cout << res << '\n';
	cout << cnt << '\n';
}