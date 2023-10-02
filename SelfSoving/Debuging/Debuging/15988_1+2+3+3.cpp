#include <iostream>
#include <string.h>
using namespace std;

int tc, n, res;
int sub[] = { 3, 2, 1 };

long long dp[10000004];


long long go(int a)
{
	if (a <= 0)
	{
		return 0;
	}

	long long& ret = dp[a];

	if (a <= 3)
	{
		return ret;
	}

	if (ret != -1) return ret;

	//for (int i = 0; i < 3; i++)
	//{
	//	if (a - sub[i] > 0)
	//	{
	//		go(a - sub[i]);
	//		res++;
	//	}
	//}

	return dp[a] = (go(a - 1) + go(a - 2) + go(a - 3)) % 1000000009;
}


int main()
{
	cin >> tc;

	memset(dp, -1, sizeof(dp));

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	while (tc--)
	{
		res = 0;

		cin >> n;
		
		cout << go(n) << '\n';
	}
}