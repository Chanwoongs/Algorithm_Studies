#include <iostream>
#include <cstring>

using namespace std;

int n, m, c, y, x, a[51][51], dp[51][51][51][51];
const int mod = 1000007;

int go(int y, int x, int cnt, int prev)
{
	if (y > n || x > m) return 0;

	if (y == n && x == m)
	{
		if (cnt == 0 && a[y][x] == 0) return 1; // 모두 방문하고 오락실이 아니다
		if (cnt == 1 && a[y][x] > prev) return 1; // 1번 남아있고 현재 오락실이면서 오름차순으로 갈 수 있는 오락실이라면
		return 0; // 끝을 0으로 만들어서 배제 시키기
	}

	int& res = dp[y][x][cnt][prev];
	if (res != -1) return res;

	res = 0;
	if (a[y][x] == 0) // 오락실이 아니다
	{
		res = (go(y + 1, x, cnt, prev) + go(y, x + 1, cnt, prev)) % mod;
	}
	else if (a[y][x] > prev) // 오락실이고 오름차순이다
	{
		res = (go(y + 1, x, cnt - 1, a[y][x]) + go(y, x + 1, cnt - 1, a[y][x])) % mod;
	}
	return res;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> c;

	// 오락실 위치
	for (int i = 1; i <= c; i++)
	{
		cin >> y >> x;
		a[y][x] = i;
	}

	for (int i = 0; i <= c; i++)
	{
		cout << go(1, 1, i, 0) << ' ';
	}
}