#include <iostream>
#include <string>
using namespace std;

//1. 그리디와 dp(바텀업) 
int a[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 }, t, n;
string dp[104], MAX_STR = "111111111111111111111111111111111111111111111111119";

string getMinStr(string a, string b)
{
	if (a.size() == b.size()) return (a < b ? a : b);
	if (a.size() < b.size()) return a;
	return b;
}

// 그리디
string findMax(int here)
{
	string res = "";
	if (here & 1) // 홀 수 인지
	{
		res += '7';
		here -= 3;
	}
	while (here)
	{
		res += '1';
		here -= 2;
	}
	return res;
}

 
int main()
{
	cin >> t;
	fill(dp, dp + 104, MAX_STR);
	dp[0] = "";

	for (int i = 2; i < 104; i++) // 남은 성냥개비
	{
		for (int j = 0; j <= 9; j++) // 만드는 성냥개비
		{
			if (i - a[j] < 0) continue; // 성냥개비가 모자란 경우
			if (j == 0 && dp[i - a[j]] == "") continue; // 맨 앞에 0이 오는 경우
			dp[i] = getMinStr(dp[i], dp[i - a[j]] + to_string(j));
		}
	}
	while (t--) 
	{
		cin >> n;
		cout << dp[n] << " " << findMax(n) << "\n";
	}
}