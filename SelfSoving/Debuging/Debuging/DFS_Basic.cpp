#include <iostream>
#include <vector>
using namespace std;

const int v = 5;

vector<int> adj[v];
int visited[v];

void DFS_(int u)
{
	visited[u] = 1;
	cout << u << '\n';

	for (int ele : adj[u])
	{
		if (ele && visited[ele] == 0) DFS(ele);
	}
	cout << u << "로 부터 시작된 함수가 종료되었습니다.\n";
	return;
}

int main()
{
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[2].push_back(5);
	adj[4].push_back(2);

	DFS(1);
}