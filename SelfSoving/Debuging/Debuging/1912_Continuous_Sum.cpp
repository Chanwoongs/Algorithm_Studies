#include <iostream>

using namespace std;

int n, sum, a, res = -1004;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		sum += a;
		res = std::max(sum, res);
		if (sum < 0) sum = 0;
	}

	cout << res << '\n';
}