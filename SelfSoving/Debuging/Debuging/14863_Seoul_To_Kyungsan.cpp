#include <iostream>
#include <queue>

using namespace std;

struct A {
	int wt, wm, bt, bm;
};

int n, k, wt, wm, bt, bm;
int dp[104][100004];

A a[104];

int go(int idx, int time)
{
	if (idx == n) return 0;

	int& res = dp[idx][time];
	if (res) return res;
	res = -1e6;

	if (time - a[idx].wt >= 0) res = std::max(res, go(idx + 1, time - a[idx].wt) + a[idx].wm);
	if (time - a[idx].bt >= 0) res = std::max(res, go(idx + 1, time - a[idx].bt) + a[idx].bm);
	
	return res;
}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> wt >> wm >> bt >> bm;
		a[i].wt = wt;
		a[i].wm = wm;
		a[i].bt = bt;
		a[i].bm = bm;
	}

	cout << go(0, k) << '\n';
	 
	// GPT Suggestion
	// 
	//for (int idx = 0; idx < n; idx++) {
	//	for (int time = k; time >= 0; time--) {
	//		if (time + a[idx].wt <= k)
	//			dp[idx + 1][time + a[idx].wt] = max(dp[idx + 1][time + a[idx].wt], dp[idx][time] + a[idx].wm);
	//		if (time + a[idx].bt <= k)
	//			dp[idx + 1][time + a[idx].bt] = max(dp[idx + 1][time + a[idx].bt], dp[idx][time] + a[idx].bm);
	//		dp[idx + 1][time] = max(dp[idx + 1][time], dp[idx][time]); // 현재 항목을 선택하지 않는 경우
	//	}
	//}

	//cout << dp[n][k] << '\n';

}