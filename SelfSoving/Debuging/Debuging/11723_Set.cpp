#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

char s[11];
int m, x, num;

int main()
{
	scanf(" %d", &m);

	for (int i = 0; i < m; i++)
	{
		scanf(" %s %d", &s, &x);

		if (s[0] == 'a' && s[1] == 'd') num |= (1 << x);
		else if (s[0] == 'r') num &= ~(1 << x);
		else if (s[0] == 'c')
		{
			if (num & (1 << x)) cout << '1' << '\n';
			else cout << '0' << '\n';
		}
		else if (s[0] == 't') num ^= (1 << x);
		else if (s[0] == 'a' && s[1] == 'l') num = (1 << 21) - 1;
		else num = 0;
	}
}