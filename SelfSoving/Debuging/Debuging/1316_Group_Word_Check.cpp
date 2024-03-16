#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <set>

using namespace std;

string s[104];
int n, res;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	for (int i = 0; i < n; i++)
	{
		stack<char> st;
		set<char> checked;
		auto cur = s[i];
		bool isGroupWord = true;

		for (int j = 0; j < cur.size(); j++)
		{
			if (!st.empty() && st.top() != cur[j])
			{
				if (checked.find(cur[j]) != checked.end())
				{
					isGroupWord = false;
					break;
				}
				checked.insert(st.top());
				st.pop();
			}
			st.push(cur[j]);
		}

		if (isGroupWord) res++;
	}

	cout << res << '\n';
}