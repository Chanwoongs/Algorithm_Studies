#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int a[26][26], visited[26][26];
int cnt, n;
int houseCnt[26];

int BFS(int y, int x)
{
    int num = 1;
    queue<pair<int, int>> q;
    q.push({ y, x });
    visited[y][x] = 1;

    while (q.size())
    {
        pair<int, int> here = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
            if (a[ny][nx] == 1)
            {
                visited[ny][nx] = 1;
                q.push({ ny, nx });
                num++;
            }
        }
    }
    return num;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            a[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] && !visited[i][j])
            {
                houseCnt[cnt++] = BFS(i, j);
            }
        }
    }

    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++)
    {
        cout << houseCnt[i] << '\n';
    }
}