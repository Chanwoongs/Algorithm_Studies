#include <iostream>

using namespace std;

int tc, num;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		cin >> num;
		int res2 = 0, res5 = 0;

		for (int j = 2; j <= num; j*=2)
		{
			res2 += num / j;
		}
		for (int j = 5; j <= num; j *= 5)
		{
			res5 += num / j;
		}
		cout << min(res2, res5) << '\n';
	}
}