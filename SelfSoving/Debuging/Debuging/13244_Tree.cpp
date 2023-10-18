#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int t, n, m, a, b, visited[1004], cnt;
vector<int> adj[1004];

void DFS(int here)
{
	visited[here] = 1;

	for (int there : adj[here])
	{
		if (!visited[there]) DFS(there);
	}
	return;
}

int main()
{
	scanf("%d\n", &t);
	while (t--)
	{
		for (int i = 0; i < 1004; i++) adj[i].clear();
		fill(visited, visited + 1004, 0);
		cnt = 0;
		scanf("%d %d", &n, &m); // E�� V �Է� ����
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &a, &b); // ����� ���� ����
			adj[b].push_back(a);
			adj[a].push_back(b);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				DFS(i); 
				cnt++;
			}
		}
		if (m == n - 1 && cnt == 1) puts("tree"); // E = V - 1 �̰� DFS �ѹ��� Ž���� �����ϴٸ�
		else
		{
			puts("graph");
		}
	}
}