#include <iostream>

using namespace std;

int a[4][4], n, m, res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}

	// 0일 때 가로, 1일 때 세로
	for (int s = 0; s < (1 << (n * m)); s++) // 모든 경우의 수
	{
		int sum = 0;
		// 가로 다 더하기
		for (int i = 0; i < n; i++)
		{
			int cur = 0;
			for (int j = 0; j < m; j++)
			{
				int k = i * m + j;
				if ((s & (1 << k)) == 0)
				{
					cur = cur * 10 + a[i][j]; // 자릿 수 맞추기
				}
				else // 가로가 끝났다.
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		// 세로 다 더하기
		for (int i = 0; i < m; i++)
		{
			int cur = 0;
			for (int j = 0; j < n; j++)
			{
				int k = i * m + j;
				if ((s & (1 << k)) != 0)
				{
					cur = cur * 10 + a[i][j];
				}
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		res = std::max(res, sum);
	}
	cout << res << '\n';
}