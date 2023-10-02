#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n, res, cnt;
string s;
stack<int> stk;
int main()
{
	cin >> n;
	cin >> s;
	stk.push(-1);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(') stk.push(i);
		if (s[i] == ')')
		{
			stk.pop();
			if (!stk.empty())
			{
				res = std::max(res, i - stk.top());
			}
			else stk.push(i); // -1�� ���� ��ó�� �б����� ����� ���� push
		}
	}
	cout << res << '\n';
}