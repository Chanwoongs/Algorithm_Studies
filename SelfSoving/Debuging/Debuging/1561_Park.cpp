#include <iostream>

using namespace std;

#define MAX_N 60000000004
#define MAX_M 10004

typedef long long ll;
ll n, m, a[MAX_M], lo, hi = MAX_N, res, mid, temp;

bool check(ll mid)
{
	temp = m; // ó���� �� �¿��.

	// �ڿ� ��� �ð��� �� �¿��.
	for (int i = 0; i < m; i++)
	{
		temp += mid / a[i];
	} 
	return temp >= n;
}

int main()
{
	cin >> n >> m;
	for (ll i = 0; i < m; i++)
	{
		cin >> a[i];
	}

	// ���� �ⱸ�� ����ϴ�
	if (n <= m)
	{
		cout << n << '\n';
		return 0;
	}
	
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (check(mid))
		{
			res = mid; // n�� �� �¿� �� �ִ� �ּ� �ð�
			hi = mid - 1;
		}
		else lo = mid + 1;
	}

	// �ּ� �ð� 1�� ���� ź ������ ��
	temp = m;
	for (ll i = 0; i < m; i++)
	{
		temp += ((res - 1) / a[i]);
	}

	// �ּ� �ð��� ���������� ž���Ͽ� ������ ������ ���̱ⱸ�� ���Ѵ�
	for (ll i = 0; i < m; i++)
	{
		if (res % a[i] == 0) temp++; // �Ѹ� �¿��
		if (temp == n) // �� �¿���
		{
			cout << i + 1 << '\n';
			return 0;
		}
	}
}