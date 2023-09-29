#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;
const int INF = 987654321;
int n, a[104], b[104], dp[104][10][10][10][2];

int _mod(int x)
{
	// 반시계로 갈 경우 + 10, 시계로 갈 경우 % 10
	return (x < 0) ? x + 10 : x % 10;
}

int f(int pos, int x, int y, int z, int flag)
{
	if (pos == n) return 0;
	int& res = dp[pos][x][y][z][flag];
	if (~res) return res;

	if (_mod(x + a[pos]) == _mod(b[pos])) 
		return res = std::min(f(pos + 1, y, z, 0, 0), f(pos + 1, y, z, 0, 1));
	
	res = INF;
	int _flag = flag ? 1 : -1;

	// 9가지 모든 경우의 수
	for (int i = 1; i <= 3; i++)
	{
		res = std::min(res, 1 + f(pos, _mod(x + i * _flag), y, z, flag));
		res = std::min(res, 1 + f(pos, _mod(x + i * _flag), _mod(y + i * _flag), z, flag));
		res = std::min(res, 1 + f(pos, _mod(x + i * _flag), _mod(y + i * _flag), _mod(z + i * _flag), flag));
	}

	return res;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%1d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%1d", &b[i]);
	}
	// 시계, 반시계 Start
	printf("%d\n", std::min(f(0, 0, 0, 0, 0), f(0, 0, 0, 0, 1))); 
}