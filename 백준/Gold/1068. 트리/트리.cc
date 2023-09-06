#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[54];
int n, gone, root, temp;

int DFS(int here)
{
	int res = 0;
	int child = 0;
	for (int there : adj[here])
	{
		if (there == gone) continue;
		res += DFS(there);
		child++;
	}
	if (child == 0) return 1; // 리프 노드라면
	return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp == -1) root = i;
		else adj[temp].push_back(i);
	}
	cin >> gone;
	if (gone == root)
	{
		cout << 0 << '\n';
		return 0;
	}

	cout << DFS(root) << '\n';
}