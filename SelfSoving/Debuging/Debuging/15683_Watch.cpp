#include <iostream>
#include <queue>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int a[10][10];
int n, m, res = 9999;

vector<pair<int, int>> v;

vector<pair<int, int>> extendCCTV(int here, int dir)
{
	vector<pair<int, int>> _change;
	int y = v[here].first;
	int x = v[here].second;

	if (a[y][x] == 1)
	{
		while (true)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6) // 벽이 아니라면
			{
				if (a[ny][nx] == 0)
				{
					a[ny][nx] = 8; // 0~6 외의 숫자로 탐색 표기
					_change.push_back({ ny, nx }); // 바꾼 값들 저장
				}
				y = ny;
				x = nx;
			}
			else break;
		}
	}
	else if (a[y][x] == 2)
	{
		for (int i = 0; i <= 2; i += 2) // 양방향을 위해
		{
			int _y = y;
			int _x = x;

			while (true)
			{
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];

				if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6) // 벽이 아니라면
				{
					if (a[ny][nx] == 0)
					{
						a[ny][nx] = 8; // 0~6 외의 숫자로 탐색 표기
						_change.push_back({ ny, nx }); // 바꾼 값들 저장
					}
					_y = ny;
					_x = nx;
				}
				else break;
			}
		}
	}
	else if (a[y][x] == 3)
	{
		for (int i = 0; i < 2; i++)
		{
			int _y = y;
			int _x = x;

			while (true)
			{
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];

				if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6) // 벽이 아니라면
				{
					if (a[ny][nx] == 0)
					{
						a[ny][nx] = 8; // 0~6 외의 숫자로 탐색 표기
						_change.push_back({ ny, nx }); // 바꾼 값들 저장
					}
					_y = ny;
					_x = nx;
				}
				else break;
			}
		}
	}
	else if (a[y][x] == 4)
	{
		for (int i = 0; i < 3; i++) // ㅗ 방향
		{
			int _y = y;
			int _x = x;

			while (true)
			{
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];

				if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6) // 벽이 아니라면
				{
					if (a[ny][nx] == 0)
					{
						a[ny][nx] = 8; // 0~6 외의 숫자로 탐색 표기
						_change.push_back({ ny, nx }); // 바꾼 값들 저장
					}
					_y = ny;
					_x = nx;
				}
				else break;
			}
		}
	}
	else if (a[y][x] == 5)
	{
		for (int i = 0; i < 4; i++) // ㅗ 방향
		{
			int _y = y;
			int _x = x;

			while (true)
			{
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];

				if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6) // 벽이 아니라면
				{
					if (a[ny][nx] == 0)
					{
						a[ny][nx] = 8; // 0~6 외의 숫자로 탐색 표기
						_change.push_back({ ny, nx }); // 바꾼 값들 저장
					}
					_y = ny;
					_x = nx;
				}
				else break;
			}
		}
	}
	return _change;
}

void DFS(int here)
{
	if (here == v.size())
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				// 사각 지대라면
				if (a[i][j] == 0) cnt++;
			}
		}
		res = min(cnt, res);
		return;
	}

	// CCTV 배치
	for (int k = 0; k < 4; k++)
	{
		// 현재 CCTV 하나에 대한 탐색
		vector<pair<int, int>> _change = extendCCTV(here, k);
		DFS(here + 1);
		// 원복
		for (auto c : _change) a[c.first][c.second] = 0;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			// CCTV 위치 저장
			if (a[i][j] != 6 && a[i][j] != 0) v.push_back({ i, j });
		}
	}
	DFS(0);
	cout << res << "\n";
}