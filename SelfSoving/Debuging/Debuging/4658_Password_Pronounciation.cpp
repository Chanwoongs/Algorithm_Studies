#include <iostream>
#include <queue>
using namespace std;

string str;
char vo[] = { 'a', 'e', 'i', 'o', 'u' };

int main()
{
	while (1)
	{
		queue<bool> q;
		bool fail = true;

		cin >> str;
		if (str == "end") break;

		char lastLet = ' ';
		for (char let : str)
		{
			bool isVo = false;

			// 1번째 검사
			for (int i = 0; i < 5; i++)
			{
				if (let == vo[i])
				{
					fail = false;
					isVo = true;
				}
			}

			// 2번째 검사
			if (!q.size()) 
				q.push(isVo);
			else if (q.back() != isVo)
			{
				while (!q.empty())
				{
					q.pop();
				}
				q.push(isVo);
			}
			else if (q.back() == isVo)
				q.push(isVo);

			if (q.size() == 3)
			{
				fail = true; 
				break;
			}

			// 3번째 검사
			if (lastLet == let && (let != 'e' && let != 'o'))
			{
				fail = true;
				break;
			}
			else lastLet = let;
		}

		if (fail) cout << '<' << str << "> is not acceptable." << '\n';
		else cout << '<' << str << "> is acceptable." << '\n';
	}
}