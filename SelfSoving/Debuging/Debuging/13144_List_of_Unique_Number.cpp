#include <iostream>

using namespace std;

long long s, e, cnt[100001], n, a[100001];
long long res;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	while (e < n)
	{
		if (!cnt[a[e]])
		{
			cnt[a[e]]++;
			e++;
		}
		else 
		{
			res += (e - s);
			cnt[a[s]]--;
			s++;
		}
	}
	res += (long long)(e - s) * (e - s + 1) / 2;
	cout << res << '\n';
}