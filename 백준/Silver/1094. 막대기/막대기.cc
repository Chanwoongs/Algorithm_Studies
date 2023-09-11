#include <iostream>

using namespace std;

int x, res = 1;

int main()
{
	cin >> x;

	while (x != 1)
	{
		if (x & 1) res++;
		x /= 2;
	}
	cout << res << '\n';
}
