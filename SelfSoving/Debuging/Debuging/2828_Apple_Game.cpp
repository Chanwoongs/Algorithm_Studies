#include <iostream>

using namespace std;

int n, m, cnt, basP = 1, res;

int main()
{
	cin >> n >> m;
	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		int apP;
		cin >> apP;

		bool flag = false;
		
		while (!flag)
		{
			if (apP >= basP && apP <= basP + m - 1)
			{
				flag = true;
				break;
			}

			if (apP < basP)
			{
				basP--; 
				res++;
			}
			if (apP > basP + m - 1)
			{
				basP++;
				res++;
			}
		}
	}

	cout << res << '\n';
}