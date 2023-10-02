#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;

bool checkParenthesis(string str)
{
	stack<char> s;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' || str[i] == '[')
			s.push(str[i]);
		else if (str[i] == ')')
		{
			if (!s.size() || s.top() == '[') return false;
			s.pop();
		}
		else if (str[i] == ']')
		{
			if (!s.size() || s.top() == '(') return false;
			s.pop();
		}
	}
	if (s.size()) return false;

	return true;
}

int main()
{
	while (1)
	{
		getline(cin, str);

		if (str == ".") break;
		if (checkParenthesis(str)) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
}