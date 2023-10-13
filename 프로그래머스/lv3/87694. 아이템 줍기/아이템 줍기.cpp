#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int a[104][104], x1, x2, y1, y2, visited[104][104];

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    characterX *= 2; characterY *= 2; itemX *= 2; itemY *= 2;
    
    for (int i = 0; i < rectangle.size(); i++)
    {
        for (int j = 0; j < rectangle[0].size(); j++)
        {
            rectangle[i][j] = rectangle[i][j] * 2;
        }
        
        y1 = rectangle[i][1], x1 = rectangle[i][0];
        y2 = rectangle[i][3], x2 = rectangle[i][2];
        
        
        for (int j = y1; j <= y2; j++)
        {
            for (int k = x1; k <= x2; k++)
            {
                a[j][k] = 1;   
            }
        }
    }
    
    for (int i = 0; i < rectangle.size(); i++)
    {

        y1 = rectangle[i][1], x1 = rectangle[i][0];
        y2 = rectangle[i][3], x2 = rectangle[i][2];
        
        
        for (int j = y1 + 1; j < y2; j++)
        {
            for (int k = x1 + 1; k < x2; k++)
            {
                a[j][k] = 0;   
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push({characterY, characterX});
    visited[characterY][characterX] = 1;
    int y, x;
    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        
        if (y == itemY && x == itemX) break;
        
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny <= 0 || nx <= 0 || ny > 100 || nx > 100) continue;
            if (visited[ny][nx]) continue;
            if (a[ny][nx] == 1)
            {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
    
    answer = visited[itemY][itemX] / 2;
    
    return answer;
}