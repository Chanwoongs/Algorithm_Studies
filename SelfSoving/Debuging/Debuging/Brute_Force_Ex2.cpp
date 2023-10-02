#include <iostream>
#include <vector>
using namespace std;

int n, temp;
vector<int> v;
// 소수 판별
bool check(int n)
{
	if (n <= 1) return 0;
	if (n <= 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0) return 0;
	}

}

int go(int idx, int sum)
{
	if (idx == n)
	{
		return check(sum);
	}

	// 더하거나, 놔두거나
	return go(idx + 1, sum + v[idx]) + go(idx + 1, sum);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	cout << go(0, 0) << '\n';
}