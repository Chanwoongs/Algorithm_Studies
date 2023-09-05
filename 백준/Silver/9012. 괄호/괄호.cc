#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n;
string str;

bool checkParenthesis(string str)
{
	stack<char> s;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (!s.size()) return false;
			s.pop();
		}
	}

	if (s.size() == 0) return true;
	return false;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> str;

		if (checkParenthesis(str)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}