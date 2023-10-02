#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm> 
 
using namespace std;
int n, w, px[1003], py[1003], dp[1003][1003], y, x;

int d(int a, int b)
{
	return abs(px[a] - px[b]) + abs(py[a] - py[b]);
}

int getSum(int a, int b)
{
	if (a == w + 1 || b == w + 1) return 0; // 모든 사건을 해결했다.
	if (dp[a][b]) return dp[a][b];
	int next = std::max(a, b) + 1; // 다음 사건은 현재 최댓값 + 1
	return dp[a][b] = std::min(getSum(next, b) + d(a, next), getSum(a, next) + d(b, next));
}

void solve()
{
	int a = 0, b = 1;
	for (int i = 2; i < w + 2; i++)
	{
		if (dp[i][b] + d(a, i) < dp[a][i] + d(b, i)) puts("1"), a = i;
		else puts("2"), b = i;
	}
	return;
}

int main()
{
	scanf("%d %d", &n, &w);
	px[0] = 1, py[0] = 1;
	px[1] = n, py[1] = n;

	for (int i = 2; i < w + 2; i++)
	{
		scanf("%d %d", &y, &x);
		px[i] = x, py[i] = y;
	}
	printf("%d\n", getSum(0, 1));
	solve();
}