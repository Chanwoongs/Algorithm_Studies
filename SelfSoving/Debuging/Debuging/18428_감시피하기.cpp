#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, y, x;
char map[10][10];
vector<pair<int, int>> teac, blank;

bool check(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y;
        int nx = x;
        while (ny >= 0 && ny < n && nx >= 0 && nx < n)
        {
            ny += dy[i];
            nx += dx[i];
            if (map[ny][nx] == 'O')
                break;
            if (map[ny][nx] == 'S')
                return false;
        }
    }
    return true;
}

void DFS(int idx, int cnt)
{
    if (cnt == 3)
    {
        for (auto ele : teac)
        {
            if (!check(ele.first, ele.second))
                return;
        }
        cout << "YES" << '\n';
        exit(0);
    }

    for (int i = idx; i < blank.size(); i++)
    {
        int yy = blank[i].first;
        int xx = blank[i].second;

        map[yy][xx] = 'O';
        DFS(i + 1, cnt + 1);
        map[yy][xx] = 'X';
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'T')
                teac.push_back({ i, j });
            else if (map[i][j] == 'X')
                blank.push_back({ i, j });
        }
    }

    DFS(0, 0);

    cout << "NO" << '\n';
}