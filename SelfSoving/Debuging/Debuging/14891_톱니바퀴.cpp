#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int k, x, y;
int visited[8];
vector<string> s(4);

void go(int idx, int dir)
{
	if (visited[idx]) return;

	visited[idx] = true;

	if (idx > 0)
	{
		if (s[idx][6] != s[idx - 1][2])
			go(idx - 1, -dir);
	}
	if (idx < 3)
	{
		if (s[idx][2] != s[idx + 1][6])
			go(idx + 1, -dir);
	}

	if (dir == 1) // 시계 회전
		rotate(s[idx].rbegin(), s[idx].rbegin() + 1, s[idx].rend());
	else // 반시계 회전
		rotate(s[idx].begin(), s[idx].begin() + 1, s[idx].end());
}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		cin >> s[i];
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		memset(visited, 0, sizeof(visited));
		cin >> x >> y;
		go(x - 1, y);
	}
	int res = 0;
	for (int i = 0; i < 4; i++)
	{
		if (s[i][0] == '1') res += (1 << i);
	}
	cout << res << '\n';
}