#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

typedef long long ll;
int n, k, y, x, l, res, idx, dir = 1;
int a[104][104], visited[104][104], t;
char c;
deque<pair<int, int>> dq;
vector<pair<int, int>> _time;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int main()
{
	cin >> n >> k;

	// 사과의 위치 저장
	for (int i = 0; i < k; i++)
	{
		int y, x;
		cin >> y >> x;
		a[--y][--x] = 1;
	}

	// 방향 전환 저장
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int t;
		char d;
		cin >> t >> d;
		if (d == 'D') _time.push_back({ t, 1 });
		else _time.push_back({ t, 3 });
	}

	dq.push_back({ 0, 0 });
	visited[0][0] = 1;

	while (dq.size())
	{
		t++;
		tie(y, x) = dq.front();
		
		// 다음 갈 방향에 의한 위치
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		// 벽이나 자기 몸에 부딪히면 break
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) break;

		// 뒷 부분 (꼬리) 처리
		if (!a[ny][nx]) // 갈곳에 사과가 없다면
		{
			visited[dq.back().first][dq.back().second] = 0; // 꼬리쪽 미방문처리 
			dq.pop_back(); // 꼬리 없애기
		}
		else a[ny][nx] = 0; // 사과 먹음 처리

		// 앞 부분 (머리) 처리
		visited[ny][nx] = 1;
		dq.push_front({ ny, nx }); // 머리 추가
		if (_time.size() > idx && t == _time[idx].first) // 방향 전환
		{
			dir = (dir + _time[idx].second) % 4;
			idx++;
		}
	}

	cout << t << '\n';
}