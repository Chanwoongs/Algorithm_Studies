#include <iostream>
#include <algorithm>
using namespace std;

int h, w, res, a[504];

int main()
{
	cin >> h >> w;

	for (int i = 0; i < w; i++)
		cin >> a[i];

	for (int i = 1; i < w - 1; i++)
	{
		int l = 0, r = 0;

		for (int j = 0; j < i; j++)
		{
			if (a[i] < a[j])
				l = max(l, a[j]);
		}

		for (int j = i + 1; j < w; j++)
		{
			if (a[i] < a[j])
				r = max(r, a[j]);
		}

		res += max(min(l, r) - a[i], 0);
	}

	cout << res << '\n';
}