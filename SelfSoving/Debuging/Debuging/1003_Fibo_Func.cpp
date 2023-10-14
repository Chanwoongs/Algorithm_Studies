#include <iostream>
#include <queue>
using namespace std;

int t;
pair<int, int> dp[44];

int main()
{
    cin >> t;

    dp[0] = { 1, 0 };
    dp[1] = { 0, 1 };

    for (int i = 2; i <= 40; i++)
    {
        dp[i].first = dp[i - 1].first + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + dp[i - 2].second;
    }

    while (t--)
    {
        int num;
        cin >> num;
        cout << dp[num].first << ' ' << dp[num].second << '\n';
    }
}