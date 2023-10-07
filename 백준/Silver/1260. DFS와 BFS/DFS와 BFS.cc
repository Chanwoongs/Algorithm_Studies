#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v, visited[1004];
vector<int> adj[1004];

void DFS(int here)
{
    visited[here] = true;
    cout << here << ' ';

    for (auto ele : adj[here])
    {
        if (visited[ele]) continue;
        DFS(ele);
    }
}

void BFS(int here)
{
    queue<int> q;
    q.push(here);
    visited[here] = true;

    while (q.size())
    {
        int next = q.front();
        cout << next << ' ';
        q.pop();

        for (auto ele : adj[next])
        {
            if (visited[ele]) continue;
            visited[ele] = true;
            q.push(ele);
        }
    }
}

int main()
{
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (auto &ele : adj)
    {
        sort(ele.begin(), ele.end());
    }

    DFS(v);
    fill(visited, visited + 1004, 0);
    cout << '\n';
    BFS(v);
}