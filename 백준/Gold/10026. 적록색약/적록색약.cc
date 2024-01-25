#include <iostream>

using namespace std;

const int dy[] = { 1, 0, -1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, visited1[104][104], visited2[104][104], res1, res2;
char map[104][104];

void DFS1(int y, int x, char col)
{
    visited1[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited1[ny][nx]) continue;

        if (map[ny][nx] == col)
            DFS1(ny, nx, col);
    }
}

void DFS2(int y, int x, char col)
{
    visited2[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited2[ny][nx]) continue;

        if (map[ny][nx] == 'R' || map[ny][nx] == 'G')
        {
            if (col == 'R' || col == 'G')
                DFS2(ny, nx, col);
        }
        else if (map[ny][nx] == col)
            DFS2(ny, nx, col);
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = temp[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited1[i][j])
            {
                DFS1(i, j, map[i][j]);
                res1++;
            }
            if (!visited2[i][j])
            {
                DFS2(i, j, map[i][j]);
                res2++;
            }
        }
    }

    cout << res1 << ' ' << res2;
}