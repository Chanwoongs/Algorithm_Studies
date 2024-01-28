#include <iostream>

using namespace std;

int t, n, res;
int dp[10004];

int main()
{
    cin >> t;
    dp[0] = 1;
    
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 10000; j++)
        {
            if (j - i >= 0) dp[j] += dp[j - i]; 
        }
    }
    while (t--)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }
}