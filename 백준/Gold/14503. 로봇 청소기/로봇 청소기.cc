#include <iostream>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, y, x, d, res;
int map[54][54];

bool move(bool back)
{
    if (back)
    {
        if (d == 0)
        {
            if (y + 1 >= n || map[y + 1][x] == 1) return false;
            y += 1;
        }
        else if (d == 2)
        {
            if (y - 1 < 0 || map[y - 1][x] == 1) return false;
            y -= 1;
        }
        else if (d == 1)
        {
            if (x - 1 < 0 || map[y][x - 1] == 1) return false;
            x -= 1;
        }
        else if (d == 3)
        {
            if (x + 1 >= m || map[y][x + 1] == 1) return false;
            x += 1;
        }
    }
    else
    {
        if (d == 0)
        {
            if (map[y - 1][x] == 0)
                y -= 1;
        }
        else if (d == 2)
        {
            if (map[y + 1][x] == 0)
                y += 1;
        }
        else if (d == 1)
        {
            if (map[y][x + 1] == 0)
                x += 1;
        }            
        else if (d == 3)
        {
            if (map[y][x - 1] == 0)
                x -= 1;
        }
    }

    return true;
}

void rotate()
{
    if (d == 0) d = 3;
    else if (d == 1) d = 0;
    else if (d == 2) d = 1;
    else if (d == 3) d = 2;
}

bool checkEmpty()
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

        if (map[ny][nx] == 0) return true;
    }
    return false;
}

bool check()
{
    if (map[y][x] == 0)
    {
        map[y][x] = 2;
        res++;
        return true;
    }

    if (checkEmpty())
    {
        rotate();
        move(false);
        return true;
    }
    else
    {
        if (!move(true)) return false;
        return true;
    }
}

int main()
{
    cin >> n >> m;
    cin >> y >> x >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    while (check())
    {}

    cout << res << '\n';
}