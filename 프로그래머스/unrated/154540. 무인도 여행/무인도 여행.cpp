#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int a[104][104], visited[104][104];
vector<int> answer;

int DFS(int y, int x, int n, int m)
{
    visited[y][x] = 1;
    
    int res = a[y][x];
    
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        if (a[ny][nx] != 0) res += DFS(ny, nx, n, m);
    }
    return res;
}

vector<int> solution(vector<string> maps) {
    
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] - '0' < 10) a[i][j] = maps[i][j] - '0';
            else a[i][j] = 0;
        }
    }
    
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (a[i][j] != 0 && !visited[i][j])
            {
                answer.push_back(DFS(i, j, maps.size(), maps[i].size()));
            }
        }
    }    
    
    if (answer.size() == 0) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    
    return answer;
}