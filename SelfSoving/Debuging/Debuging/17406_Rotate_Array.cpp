#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int dy[] = { 0, 1, 0, -1 }; // �� �� �� ��
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
	// ���� ���� ������ �ƴϰ�, �������� �ɸ��� �Ǹ�
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
		//  �������� �簢���� ������ ���
		sy = y - 1 * i;
		sx = x - 1 * i;
		ey = y + 1 * i;
		ex = x + 1 * i;

		vv.clear();
		dir = 0;
		memset(visited, 0, sizeof(visited));
		visited[sy][sx] = 1;
		vv.push_back({ sy, sx }); // �������� ���� go
		go(sy, sx, 1); // ���⼭ �ٲ� ��� ��ǥ�� ����

		vector<int> vvv;
		for (pair<int, int> c : vv) // �ٲ� ��ǥ Loop
		{
			vvv.push_back(b[c.first][c.second]); // b�� �ٲ� ��ǥ�� ���� push
		}
		rotate(vvv.rbegin(), vvv.rbegin() + 1, vvv.rend()); // ���� ������
		for (int i = 0; i < vv.size(); i++)
		{
			b[vv[i].first][vv[i].second] = vvv[i]; // ���� ���� �ٽ� b�� ����
		}
	}
}

int solve()
{
	for (int i : vIdx) rotateAll(v[i].y, v[i].x, v[i].cnt); // ���� 3, 1, 2 ������ ������
	int mn = INF;
	// �ּ� �� üũ
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
		r--; c--; // 0���� ��ǥ ����
		v.push_back({ r, c, sec });
		vIdx.push_back(i); // 0, 1, 2 ������ �ٲ㰡�鼭 �迭�� ����
	}

	do {
		memcpy(b, a, sizeof(b)); // ���� �迭�� �������� �ʰ� b�� �����ؼ� ����
		res = std::min(res, solve());
	} while (next_permutation(vIdx.begin(), vIdx.end())); // vIdx�� ��� ������ ����� ���

	cout << res << '\n';
}
