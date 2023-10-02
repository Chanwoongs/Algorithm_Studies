#include <iostream>
#include <vector>
#include <cstring>

#define MAX_N 100001 
using namespace std;
int dp[5][5][MAX_N], n;
vector<int> v;

int check(int from, int to)
{
	// ���� ���
	if (from == 0) return 2;
	// ���� �� ������
	if (from == to) return 1;
	// �ݴ� ������
	if (abs(from - to) == 2) return 4;
	// ������ ��
	return 3;
}

int solve(int y, int x, int target) // ����ġ, ����ġ, ���� idx
{
	if (target == n) return 0;

	if (dp[y][x][target] != -1) return dp[y][x][target];

	int right = solve(v[target], y, target + 1) + check(x, v[target]);
	int left = solve(x, v[target], target + 1) + check(y, v[target]);

	return dp[y][x][target] = std::min(left, right);
}

int main()
{
	while (true)
	{
		int num;
		cin >> num;
		if (num == 0) break;
		v.push_back(num);
	}

	memset(dp, -1, sizeof(dp));

	n = v.size();
	cout << solve(0, 0, 0) << '\n';
}