#include <string>
#include <vector>

using namespace std;

int a[104][104];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for (auto& ele : results)
    {
        a[ele[0]][ele[1]] = 1;
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][k] && a[k][j])
                    a[i][j] = true;
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] || a[j][i])
                cnt++;
        }
        if (cnt == n - 1)
        {
            answer++;
        }
    }
    
    return answer;
}