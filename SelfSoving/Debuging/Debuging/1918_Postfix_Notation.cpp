#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s;

int getPriority(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;

	default:
		return -1;
	}
}

string postFix(const string& str)
{
	string res;
	stack<char> s;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			res += str[i];
		}
		else if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else if (str[i] == ')')
		{
			while (s.top() != '(')
			{
				res += s.top();
				s.pop();
			}
			s.pop(); // pop '('
		}
		else
		{
			while (!s.empty() && getPriority(s.top()) >= getPriority(str[i]))
			{
				res += s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}
	while (!s.empty())
	{
		res += s.top();
		s.pop();
	}

	return res;
}

int main()
{
	cin >> s;

	cout << postFix(s) << '\n';
}