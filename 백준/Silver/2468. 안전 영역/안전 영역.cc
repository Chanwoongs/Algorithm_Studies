#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int a[104][104], visited[104][104];
int n, safe = 1, temp;

void DFS(int y, int x, int height)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx >= n || nx < 0 || ny >= n) continue;
		if (visited[ny][nx]) continue;

		if (a[ny][nx] > height) DFS(ny, nx, height);
	}
}

int main()
{
    cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	// height test
	for (int i = 1; i <= 100; i++)
	{
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		temp = 0;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (a[j][k] > i && visited[j][k] == 0)
				{
					DFS(j, k, i);
					temp++;
				}
			}
		}
		if (safe < temp) safe = temp;
	}

	cout << safe << '\n';
}