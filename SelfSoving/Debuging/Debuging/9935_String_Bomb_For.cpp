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
		if (res.size() >= b.size() // �̰� ���� ���ؾ� AC4 ���� �ڿ� ���ǹ��� ������ �Ȼ��� 
			&& res.substr(res.size() - b.size(), b.size()) == b)
		{
			res.erase(res.end() - b.size(), res.end());
		}
	}
	if (!res.size()) cout << "FRULA" << '\n';
	else cout << res << '\n';
}