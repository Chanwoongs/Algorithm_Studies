#include <iostream>
#include <string>

using namespace std;

//2. ž���� 
int a[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 }, t, n;
string dp[104], dp2[104], MAX_STR = "11111111111111111111111111111111111111111111111111111";

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

string findMin(int here)
{
	if (here == 0) return "";
	string& res = dp[here];
	if (res != MAX_STR) return res;
	for (int i = 0; i <= 9; i++)
	{
		if (here - a[i] < 0) continue; // ���� ���ڶ�
		if (here == n && i == 0) continue; // ù��° 0�ȵ�
		res = getMinStr(res, to_string(i) + findMin(here - a[i]));
	}
	return res;
}


int main()
{
	cin >> t;

	while (t--) 
	{
		cin >> n;
		fill(dp, dp + 104, MAX_STR);
		cout << findMin(n) << " " << findMax(n) << "\n";
	}
}