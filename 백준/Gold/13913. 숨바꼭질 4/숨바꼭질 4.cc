#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define prev aaa
#define next aaaa

const int MAX = 200004;
int visited[MAX], prev[MAX], n, k , res, here, cnt, next;

vector<int> v;
queue<int> q;

int main()
{
	int n, k;
	cin >> n >> k;


	visited[n] = 1;
	q.push(n);

	while (q.size())
	{
		int here = q.front();
		q.pop();

		if (here == k)
		{
			res = visited[k];
			break;
		}

		for (int next : {here + 1, here - 1, here * 2})
		{
			if (next < 0 || next > MAX) continue;

			if (visited[next]) continue;
			
			visited[next] = visited[here] + 1;
			prev[next] = here;
			q.push(next);
		}
	}
	for (int i = k; i != n; i = prev[i])
	{
		v.push_back(i);
	}
	v.push_back(n);
	cout << res - 1 << '\n';
	reverse(v.begin(), v.end());
	for (int ele : v) cout << ele << ' ';
}