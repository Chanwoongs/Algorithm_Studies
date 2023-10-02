#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int dy[] = { 0, 1, 0, -1 }; // 동 남 서 북
const int dx[] = { 1, 0, -1, 0 };

int n, m, k, a[104][104], b[104][104], res = INF, r, c, sec, visited[104][104], dir, sy, sx, ey, ex;
vector<pair<int, int>> vv;
vector<int> vIdx;
struct A {
	int y, x, cnt;
};
vector<A> v;

void go(int y, int x, int first)
{
	// 만약 시작 지점이 아니고, 꼭짓점에 걸리게 되면
	if (!first && y == sy && x == sx) dir++;
	if (!first && y == sy && x == ex) dir++;
	if (!first && y == ey && x == ex) dir++;
	if (!first && y == ey && x == sx) dir++;

	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) return;

	visited[ny][nx] = 1;
	vv.push_back({ ny, nx });

	go(ny, nx, 0);
}

void rotateAll(int y, int x, int cnt)
{
	for (int i = 1; i <= cnt; i++)
	{
		//  돌려야할 사각형의 꼭짓점 명시
		sy = y - 1 * i;
		sx = x - 1 * i;
		ey = y + 1 * i;
		ex = x + 1 * i;

		vv.clear();
		dir = 0;
		memset(visited, 0, sizeof(visited));
		visited[sy][sx] = 1;
		vv.push_back({ sy, sx }); // 시작지점 부터 go
		go(sy, sx, 1); // 여기서 바꿀 모든 좌표를 얻어옴

		vector<int> vvv;
		for (pair<int, int> c : vv) // 바꿀 좌표 Loop
		{
			vvv.push_back(b[c.first][c.second]); // b의 바꿀 좌표의 값을 push
		}
		rotate(vvv.rbegin(), vvv.rbegin() + 1, vvv.rend()); // 값을 돌리기
		for (int i = 0; i < vv.size(); i++)
		{
			b[vv[i].first][vv[i].second] = vvv[i]; // 돌린 값을 다시 b에 저장
		}
	}
}

int solve()
{
	for (int i : vIdx) rotateAll(v[i].y, v[i].x, v[i].cnt); // 수열 3, 1, 2 순으로 돌리기
	int mn = INF;
	// 최소 값 체크
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < m; j++)
		{
			cnt += b[i][j];
		}
		mn = std::min(mn, cnt);
	}
	return mn;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		cin >> r >> c >> sec;
		r--; c--; // 0부터 좌표 시작
		v.push_back({ r, c, sec });
		vIdx.push_back(i); // 0, 1, 2 순서를 바꿔가면서 배열을 돌림
	}

	do {
		memcpy(b, a, sizeof(b)); // 원본 배열을 수정하지 않고 b에 복사해서 수행
		res = std::min(res, solve());
	} while (next_permutation(vIdx.begin(), vIdx.end())); // vIdx를 모든 수열로 만들어 계산

	cout << res << '\n';
}
