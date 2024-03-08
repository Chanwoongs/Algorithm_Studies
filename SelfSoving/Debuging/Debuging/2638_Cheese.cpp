#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m, cnt;
int a[104][104], visited[104][104];
vector<pair<int, int>> eraseablePos;

void BFS(int y, int x)
{
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

            if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        
            if (a[ny][nx] == 0)
            {
                visited[ny][nx] = visited[here.first][here.second] + 1;
                q.push({ ny, nx });
            }
        }
    }
}

void combineAir(int y, int x)
{
    queue<pair<int, int>> q;

    q.push({ y, x });
    visited[y][x] = 1;

    while (q.size())
    {
        pair<int, int> here = q.front();
        q.pop();
        a[here.first][here.second] = 0;

        for (int i = 0; i < 4; i++)
        {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;

            if (a[ny][nx] == 0 || a[ny][nx] == 2)
            {
                visited[ny][nx] = visited[here.first][here.second] + 1;
                q.push({ ny, nx });
            }
        }
    }
}

void color(int y, int x)
{
    queue<pair<int, int>> q;

    q.push({ y, x });
    visited[y][x] = 1;

    while (q.size())
    {
        pair<int, int> here = q.front();
        a[here.first][here.second] = 2;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;

            if (a[ny][nx] == 0)
            {
                visited[ny][nx] = visited[here.first][here.second] + 1;
                q.push({ ny, nx });
            }
        }
    }
}

void eraseCheese(int y, int x)
{
    queue<pair<int, int>> q;

    q.push({ y, x });
    visited[y][x] = 1;

    while (q.size())
    {
        int outAir = 0;
        pair<int, int> here = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];

            if (a[ny][nx] == 0) outAir++;

            if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;

            if (a[ny][nx] == 1)
            {
                visited[ny][nx] = visited[here.first][here.second] + 1;
                q.push({ ny, nx });
            }
            if (outAir >= 2) eraseablePos.push_back({ here.first, here.second });
        }
    }
}

bool checkCheese()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1) return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    while (checkCheese())
    {
        cnt++;

        memset(visited, 0, sizeof(visited));
        BFS(0, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 0 && !visited[i][j])
                {
                    color(i, j);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1 && !visited[i][j])
                {
                    eraseCheese(i, j);
                }
            }
        }

        for (auto pos : eraseablePos)
        {
            a[pos.first][pos.second] = 0;
        }

        memset(visited, 0, sizeof(visited));
        combineAir(0, 0);
    }

    cout << cnt << '\n';
}