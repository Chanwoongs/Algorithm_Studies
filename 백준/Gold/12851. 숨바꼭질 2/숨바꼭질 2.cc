#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000;
int visited[MAX + 4];
long long cnt[MAX + 4];

int main()
{
	int n, m;

	cin >> n >> m;

	if (n == m)
	{
		cout << '0' << '\n' << '1' << '\n';
		return 0;
	}

	visited[n] = 1;
	cnt[n] = 1;
	queue<int> q;
	q.push(n);

	while (q.size())
	{
		int now = q.front();
		q.pop();

		for (int next : {now + 1, now - 1, now * 2})
		{
			if (next < 0 || next > MAX) continue;
			if (!visited[next])
			{
				visited[next] = visited[now] + 1;
				cnt[next] += cnt[now];
				q.push(next);
			}
			else if (visited[next] == visited[now] + 1)
			{
				cnt[next] += cnt[now];
			}
		}
	}

	cout << visited[m] - 1 << '\n';
	cout << cnt[m] << '\n';
}