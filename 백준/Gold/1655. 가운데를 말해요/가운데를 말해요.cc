#include <iostream>
#include <queue>

using namespace std;

int n, num;
priority_queue<int, vector<int>, greater<int>> minPQ;
priority_queue<int> maxPQ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;

        if (maxPQ.empty() || maxPQ.top() > num) {
            maxPQ.push(num);
        } else {
            minPQ.push(num);
        }

        while (maxPQ.size() < minPQ.size()) {
            maxPQ.push(minPQ.top());
            minPQ.pop();
        }

        while (maxPQ.size() > minPQ.size() + 1) {
            minPQ.push(maxPQ.top());
            maxPQ.pop();
        }

        cout << maxPQ.top() << '\n';
    }
}