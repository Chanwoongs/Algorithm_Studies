#include <iostream>
#include <string>

using namespace std;

string str;

int main()
{
	cin >> str;

	bool flag = false;

	int idx = 0;
	while (idx < str.size())
	{
		if (str[idx] == 'p' || str[idx] == 'k' || str[idx] == 'c')
		{
			flag = true;
		}
		else
		{
			flag = false;
			break;
		}

		if (str[idx] == 'p' && str[idx + 1] == 'i')
		{
			idx += 2;
		}
		else if (str[idx] == 'k' && str[idx + 1] == 'a')
		{
			idx += 2;
		}
		else if (str[idx] == 'c' && str[idx + 1] == 'h' && str[idx + 2] == 'u')
		{
			idx += 3;
		}
		else
		{
			flag = false;
			break;
		}
	}
	if (flag) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}