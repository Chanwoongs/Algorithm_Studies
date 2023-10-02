#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string s, b, res;
stack<char> stk;

int main()
{
	cin >> s >> b;
	for (char a : s)
	{
		stk.push(a);
		if (stk.size() >= b.size() && stk.top() == b[b.size() - 1])
		{
			string ss = "";
			for (char i : b)
			{
				ss += stk.top();
				stk.pop();
			}
			reverse(ss.begin(), ss.end());
			if (b != ss)
			{
				for (char c : ss)
				{
					stk.push(c);
				}
			}
		}
	}
	if (stk.size() == 0) cout << "FRULA" << '\n';
	else
	{
		while (stk.size())
		{
			res += stk.top();
			stk.pop();
		}
		reverse(res.begin(), res.end());
		cout << res << '\n';
	}
}