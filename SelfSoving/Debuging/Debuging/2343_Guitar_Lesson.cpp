#include <iostream>

using namespace std;

typedef long long ll;
int n, m, lo, hi, res, a[100004], sum, mx;

bool check(int mid)
{
	if (mx > mid) return false; // 1���� ��� ��� mx ���� ������ �ȵȴ�.
	int temp = mid;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		// ��緹���� �ð��� �ʰ��Ѵٸ�
		if (mid - a[i] < 0) 
		{
			// ��� ���̸� ���
			mid = temp;
			cnt++;
		}
		mid -= a[i];
	}
	// ������ �κп��� �豸��. �Ƚ�ٸ� mid�� ����
	if (mid != temp) cnt++;
	
	return cnt <= m;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i]; // ��� ���Ǹ� ��ģ �ִ� ��
		mx = std::max(mx, a[i]);
	}

	lo = 0;
	hi = sum;

	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (check(mid))
		{
			hi = mid - 1;
			res = mid;
		}
		else lo = mid + 1;
	}

	cout << res << '\n';
}