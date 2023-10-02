#include <iostream>
#include <map>

using namespace std;

int a[1001], b[1001], res, want, n, m;
int psumA[2002], psumB[2002]; // �ڿ� �迭�� ���ٿ� ���� �ڷᱸ�� -> ���� �ڷᱸ��
map<int, int> aCnt, bCnt;

void make(int n, int psum[], map<int, int>& mp)
{
	for (int interval = 1; interval <= n; interval++) // 1��¥��, 2��¥��.... ������ ũ��
	{
		for (int start = interval; start <= n + interval - 1; start++)
		{
			int sum = psum[start] - psum[start - interval]; // ���� - ����
			mp[sum]++;
			if (interval == n) break;
		}
	}
}

int main()
{
	cin >> want >> n >> m;

	// A ������ �����
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		psumA[i] = psumA[i - 1] + a[i];
	}
	for (int i = n + 1; i <= 2 * n; i++)
	{
		psumA[i] = psumA[i - 1] + a[i - n];
	}
	// B ������ �����
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
		psumB[i] = psumB[i - 1] + b[i];
	}
	for (int i = m + 1; i <= 2 * m; i++)
	{
		psumB[i] = psumB[i - 1] + b[i - m];
	}

	// ��� ����� �� �����
	make(n, psumA, aCnt);
	make(m, psumB, bCnt);

	res = aCnt[want] + bCnt[want]; // ������ ���ڿ��� �ذ� ������ ���
	for (int i = 1; i < want; i++)
	{
		res += (aCnt[i] * bCnt[want - i]); // ���� ���Ͽ� want�� �Ǵ� ���
	}
	cout << res << '\n';
}