#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
int n, res = -99999999;
vector<int> num, ops;

int op(char op, int a, int b)
{
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
}

void go(int here, int _num)
{
	if (here == num.size() - 1)
	{
		res = max(res, _num);
		return;
	}

	go(here + 1, op(ops[here], _num, num[here + 1]));
	if (here + 2 <= num.size() - 1)
	{
		int temp = op(ops[here + 1], num[here + 1], num[here + 2]);
		go(here + 2, op(ops[here], _num, temp));
	}
	return;
}

int main()
{
	cin >> n >> str;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) num.emplace_back(str[i] - '0');
		else ops.emplace_back(str[i]);
	}
	go(0, num[0]);

	cout << res << '\n';
}