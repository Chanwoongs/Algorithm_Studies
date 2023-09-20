#include <iostream>
#include <map>

using namespace std;

int a[1001], b[1001], res, want, n, m;
int psumA[2002], psumB[2002]; // 뒤에 배열을 덧붙여 원형 자료구조 -> 선형 자료구조
map<int, int> aCnt, bCnt;

void make(int n, int psum[], map<int, int>& mp)
{
	for (int interval = 1; interval <= n; interval++) // 1개짜리, 2개짜리.... 구간의 크기
	{
		for (int start = interval; start <=  n + interval - 1; start++)
		{
			int sum = psum[start] - psum[start - interval]; // 구간 - 구간
			mp[sum]++;
			if (interval == n) break;
		}
	}
}

int main()
{
	cin >> want >> n >> m;
	
	// A 누적합 만들기
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		psumA[i] = psumA[i - 1] + a[i];
	}
	for (int i = n + 1; i <= 2 * n; i++)
	{
		psumA[i] = psumA[i - 1] + a[i - n];
	}
	// B 누적합 만들기
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
		psumB[i] = psumB[i - 1] + b[i];
	}
	for (int i = m + 1; i <= 2 * m; i++)
	{
		psumB[i] = psumB[i - 1] + b[i - m];
	}

	// 모든 경우의 수 만들기
	make(n, psumA, aCnt);
	make(m, psumB, bCnt);

	res = aCnt[want] + bCnt[want]; // 각각의 피자에서 해결 가능한 경우
	for (int i = 1; i < want; i++)
	{
		res += (aCnt[i] * bCnt[want - i]); // 서로 더하여 want가 되는 경우
	}
	cout << res << '\n';
}