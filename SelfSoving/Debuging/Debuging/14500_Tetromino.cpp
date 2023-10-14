#include <iostream>
#include <queue>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0 ,-1 };
int n, m, res;
int a[504][504], visited[504][504];

void DFS(int y, int x, int cnt, int val)
{
    if (cnt == 4) res = std::max(res, val);
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 1 || nx < 1 || ny > n || nx > m) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            DFS(ny, nx, cnt + 1, val + a[ny][nx]);
            visited[ny][nx] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            visited[i][j] = 1;
            DFS(i, j, 1, a[i][j]);
            visited[i][j] = 0;

            if (i > 1 && j >= 1 && i <= n && j < m - 1)
            {
                res = std::max(res, (a[i][j] + a[i - 1][j + 1] + a[i][j + 1] + a[i][j + 2]));
            }
            if (i >= 1 && j >= 1 && i < n - 1 && j < m)
            {
                res = std::max(res, (a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 1][j + 1]));
            }
            if (i >= 1 && j >= 1 && i < n && j < m - 1)
            {
                res = std::max(res, (a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 1]));
            }
            if (i > 1 && j >= 1 && i < n && j < m)
            {
                res = std::max(res, (a[i][j] + a[i - 1][j + 1] + a[i][j + 1] + a[i + 1][j + 1]));
            }
        }
    }

    cout << res << '\n';
}