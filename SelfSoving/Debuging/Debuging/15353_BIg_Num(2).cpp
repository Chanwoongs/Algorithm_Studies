#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a, b;

string stringAdd(string a, string b)
{
	int sum = 0;
	string res;


	while (a.size() || b.size() || sum)
	{
		if (a.size())
		{
			sum += a.back() - '0';
			a.pop_back();
		}
		if (b.size())
		{
			sum += b.back() - '0';
			b.pop_back();
		}
		res += (sum % 10) + '0';
		sum /= 10; // Sum == 1 or 0
	}
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	cin >> a >> b;
	cout << stringAdd(a, b) << '\n';
}