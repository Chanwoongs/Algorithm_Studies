#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int n;
int a[12], b[4];
int p, minu, mult, divi;
int maxRes = -9987654321; // 최대 최소 10억 까지 인 것 check 하자
int minRes = 9987654321;

void go(int index, int cur, int plus, int minus, int mul, int div) // 연산자의 개수가 파라미터로 들어옴
{
	if (index == n - 1) // 모든 계산이 끝났을 때
	{
		maxRes = std::max(cur, maxRes);
		minRes = std::min(minRes, cur);

		return;
	}

	if (plus) go(index + 1, cur + a[index + 1], plus - 1, minus, mul, div);
	if (minus) go(index + 1, cur - a[index + 1], plus, minus - 1, mul, div);
	if (mul) go(index + 1, cur * a[index + 1], plus, minus, mul - 1, div);
	if (div) go(index + 1, cur / a[index + 1], plus, minus, mul, div - 1);

	return;
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &a[i]);
	}

	scanf("%d %d %d %d", &p, &minu, &mult, &divi);
	go(0, a[0], p, minu, mult, divi);

	printf("%d\n%d\n", maxRes, minRes);
	return 0;
}