#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, t[20], p[1004], dp[20]; 

int main () 
{
    cin >> n;
    memset(dp, 0, sizeof(dp));
        
    for(int i = 0; i < n; i++) 
        cin >> t[i] >> p[i];
    
    int mx = 0;
    for(int i = 0; i <= n; i++) 
    {
        dp[i] = max(mx, dp[i]);
        
        if (t[i] + i <= n) 
        {
            dp[t[i] + i] = max(dp[t[i] + i], p[i] + dp[i]);
        }
        mx = max(mx, dp[i]);
    }
    cout << mx;
}