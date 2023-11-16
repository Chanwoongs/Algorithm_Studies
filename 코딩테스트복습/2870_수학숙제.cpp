#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s, temp;
int n;
vector<string> v;
void go()
{
	while (true)
	{
		if (temp.size() && temp.front() == '0') temp.erase(temp.begin());
		else break;
	}
	if (temp.size() == 0) temp = "0";
	v.push_back(temp);
	temp = "";
}

bool cmp(string& a, string& b)
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

		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] < 65) temp += s[j];
			else if (temp.size()) go();
		}
		if (temp.size()) go();
	}
	sort(v.begin(), v.end(), cmp);
	for (auto& s : v) cout << s << '\n';
}