#include <iostream>
#include <vector>

using namespace std;

const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 0, -1, 0 };

int n, x, y, d, g, cnt, a[101][101];
vector<int> dragon[4][11];

void go(int x, int y, int d, int g)
{
	a[x][y] = 1;
	for (int i = 0; i <= g; i++) // g 세대 까지
	{
		for (int dir : dragon[d][i]) // d로 입력된 방향으로 시작
		{
			x += dx[dir];
			y += dy[dir];
			a[x][y] = 1; // 전부 1로 visited
		}
	}
}

// 갈 방향을 전부 모아 놓음
void makeDragon()
{
	for (int i = 0; i < 4; i++) // 첫 시작 방향 0, 1, 2, 3
	{
		dragon[i][0].push_back(i); // 0 세대
		dragon[i][1].push_back((i + 1) % 4); // 1 세대

		for (int j = 2; j <= 10; j++)
		{
			// 그대로 가져올 이전 세대의 사이즈
			int n = dragon[i][j - 1].size();
			for (int k = n - 1; k >= 0; k--) // 마지막 요소 부터 
			{
				// (이전 세대 역순 + 1) % 4
				dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4); 
			}
			for (int k = 0; k < n; k++)
			{
				// 이전 세대를 그대로 넣음
				dragon[i][j].push_back(dragon[i][j - 1][k]); 
			}
		}
	}
}

int main()
{
	cin >> n;
	makeDragon(); // 바로 드래곤 커브 생성
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> d >> g;
		go(x, y, d, g);
	}
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (a[i][j] && a[i + 1][j] && a[i + 1][j + 1] && a[i][j + 1]) cnt++;
		}
	}
	cout << cnt << '\n';
}