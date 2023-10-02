#include <iostream>
#include <string.h>
using namespace std;

int res, n;

struct Board
{
	int a[24][24];

	void rotate90()
	{
		int temp[24][24];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				temp[i][j] = a[n - j - 1][i]; // 배열 90도 회전
			}
		}
		memcpy(a, temp, sizeof(a));
	}

	void move()
	{
		int temp[24][24];
		for (int i = 0; i < n; i++)
		{
			int idx = -1, isInTemp = 0;
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] == 0) continue;
				if (isInTemp && a[i][j] == temp[i][idx]) // temp에 들어와있고, 같은 값이라면
				{
					temp[i][idx] *= 2;
					isInTemp = 0;
				}
				else // temp 가 비어있다면
				{
					temp[i][++idx] = a[i][j];
					isInTemp = 1;
				}
			}
			for (idx++; idx < n; idx++)
			{
				temp[i][idx] = 0; // 나머지 부분을 다시 0으로 바꿔준다.
			}
		}
		memcpy(a, temp, sizeof(a));
	}

	void getMax()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				res = std::max(res, a[i][j]);
			}
		}
	}
};

void go(Board b, int here) // 완전 탐색
{
	if (here == 5)
	{
		b.getMax();
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		Board c = b;
		c.move();
		go(c, here + 1);
		b.rotate90();
	}
}

int main()
{
	cin >> n;
	Board b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b.a[i][j];
		}
	}
	go(b, 0);

	cout << res << '\n';
}