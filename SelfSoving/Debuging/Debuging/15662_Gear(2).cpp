#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int t, k, dir, res;
int visited[1004];
int r = 2, l = 6;
vector<vector<int>> gs;
vector<pair<int, int>> v;

void go(int idx, int dir)
{
	if (visited[idx]) return;
	visited[idx] = true;

	if (dir == 1)
		rotate(gs[idx].rbegin(), gs[idx].rbegin() + 1, gs[idx].rend());
	else if (dir == -1)
		rotate(gs[idx].begin(), gs[idx].begin() + 1, gs[idx].end());

	if (idx + 1 < t && gs[idx][r] != gs[idx + 1][l]) 
		go(idx + 1, -dir);
	if (idx - 1 >= 0 && gs[idx][l] != gs[idx - 1][r]) 
		go(idx - 1, -dir);
}

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string s;
		vector<int> v;
		cin >> s;
		gs.push_back(v);
		for (char c : s)
		{
			gs[i].push_back(c - '0');
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a - 1, b });
	}

	for (pair<int, int> p : v)
	{
		fill(visited, visited + 1004, 0);
		go(p.first, p.second);
	}
	for (auto g : gs) if (g[0] == 1) res++;

	cout << res << '\n';
}