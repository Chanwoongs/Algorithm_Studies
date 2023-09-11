#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
int n, a[11], m, temp, res = INF, comp[11], visited[11];
vector<int> adj[11];

pair<int, int> DFS(int here, int value)
{
	visited[here] = 1;
	pair<int, int> res = { 1, a[here] };

	for (int there : adj[here])
	{
		if (comp[there] != value) continue;
		if (visited[there]) continue;
		pair <int, int> _temp = DFS(there, value);
		res.first += _temp.first;
		res.second += _temp.second;
	}
	return res;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	// 양방향 간선
	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			adj[i].push_back(temp);
			adj[temp].push_back(i);
		}
	}

	for (int i = 1; i < (1 << n) - 1; i++) // 2개의 영역으로 나눠야 하기 때문에 000, 111을 빼서 -1을 해줌
	{
		fill(comp, comp + 11, 0);
		fill(visited, visited + 11, 0);

		int idx1 = -1, idx2 = -1;

		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				comp[j + 1] = 1; // 1로 색칠할 comp 배열의 idx에 1
				idx1 = j + 1;
			}
			else idx2 = j + 1; // 0으로 색칠할 곳의 idx에 0
		}
		pair<int, int> comp1 = DFS(idx1, 1); // first는 1, 0 색깔, second는 더해진 인구수
		pair<int, int> comp2 = DFS(idx2, 0);

		if (comp1.first + comp2.first == n) // 
		{
			res = std::min(res, abs(comp1.second - comp2.second));
		}
	}
	cout << (res == INF ? -1 : res) << '\n';
}