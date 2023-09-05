#include <iostream>
#include <string>
using namespace std;

string s;
int n;
char a[104][104];

string quad(int y, int x, int size)
{
	if (size == 1) return string(1, a[y][x]);

	char b = a[y][x];
	string res = "";

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (b != a[i][j])
			{
				res += '(';
				res += quad(y, x, size / 2);
				res += quad(y, x + size / 2, size / 2);
				res += quad(y + size / 2, x, size / 2);
				res += quad(y + size / 2, x + size / 2, size / 2);
				res += ')';

				return res;
			}
		}
	}
	return string(1, a[y][x]);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			a[i][j] = s[j];
		}
	}

	cout << quad(0, 0, n) << '\n';
	return 0;
}