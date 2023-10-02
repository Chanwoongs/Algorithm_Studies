#include <iostream>
#include <map>
#include <queue>

using namespace std;

int a, b, c, d;
map<pair<int, int>, int> m;
queue<pair<int, int>> q;

void enqueue(int x, int y, int d)
{
	if (m[{ x, y }]) return;
	m[{ x, y }] = d + 1;
	q.push({ x, y });
	// visited[nx][ny] = visited[x][y] + 1;
}

int BFS(int x, int y)
{
	m[{x, y}] = 1; // visited[x][y] 를 map으로 구현
	q.push({ x, y });

	while (q.size())
	{
		x = q.front().first;
		y = q.front().second;

		// 한쪽  채우기
		enqueue(a, y, m[{ x, y }]);
		enqueue(x, b, m[{ x, y }]);
		// 한쪽 버리기
		enqueue(0, y, m[{ x, y }]);
		enqueue(x, 0, m[{ x, y }]);

		// x에 남아있는 물이 y에 남아있는 빈 공간보다 적거나 같다면 x물을 모두 y로
		// x에 남아있는 물이 y에 남아있는 빈 공간보다 많다면 y를 꽉채우고 나머지는 x로
		enqueue(std::min(x + y, a), std::max(0, x - a + y ), m[{ x, y }]);
		enqueue(std::max(y - b + x, 0), std::min(x + y, b), m[{ x, y }]);
	}
	if (m[{c, d}] == 1) return m[{c, d}] - 1;
	else return -1; // c, d를 만들지 못했다.
}

int main()
{
	cin >> a >> b >> c >> d;

	cout << BFS(0, 0);
}