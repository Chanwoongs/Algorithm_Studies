#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> v;
string s, res;

void go()
{
	while (true)
	{
		if (res.size() && res.front() == '0') res.erase(res.begin());
		else break;
	}
	if (res.size() == 0) res = "0";
	v.push_back(res);
	res = "";
}

bool cmp(string a, string b)
{
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		res = "";

		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] < 65) res += s[j];
			else if (res.size()) go();
		}
		if (res.size()) go();
	}

	sort(v.begin(), v.end(), cmp);

	for (string s : v) cout << s << '\n';

}