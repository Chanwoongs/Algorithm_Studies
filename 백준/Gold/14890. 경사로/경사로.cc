#include <iostream>

using namespace std;

int a[104][104], b[104][104];
int n, l, res;

void solve(int a[104][104])
{
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		int j;
		for (j = 0; j < n - 1; j++)
		{
			if (a[i][j] == a[i][j + 1]) cnt++;

			// 오르막길 성립되면 다시 cnt = 1로
			else if (a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1;

			// 내리막길 성립되면 음수로 만들어서 0이상이 되면
			else if (a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1;
			else break;
		}
		// 전체 다 돌고 길이 있다면
		if (j == n - 1 && cnt >= 0) res++;
	}
	return;
}

int main()
{
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			b[j][i] = a[i][j]; // 대칭으로 된 배열을 하나 더 만듦
		}
	}
	solve(a);
	solve(b);

	cout << res << '\n';
}