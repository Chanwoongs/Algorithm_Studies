#include <iostream>
#include <string>
using namespace std;

const int n = 4;

string a[n] = { "사과", "딸기", "포도", "배" };

void go(int num)
{
	string res = "";

	for (int i = 0; i < 4; i++)
	{
		if (num & (1 << i)) res += a[i] + ' ';
	}
	cout << res << '\n';
}

int main()
{
	for (int i = 0; i < (1 << n); i++)
	{
		string res = "";
		cout << i << " : ";
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j)) // 켜져 있는가
			{
				res += (a[j] + ' ');
			}
		}
		cout << '\n';
		cout << res << '\n';
	}
	cout << '\n';

	for (int i = 1; i < n; i++)
	{
		// visited[i] = 1;
		go(1 | (1 << i));
		// visited[i] = 0; 
		// visited 배열 없이 비트 마스킹으로 구현 가능
	}
}