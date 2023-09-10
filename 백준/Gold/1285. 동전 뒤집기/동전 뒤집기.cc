#include <iostream>
#include <string>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int a[44];
int n, res = 99999999;
string s;

void go(int here)
{
	if (here == n + 1) // 끝까지 왔을 때
	{
		int sum = 0;
		for (int i = 1; i <= (1 << (n - 1)); i *= 2) // 1, 2, 4... 체크
		{
			int cnt = 0;
			for (int j = 1; j <= n; j++) if (a[j] & i) cnt++; // T 체크
			sum += std::min(cnt, n - cnt); // H와 T를 비교해서 작은 것을 Sum에 합함. 어짜피 뒤집으면 H나 T나 같음.
		}

		res = min(res, sum);
		return;
	}

	go(here + 1); // 안뒤집고 go
	a[here] = ~a[here]; // 비트 뒤집기
	go(here + 1); // 뒤집고 go 
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		int value = 1;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == 'T') a[i] |= value;
			value *= 2;
		}
	}
	go(1);
	cout << res << '\n';
}