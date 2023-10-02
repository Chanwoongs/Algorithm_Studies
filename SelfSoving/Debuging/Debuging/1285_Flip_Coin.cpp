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
	if (here == n + 1) // ������ ���� ��
	{
		int sum = 0;
		for (int i = 1; i <= (1 << (n - 1)); i *= 2) // 1, 2, 4... üũ
		{
			int cnt = 0;
			for (int j = 1; j <= n; j++) if (a[j] & i) cnt++; // T üũ
			sum += std::min(cnt, n - cnt); // H�� T�� ���ؼ� ���� ���� Sum�� ����. ��¥�� �������� H�� T�� ����.
		}

		res = min(res, sum);
		return;
	}

	go(here + 1); // �ȵ����� go
	a[here] = ~a[here]; // ��Ʈ ������
	go(here + 1); // ������ go 
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