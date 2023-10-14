#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int a, b, t;
int visited[10004];

void BFS()
{
    queue<pair<int, string>> q;

    q.push({ a, "" });
    visited[a] = 1;

    while (q.size())
    {
        pair<int, string> here = q.front();
        int num = here.first;
        string s = here.second;

        q.pop();

        if (num == b)
        {
            cout << s << '\n';
            return;
        }

        int D = (num * 2) % 10000;
        if (!visited[D])
        {
            visited[D] = 1;
            q.push({ D, s + "D" });
        }
        int S = num - 1 >= 0 ? num - 1 : 9999;
        if (!visited[S])
        {
            visited[S] = 1;
            q.push({ S, s + "S" });
        }
        int L = (num % 1000) * 10 + num / 1000;
        if (!visited[L])
        {
            visited[L] = 1;
            q.push({ L, s + "L" });
        }
        int R = (num / 10) + (num % 10) * 1000;
        if (!visited[R])
        {
            visited[R] = 1;
            q.push({ R, s + "R" });
        }
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        fill(visited, visited + 10004, 0);
        BFS();
    }
}