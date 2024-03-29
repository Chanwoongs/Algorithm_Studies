#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    vector<vector<long long>> dp(N, vector<long long>(21, 0));
    dp[0][nums[0]] = 1;

    for (int i = 1; i < N - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (j + nums[i] <= 20) {
                dp[i][j + nums[i]] += dp[i - 1][j];
            }
            if (j - nums[i] >= 0) {
                dp[i][j - nums[i]] += dp[i - 1][j];
            }
        }
    }

    cout << dp[N - 2][nums[N - 1]] << endl;
    return 0;
}