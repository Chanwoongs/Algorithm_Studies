#include <iostream>
#include <queue>

using namespace std;

#define MAX 500000
int visited[2][MAX + 4], a, b, ok, turn = 1;

int main()
{
	cin >> a >> b; 

	if (a == b) { cout << 0 << '\n'; return 0; }
	queue<int> q;
	visited[0][a] = 1;
	q.push(a);

	while (q.size())
	{
		b += turn;
		if (b > MAX) break;

		// 동생 위치에 미리 방문을 했다면 
		if (visited[turn % 2][b]) 
		{
			ok = true;
			break;
		}

		// Floodfill 색칠하다
		// 한 턴씩 분리한다
		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int x = q.front(); q.pop();
			for (int nx : {x + 1, x - 1, x * 2})
			{
				if (nx < 0 || nx > MAX || visited[turn % 2][nx]) continue;
				visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
				if (nx == b)
				{
					ok = 1; break;
				}
				q.push(nx);
			}
			if (ok) break;
			turn++;
		}
		if (ok) break;
	}

	if (ok) cout << turn << '\n';
	else cout << -1 << '\n';
}