#include <iostream>
#include <cstring>

#define MAX_N 16
using namespace std;

const int INF = 987654321;
int n;
int dist[MAX_N][MAX_N], dp[MAX_N][1 << MAX_N];

int tsp(int here, int visited)
{
	if (visited == (1 << n) - 1) // 모든 지점을 방문 했다면
	{
		return dist[here][0] ? dist[here][0] : INF;
	}
	int& res = dp[here][visited];
	if (~res) return res;

	res = INF; // 최솟값은 최댓값부터 시작한다.

	for (int i = 0; i < n; i++)
	{
		if (visited & (1 << i)) continue;
		if (dist[here][i] == 0) continue;
		res = std::min(res, tsp(i, visited | (1 << i)) + dist[here][i]);
	}
	return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> dist[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << tsp(0, 1) << '\n';
}