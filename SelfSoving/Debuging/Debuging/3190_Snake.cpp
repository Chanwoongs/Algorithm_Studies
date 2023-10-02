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

	// ����� ��ġ ����
	for (int i = 0; i < k; i++)
	{
		int y, x;
		cin >> y >> x;
		a[--y][--x] = 1;
	}

	// ���� ��ȯ ����
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
		
		// ���� �� ���⿡ ���� ��ġ
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		// ���̳� �ڱ� ���� �ε����� break
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) break;

		// �� �κ� (����) ó��
		if (!a[ny][nx]) // ������ ����� ���ٸ�
		{
			visited[dq.back().first][dq.back().second] = 0; // ������ �̹湮ó�� 
			dq.pop_back(); // ���� ���ֱ�
		}
		else a[ny][nx] = 0; // ��� ���� ó��

		// �� �κ� (�Ӹ�) ó��
		visited[ny][nx] = 1;
		dq.push_front({ ny, nx }); // �Ӹ� �߰�
		if (_time.size() > idx && t == _time[idx].first) // ���� ��ȯ
		{
			dir = (dir + _time[idx].second) % 4;
			idx++;
		}
	}

	cout << t << '\n';
}