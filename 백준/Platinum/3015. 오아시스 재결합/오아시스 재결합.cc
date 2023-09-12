#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;
ll n, res, temp;
stack<pair<ll, ll>> s; // temp 와 cnt 둘다 담기

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		int cnt = 1;
		while (s.size() && s.top().first <= temp)
		{
			res += s.top().second;
			// 같은 키
			if (s.top().first == temp)
			{
				cnt = s.top().second + 1;
			}
			else cnt = 1;
			s.pop();
		}
		if (s.size()) res++;
		s.push({ temp, cnt });
		
	}
	cout << res << '\n';
}