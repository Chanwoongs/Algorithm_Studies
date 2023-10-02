#include <iostream>

using namespace std;

int n, a[1004], cnt[1004], res;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		int mx = 0;
		// ¿ÞÂÊ ºÎÅÍ i ±îÁö Å½»ö
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && mx < cnt[j])
			{
				mx = cnt[j];
			}
		}
 		cnt[i] = mx + 1;
		res = std::max(res, cnt[i]);
	}
	cout << res << '\n';
}