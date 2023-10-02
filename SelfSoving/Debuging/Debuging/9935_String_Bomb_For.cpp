#include <iostream>
#include <string>
using namespace std;

string str;
string b;
string res;

int main()
{
	cin >> str >> b;
	for (char a : str)
	{
		res += a;
		if (res.size() >= b.size() // 이걸 먼저 비교해야 AC4 에서 뒤에 조건문이 문제가 안생김 
			&& res.substr(res.size() - b.size(), b.size()) == b)
		{
			res.erase(res.end() - b.size(), res.end());
		}
	}
	if (!res.size()) cout << "FRULA" << '\n';
	else cout << res << '\n';
}