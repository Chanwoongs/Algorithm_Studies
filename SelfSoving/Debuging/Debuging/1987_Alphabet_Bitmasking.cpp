#include <iostream>
#include <string>
using namespace std;
const int INF = 987654321;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int a[24][24];
int r, c, res;

void go(int y, int x, int num, int cnt)
{
	res = max(res, cnt);

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		int _next = (1 << (int)(a[ny][nx] - 'A'));
		// 7 & 4 111 & 100 = 100 true �� �� ���� �湮 �߳� ���߳�
		if ((num & _next) == 0) go(ny, nx, num | _next, cnt + 1); // num | next �� ���� 111 | 10000 = 10111 ���� �Ű�����
	}
	return;
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			a[i][j] = s[j];
		}
	}

	go(0, 0, (1 << (int)a[0][0] - 'A'), 1);

	cout << res << '\n';
}