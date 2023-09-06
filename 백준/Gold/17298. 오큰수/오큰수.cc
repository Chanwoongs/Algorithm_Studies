#include <iostream>
#include <stack>
using namespace std;

int n;
int a[1000004], res[1000004];
stack<int> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
   
	cin >> n;

	fill(&res[0], &res[0] + 1000004, -1);

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		while (s.size() && a[s.top()] < a[i])
		{
			res[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << res[i] << ' ';
	}
}