#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b;
int indegree[32004];
vector<vector<int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin >> n >> m;
    
    v.resize(n + 1);
    
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (!indegree[i]) pq.push(i);
    }
    
    while (pq.size())
    {
        int cur = pq.top();
        pq.pop();
        cout << cur << ' ';
        
        for (int nxt : v[cur])
        {
            indegree[nxt]--;
            if (!indegree[nxt]) pq.push(nxt);
        }
    }
   
    return 0;
}