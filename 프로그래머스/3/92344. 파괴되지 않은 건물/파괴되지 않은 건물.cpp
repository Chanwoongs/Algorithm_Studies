#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int delta[1004][1004];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    int n = board.size();
    int m = board[0].size();
    
    memset(delta, 0, sizeof(delta));
    
    for (auto s : skill)
    {
        int dg = (s[0] == 1 ? -s[5] : s[5]);
        int r1 = s[1], c1 = s[2], r2 = s[3], c2 = s[4];
        
        delta[r1][c1] += dg;
        delta[r1][c2 + 1] += -dg;
        delta[r2 + 1][c1] += -dg;
        delta[r2 + 1][c2 + 1] += dg;
    }
    
    // 위에서 아래로 계산
    for (int c = 0; c < m; c++)
    {
        for (int r = 1; r < n; r++)
        {
            delta[r][c] += delta[r - 1][c];
        }
    }
    
    // 좌에서 우로 계산    
    for (int r = 0; r < n; r++)
    {
        for (int c = 1; c < m; c++)
        {
            delta[r][c] += delta[r][c - 1];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            board[i][j] += delta[i][j];
            if (board[i][j] > 0) answer++;
        }
    }
    
    return answer;
}