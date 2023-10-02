#include <iostream>
#include <vector>
using namespace std;

vector<int> num;
vector<char> operStr;
int n, res = -987654321;
string s;

int oper(char a, int b, int c)
{
	if (a == '+') return b + c;
	if (a == '-') return b - c;
	if (a == '*') return b * c;
}

void go(int here, int inNum)
{
	if (here == num.size() - 1)
	{
		res = std::max(res, inNum);
		return;
	}
	
	go(here + 1, oper(operStr[here], inNum, num[here + 1]));
	if (here + 2 <= num.size() - 1)
	{
		int temp = oper(operStr[here + 1], num[here + 1], num[here + 2]);
		go(here + 2, oper(operStr[here], inNum, temp));
	}
}

int main()
{
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) num.push_back(s[i] - '0');
		else operStr.push_back(s[i]);
	}
	go(0, num[0]);
	cout << res << '\n';
}