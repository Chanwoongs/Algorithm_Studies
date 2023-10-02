#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, A[14][14], yangbun[14][14], res;
vector<int> a[14][14];
const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void springSummer()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j].size() == 0) continue; // 나무가 없다.
			int dieTree = 0;
			vector<int> temp;

			sort(a[i][j].begin(), a[i][j].end()); // 어린이부터 양분을 주기 위해 정렬
			for (int tree : a[i][j])
			{
				if (yangbun[i][j] >= tree)
				{
					yangbun[i][j] -= tree;
					temp.push_back(tree + 1); // 나이가 자란 나무 저장
				}
				else
				{
					dieTree += tree / 2; // 죽은 나무가 줄 양분 쌓아두기
				}
			}
			a[i][j] = temp;
			yangbun[i][j] += dieTree;
		}
	}
}

void fall()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j].size() == 0) continue;

			for (int tree : a[i][j])
			{
				if (tree % 5 == 0)
				{
					for (int d = 0; d < 8; d++)
					{
						int ny = i + dy[d];
						int nx = j + dx[d];

						if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
						a[ny][nx].push_back(1);
					}
				}
			}
		}
	}
}

void winter()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			yangbun[i][j] += A[i][j];
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	
	fill(&yangbun[0][0], &yangbun[0][0] + 14 * 14, 5);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		a[x][y].push_back(z);
	}
	for (int i = 0; i < k; i++)
	{
		springSummer();
		fall();
		winter();
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res += a[i][j].size();
		}
	}
	cout << res << '\n';
}