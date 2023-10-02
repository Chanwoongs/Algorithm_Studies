#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int b[1004];
int dp[1004][2][34];

int go(int idx, int tree, int cnt)
{
	// 안되는 부분 배제
	if (cnt < 0) return -1e9;
	// 모든 부분 탐색이 끝났다.
	if (idx == n) return 0;

	int& res = dp[idx][tree][cnt];
	if (~res) return res;

	// 움직인다, 움직이지 않는다.
	return res = std::max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1);
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	cout << std::max(go(0, 1, m - 1), go(0, 0, m)) << '\n';
}