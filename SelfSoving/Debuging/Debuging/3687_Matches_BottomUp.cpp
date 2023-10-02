#include <iostream>
#include <string>
using namespace std;

//1. �׸���� dp(���Ҿ�) 
int a[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 }, t, n;
string dp[104], MAX_STR = "111111111111111111111111111111111111111111111111119";

string getMinStr(string a, string b)
{
	if (a.size() == b.size()) return (a < b ? a : b);
	if (a.size() < b.size()) return a;
	return b;
}

// �׸���
string findMax(int here)
{
	string res = "";
	if (here & 1) // Ȧ �� ����
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

	for (int i = 2; i < 104; i++) // ���� ���ɰ���
	{
		for (int j = 0; j <= 9; j++) // ����� ���ɰ���
		{
			if (i - a[j] < 0) continue; // ���ɰ��� ���ڶ� ���
			if (j == 0 && dp[i - a[j]] == "") continue; // �� �տ� 0�� ���� ���
			dp[i] = getMinStr(dp[i], dp[i - a[j]] + to_string(j));
		}
	}
	while (t--) 
	{
		cin >> n;
		cout << dp[n] << " " << findMax(n) << "\n";
	}
}