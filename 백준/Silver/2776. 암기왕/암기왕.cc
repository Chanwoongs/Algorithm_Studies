#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int t, n, m, temp;
unordered_map<int, int> mp;

int check(int temp, vector<int>& v)
{
	int l = 0, r = v.size() - 1;
	int mid;

	while (l <= r)
	{
		mid = (l + r) / 2;
		if (v[mid] > temp) r = mid - 1; // 작은수 쪽으로 반으로 줄이기
		else if (v[mid] == temp) return 1;
		else l = mid + 1; // 큰수 쪽으로 반으로 줄이기
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--)
	{
		vector<int> v;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> temp;
			cout << check(temp, v) << '\n';
		}
	}
}