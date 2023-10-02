#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m;

int check(int temp, vector<int>& v)
{
	int l = 0, r = v.size() - 1;
	int mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (v[mid] > temp) r = mid - 1;
		else if (v[mid] == temp) return 1;
		else l = mid + 1;
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
		vector<int> a;

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			a.push_back(temp);
		}
		sort(a.begin(), a.end());

		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int temp;
			cin >> temp;

			cout << check(temp, a) << '\n';
		}
	}
}