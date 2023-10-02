#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[10004];
vector<int> temp, res;
int visited[10004];
int n, m;
int A, B;

int temp2[10004];

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

	//// 规过 1
	//for (int i = 1; i <= n; i++)
	//{
	//	fill(&visited[0], &visited[0] + 10004, 0);
	//	temp.push_back(DFS(i));
	//}

	//int max1 = -1;
	//for (int i = 1; i <= n; i++)
	//{
	//	if (temp[i - 1] > max1)
	//	{
	//		res.clear();
	//		res.push_back(i);
	//		max1 = temp[i - 1];
	//	}
	//	else if (temp[i - 1] == max1)
	//	{
	//		res.push_back(i);
	//	}
	//}

	//for (int ele : res)
	//{
	//	cout << ele << ' ';
	//}

	// 规过 2
	int max2 = -1;
	for (int i = 1; i <= n; i++)
	{
		fill(&visited[0], &visited[0] + 10004, 0);
		temp2[i] = DFS(i);
		max2 = max(temp2[i], max2);
	}
	for (int i = 1; i <= n; i++)
	{
		if (temp2[i] == max2) cout << i << ' ';
	}
}

//vector<int> adj2[10004];
//int visited2[10004];
//
//int dfs(int here)
//{
//	int res = 1;
//	for (int i : adj[here])
//	{
//		if (visited2[i]) continue;
//		visited2[i] = 1;
//		res += dfs(i);
//	}
//	return res;
//}
//
//int main()
//{
//	adj2[1].push_back(2);
//	adj2[1].push_back(3);
//	visited2[1] = 1;
//	cout << dfs(1) << '\n';
//}