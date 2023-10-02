#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int a[104][104];
int visited[104][104];
int n, m, sy, sx, ey, ex, ny, nx;

void BFS(int y, int x)
{
    queue<pair<int, int>> q;

    visited[y][x] = 1;
    q.push({ y, x });

    while (q.size())
    {
        pair<int, int> here = q.front();
        q.pop();
        //cout << "visited : " << here.first << ", " << here.second << '\n';
        for (int i = 0; i < 4; i++)
        {
            ny = here.first + dy[i];
            nx = here.second + dx[i];

            if (ny < 0 || nx >= m || nx < 0 || ny >= n || a[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;

            visited[ny][nx] = visited[here.first][here.second] + 1;
            q.push({ ny, nx });
        }
    }
}

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
    BFS(0, 0);
    printf("%d", visited[n - 1][m - 1]);
}