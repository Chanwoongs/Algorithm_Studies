#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int dz[] = { 1, 0, 0, -1, 0, 0 };
const int dy[] = { 0, -1, 0, 0, 1, 0 };
const int dx[] = { 0, 0, 1, 0, 0, -1 };

int n, m, h, res;
int a[104][104][104];

struct Point
{
    int y, x, z;
};

queue<Point> q;

void BFS()
{
    while (q.size())
    {
        int size = q.size();
        res++;

        for (int w = 0; w < size; w++)
        {
            int y = q.front().y;
            int x = q.front().x;
            int z = q.front().z;
             
            q.pop();

            for (int i = 0; i < 6; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                int nz = z + dz[i];

                if (ny < 0 || nx < 0 || nz < 0 || ny >= n || nx >= m || nz >= h) continue;
                if (a[ny][nx][nz] == 0)
                {
                    a[ny][nx][nz] = 1;
                    q.push({ ny, nx, nz });
                }
            }
        }
    }
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j][k] == 0)
                {
                    cout << -1;
                    return;
                }
            }
        }
    }
    cout << res - 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> h;

    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j][k];
                if (a[i][j][k] == 1)
                {
                    q.push({ i, j, k });
                }
            }
        }
    }
    BFS();
}