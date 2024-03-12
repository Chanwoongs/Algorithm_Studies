#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

#define INF 99999999
int n, k, tt, visited[100004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    cin >> n >> k;

    pq.push({ 0, n });
    while (pq.size())
    {
        auto tt = pq.top().first;
        auto x = pq.top().second;
        pq.pop();

        if (visited[x]) continue;
        visited[x] = 1;

        if (x == k)
        {
            cout << tt << '\n';
            return 0;
        }

        if (x-1 >= 0 && !visited[x-1])
        {
            pq.push({ tt + 1, x - 1 });
        }
        if (x+1 <= 100000 && !visited[x+1])
        {
            pq.push({ tt + 1, x + 1 });
        }
        if (2*x <= 100000 && !visited[2*x])
        {
            pq.push({ tt, 2*x });
        }
    }
}