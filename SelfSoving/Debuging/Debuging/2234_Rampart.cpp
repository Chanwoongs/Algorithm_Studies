#include <iostream>

using namespace std;

// ���� �� ���� ������ ���� ���� Update 
int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };

int a[54][54], visited[54][54];
int compSize[2504];
int n, m, cnt, mx, big = -1;

int DFS(int y, int x, int cnt)
{
	if (visited[y][x]) return 0;
	visited[y][x] = cnt;

	int res = 1;

	for (int i = 0; i < 4; i++)
	{
		if (!(a[y][x] & (1 << i))) // 1, 2, 4, 8 �Ǵ� ���� 0�̶�� ���� ����.
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
			res += DFS(ny, nx, cnt);
		}
	}
	return res;
}


int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				cnt++; // �� �� ID �ο�
				compSize[cnt] = DFS(i, j, cnt); // CC ������ ����
				mx = std::max(mx, compSize[cnt]); // ���� ū CC ��
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + 1 < m) // overflow üũ
			{
				int a = visited[i + 1][j];
				int b = visited[i][j];
				if (a != b) // �ٸ� CC���
				{
					big = std::max(big, compSize[a] + compSize[b]);
				}
			}
			if (j + 1 < n) // overflow üũ
			{
				int a = visited[i][j + 1];
				int b = visited[i][j];
				if (a != b) // �ٸ� CC���
				{
					big = std::max(big, compSize[a] + compSize[b]);
				}
			}
		}
	}
	cout << cnt << "\n" << mx << "\n" << big << '\n';
}