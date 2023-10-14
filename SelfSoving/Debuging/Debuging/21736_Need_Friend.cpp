#include <iostream>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m, res;
int sy, sx;
char a[604][604];
int visited[604][604];

void DFS(int y, int x)
{
    visited[y][x] = 1;
    if (a[y][x] == 'P') res++;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        if (a[ny][nx] != 'X') DFS(ny, nx);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            a[i][j] = s[j];
            if (s[j] == 'I')
            {
                sy = i; sx = j;
            }
        }
    }
    DFS(sy, sx);
    if (!res) cout << "TT" << '\n';
    else cout << res << '\n';
}