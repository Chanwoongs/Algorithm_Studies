#include <iostream>
#include <string>
#include <map>
using namespace std;

string s;
map<string, int> a;
int cnt;

int main()
{
	while (getline(cin, s))
	{
		a[s]++;
		cnt++;
	}

	cout.precision(5);

	// 나눠서 출력
	for (auto ele : a)
	{
		cout << ele.first << ' ' << ele.second / cnt;
	}
}