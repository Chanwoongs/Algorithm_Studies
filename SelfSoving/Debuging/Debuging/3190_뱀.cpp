#include <iostream>
#include <deque>
#include <vector>
#include <tuple>
using namespace std;

#define time eeee
#define y1 dddd

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0 ,-1 };
int n, k, l, time, dir = 1, y, x, idx;
int a[104][104], visited[104][104];
deque<pair<int, int>> dq;
vector<pair<int, int>> _time;

int main()
{
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		a[--x][--y] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int sec;
		char dir;
		cin >> sec >> dir;
		if (dir == 'D') _time.push_back({ sec, 1 });
		else _time.push_back({ sec, 3 });
	}

	dq.push_back({ 0, 0 });

	while (dq.size())
	{
		time++;
		tie(y, x) = dq.front();
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		// ���̳� �ڱ� ���� �ε�����
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) break;
	
		// �� �κ� ó��
		// ����� ���ٸ�
		if (!a[ny][nx])
		{
			// ���� �κ� �̹湮 ó�� �� ����
			visited[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
		// ��� ���� ó��
		else a[ny][nx] = 0;

		// �պκ� ó��
		visited[ny][nx] = 1;
		dq.push_front({ ny, nx });
		if (time == _time[idx].first)
		{
			dir = (dir + _time[idx].second) % 4;
			idx++;
		}
	}

	cout << time << '\n';
}