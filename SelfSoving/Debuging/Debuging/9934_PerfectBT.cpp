#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int k;
int a[10000004];
vector<int> res[14];

void go(int s, int e, int level)
{
	if (s > e) return; // 구간을 쪼개서 하는 코드는 무조건 넣어야한다.
	if (s == e)
	{
		res[level].push_back(a[s]);
		return;
	}
	int mid = (s + e) / 2;
	res[level].push_back(a[mid]);
	go(s, mid - 1, level + 1);
	go(mid + 1, e, level + 1);

	return;
}


int main()
{
	cin >> k;
	
	int end = (int)pow(2, k) - 1;

	for (int i = 0; i < end; i++)
	{
		cin >> a[i];
	}
	go(0, end, 1);

	for (int i = 1; i <= k; i++)
	{
		for (int ele : res[i])
		{
			cout << ele << ' ';
		}
		cout << '\n';
	}
}