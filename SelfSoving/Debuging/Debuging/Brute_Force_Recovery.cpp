#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[104];
vector<int> v;
int visited[104];

void print()
{
	for (int i : v)
	{
		cout << char(i + 'A') << ' ';
	}
	cout << '\n';
}

// 원복 기본 꼴
//go(int here)
//{
//	visited[there] = 1;
//	go(there);
//	visited[there] = 0;
//}

void go(int idx)
{
	if (v.size() == 3)
	{
		print();
		return;
	}

	for (int there : adj[idx])
	{
		if (visited[there]) continue;
		visited[there] = 1;
		v.push_back(there);
		go(there);
		// 원상 복구
		visited[there] = 0;
		v.pop_back();
	}
}

int main()
{
	adj[0].push_back(1);
	adj[1].push_back(0);
	
	adj[1].push_back(2);
	adj[2].push_back(1);

	adj[1].push_back(3);
	adj[3].push_back(1);

	visited[0] = 1;
	v.push_back(0);
	go(0);


}