#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int t, n, map[2][100004], dp[2][100004];
int main()
{
    cin >> t;
    while (t--)
    {
        memset(map, 0, sizeof(map));
        memset(dp, 0, sizeof(dp));
        cin >> n;
        
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> map[i][j];
            }
        }
        
        dp[0][0] = map[0][0], dp[1][0] = map[1][0];
        dp[0][1] = map[0][1] + dp[1][0];
        dp[1][1] = map[1][1] + dp[0][0];
        for (int i = 2; i < n; i++)
        {
            dp[0][i] = map[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] = map[1][i] + max(dp[0][i-1], dp[0][i-2]);
        }
        
        cout << max(dp[0][n-1], dp[1][n-1]) << '\n'; 
    }
}