#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int INF = 987654321;
int dist[20004];
vector<vector<int>> adj;
int mx = -1;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    adj.resize(n + 1);
    
    fill (&dist[0], &dist[0] + 20004, -1);
    
    for (int i = 0; i < edge.size(); i++)
    {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while (q.size())
    {
        int cur = q.front();
        int d = dist[cur];
        q.pop();
        
        for (auto ele : adj[cur])
        {
            if (dist[ele] != -1) continue;
            dist[ele] = d + 1;
            
            mx = std::max(mx, dist[ele]);
            q.push(ele);
        }
    }
    
    for (int i = 0; i < 20004; i++)
    {
        if (dist[i] == mx) answer++;
    }
    
    return answer;
}