#include <iostream>
#include <string>
using namespace std;

int n, team, A, B, asum, bsum;
string scoreTime;
string last = "00:00";

string print(int a)
{
	string d = "00" + to_string(a / 60);
	string e = "00" + to_string(a % 60);

	return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}

int changeToInt(string a)
{
	return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

void go(int& sum, string s)
{
	sum += (changeToInt(s) - changeToInt(last));
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> team >> scoreTime;
		
		if (A > B) go(asum, scoreTime);
		else if (B > A) go(bsum, scoreTime);

		team == 1 ? A++ : B++;
		last = scoreTime;
	}

	if (A > B) go(asum, "48:00");
	else if (B > A) go(bsum, "48:00");

	cout << print(asum) << '\n';
	cout << print(bsum) << '\n';
}