#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int v, a, b, c, maxCost, deepest;
vector<pair<int, int>> adj[100004];
int dist[100004];

int BFS(int start) {
    fill(dist, dist + v + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farthestNode = start;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (auto next : adj[current]) {
            int nextNode = next.first, weight = next.second;

            if (dist[nextNode] == -1) {
                q.push(nextNode);
                dist[nextNode] = dist[current] + weight;

                if (dist[nextNode] > dist[farthestNode]) {
                    farthestNode = nextNode;
                }
            }
        }
    }
    return farthestNode;
}

int main() {
    cin >> v;
    for (int i = 0; i < v; i++) {
        cin >> a;
        while (true) {
            cin >> b;
            if (b == -1) break;
            cin >> c;
            adj[a].push_back({ b, c });
        }
    }

    int farthest = BFS(1);
    BFS(farthest);

    cout << *max_element(dist + 1, dist + v + 1) << '\n';

    return 0;
}