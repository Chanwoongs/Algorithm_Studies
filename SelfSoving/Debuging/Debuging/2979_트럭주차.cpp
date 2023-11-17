#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int a, b, c, res;
vector<pair<int, int>> v;
map<int, int> mp;
set<int> st;

int main()
{
	cin >> a >> b >> c;

	for (int i = 0; i < 3; i++)
	{
		int x, y;
		cin >> x >> y;
		for (int j = x; j < y; j++)
		{
			mp[j]++;
			st.insert(j);
		}
	}

	for (auto& ele : st)
	{
		if (mp[ele] == 1)
			res += a;
		else if (mp[ele] == 2)
			res += (b * 2);
		else if (mp[ele] == 3)
			res += (c * 3);
	}

	cout << res << '\n';
}