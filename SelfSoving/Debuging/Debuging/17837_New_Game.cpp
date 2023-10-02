#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	int y, x, dir;
};

int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1,-1, 0, 0 };

int n, k, a[14][14], y, x, dir;

vector<int> v[14][14];
vector<Point> status;

void move(int y, int x, int dir, int i)
{
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx] == 2)
	{
		status[i].dir ^= 1; // 방향 전환
		
		ny = y + dy[status[i].dir];
		nx = x + dx[status[i].dir];

		// 방향 전환해도 벗어난다면
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx] == 2) return;
	}
	
	// 한칸 이동 로직
	vector<int>& here_v = v[y][x];
	vector<int>& next_v = v[ny][nx];

	// 현재 말이 쌓여있는 위치
	auto pos = find(here_v.begin(), here_v.end(), i);
	
	if (a[ny][nx] == 1) reverse(pos, here_v.end());

	for (auto it = pos; it != here_v.end(); it++)
	{
		next_v.push_back(*it);
		status[*it].y = ny;
		status[*it].x = nx;
	}
	here_v.erase(pos, here_v.end());
	return;
}

bool isOver()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j].size() >= 4)
			{
				return true;
			}
		}
	}
	return false;
}

bool simul()
{
	for (int i = 0; i < status.size(); i++)
	{
		int y = status[i].y;
		int x = status[i].x;
		int dir = status[i].dir;
		move(y, x, dir, i);
		// 진행되는 도중 말이 4이상인 칸이 있으면 종료된다.
		if (isOver()) return 1;
	}
	return 0;
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		cin >> y >> x >> dir; y--; x--; dir--;
		v[y][x].push_back(i);
		status.push_back({ y, x, dir });
	}

	int cnt = 0;
	bool flag = 0;

	while (cnt <= 1000)
	{
		cnt++;
		if (simul()) // 4개의 말이 올라가있다.
		{
			flag = 1;
			break;
		}
	}
	if (flag) cout << cnt << '\n';
	else cout << -1 << '\n';
}