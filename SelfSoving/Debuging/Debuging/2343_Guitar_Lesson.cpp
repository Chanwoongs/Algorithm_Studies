#include <iostream>

using namespace std;

typedef long long ll;
int n, m, lo, hi, res, a[100004], sum, mx;

bool check(int mid)
{
	if (mx > mid) return false; // 1개씩 담는 경우 mx 보다 작으면 안된다.
	int temp = mid;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		// 블루레이의 시간을 초과한다면
		if (mid - a[i] < 0) 
		{
			// 블루 레이를 썼다
			mid = temp;
			cnt++;
		}
		mid -= a[i];
	}
	// 마지막 부분에서 썼구나. 안썼다면 mid와 같음
	if (mid != temp) cnt++;
	
	return cnt <= m;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i]; // 모든 강의를 합친 최대 값
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