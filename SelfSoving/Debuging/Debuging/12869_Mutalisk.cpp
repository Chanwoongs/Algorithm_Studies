#include <iostream>
#include <queue>
using namespace std;

const int INF = 987654321;
int a[3], n, visited[64][64][64];
int _a[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 1, 9},
	{3, 9, 1},
	{1, 3, 9},
	{1, 9, 3}
};

struct A {
	int a, b, c;
};

queue<A> q;
int solve(int a, int b, int c)
{
	visited[a][b][c] = 1;
	q.push({ a, b, c });

	while (q.size())
	{
		A here = q.front();
		q.pop();

		if (visited[0][0][0]) break;

		for (int i = 0; i < 6; i++)
		{
			int na = std::max(0, here.a - _a[i][0]);
			int nb = std::max(0, here.b - _a[i][1]);
			int nc = std::max(0, here.c - _a[i][2]);

			if (visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[here.a][here.b][here.c] + 1;
			q.push({ na, nb, nc });
		}
	}

	return visited[0][0][0] - 1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << solve(a[0], a[1], a[2]) << '\n';
}