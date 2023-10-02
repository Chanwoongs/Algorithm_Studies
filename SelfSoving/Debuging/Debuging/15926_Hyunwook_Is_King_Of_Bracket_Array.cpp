#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n, res = 0, cnt, d[200004];
string s;
stack<int> stk;

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(') stk.push(s[i]);
		else if (stk.size())
		{
			d[i] = d[stk.top()] = 1;
			stk.pop();
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (d[i])
		{
			cnt++;
			res = std::max(res, cnt);
		}
		else cnt = 0;
	}
	cout << res << '\n';
}