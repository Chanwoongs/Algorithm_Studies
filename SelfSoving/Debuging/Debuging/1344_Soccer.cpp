#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

const int n = 18;
bool che[24];
double a, b, dp[20][20][20];

double go(int idx, int x, int y)
{
	if (idx == n) return che[x] || che[y] ? 1.0 : 0.0;

	double& res = dp[idx][x][y];
	if (res > -0.5) return res;

	// 경우의 수는 더하기다
	// 확률은 경우의 수 곱하기 확률이다.
	res = 0.0;
	res += go(idx + 1, x + 1, y) * a * (1 - b);
	res += go(idx + 1, x, y + 1) * (1 - a) * b;
	res += go(idx + 1, x + 1, y + 1) * a * b;
	res += go(idx + 1, x, y) * (1 - a) * (1 - b);

	return res;
}

void era()
{
	int temp[24] = {};

	for (int i = 2; i <= 20; i++) 
	{
		if (temp[i]) continue;
		for (int j = 2 * i; j <= 20; j += i) 
		{
			temp[j] = 1;
		}
	}
	for (int i = 2; i <= 20; i++)
	{
		if (temp[i] == 0) che[i] = 1;
	}
}

int main()
{
	scanf("%lf %lf", &a, &b);
	a /= 100; b /= 100;
	era();
	memset(dp, -1, sizeof(dp));
	printf("%.6lf", go(0, 0, 0));
}