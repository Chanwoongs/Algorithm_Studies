#include <iostream>
#include <string>

using namespace std;

const int INF = 987654321;
int dp[2504][2504], dp2[2504];
string s;

int go(int here)
{
	if (here == s.size()) return 0;
	if (dp2[here] != INF) return dp2[here];

	int& res = dp2[here];

	for (int i = 1; i <= s.size() - here; i++)
	{
		if (dp[here][i]) res = std::min(res, go(here + i) + 1);
	}
	return res;
}

int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		dp[i][1] = 1;
	}
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s[i] == s[i + 1])
			dp[i][2] = 1;
	}
	for (int _size = 3; _size <= s.size(); _size++)
	{
		for (int j = 0; j <= s.size() - _size; j++)
		{
			if (s[j] == s[j + _size - 1] && dp[j + 1][_size - 2]) dp[j][_size] = 1;
		}
	}
	fill(dp2, dp2 + 2504, INF);
	cout << go(0) << '\n';
}