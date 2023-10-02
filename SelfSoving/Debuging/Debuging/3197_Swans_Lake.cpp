#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define prev aaa;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int a[1504][1504], visited[1504][1504], visitedSwan[1504][1504];
vector<pair<int, int>> prev;
int r, c, t;
queue<pair<int, int>> waterQ, waterTempQ, swanQ, swanTempQ;
string s;
int swanY, swanX;

void QClear(queue<pair<int, int>>& q)
{
	queue<pair<int, int>> empty;
	swap(q, empty);
}

void meltWater()
{
	while (waterQ.size())
	{
		pair<int, int> here = waterQ.front();
		waterQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;

			if (a[ny][nx] == 'X')
			{
				visited[ny][nx] = 1;
				waterTempQ.push({ ny, nx });
				a[ny][nx] = '.';
			}
		}
	}
}

bool moveSwan()
{
	while (swanQ.size())
	{
		pair<int, int> here = swanQ.front();
		swanQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c || visitedSwan[ny][nx]) continue;

			visitedSwan[ny][nx] = 1;

			if (a[ny][nx] == '.') swanQ.push({ ny, nx });
			else if (a[ny][nx] == 'X') swanTempQ.push({ ny, nx });
			else if (a[ny][nx] == 'L') return true;
		}
	}
	return false;
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			a[i][j] = s[j];
			if (a[i][j] == 'L') { swanY = i; swanX = j; }
			if (a[i][j] == '.' || a[i][j] == 'L')
			{
				visited[i][j] = 1;
				waterQ.push({ i, j });
			}
		}
	}

	swanQ.push({ swanY, swanX });
	visitedSwan[swanY][swanX] = 1;

	while (true)
	{
		if (moveSwan()) break;
		meltWater();
		waterQ = waterTempQ;
		swanQ = swanTempQ;
		QClear(waterTempQ);
		QClear(swanTempQ);
		t++;
	}
	cout << t << '\n';
}