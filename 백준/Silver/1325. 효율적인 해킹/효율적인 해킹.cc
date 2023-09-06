#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[10004];
vector<int> temp, res;
int visited[10004];
int n, m;
int A, B;

int DFS(int here)
{
	int cnt = 1;
	visited[here] = 1;

	for (int there : adj[here])
	{
		if (visited[there]) continue;
		cnt += DFS(there);
	}

	return cnt;
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> A >> B;
		adj[B].push_back(A);
	}

	for (int i = 1; i <= n; i++)
	{
		temp.push_back(DFS(i));
		fill(&visited[0], &visited[0] + 10004, 0);
	}

	int max = -1;
	for (int i = 1; i <= n; i++)
	{
		if (temp[i - 1] > max)
		{
			res.clear();
			res.push_back(i);
			max = temp[i - 1];
		}
		else if (temp[i - 1] == max)
		{
			res.push_back(i);
		}
	}

	for (int ele : res)
	{
		cout << ele << ' ';
	}
}