#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int lo, hi, mx;
int a[100000];

bool check(int mid)
{
    int cnt = 1; // 인출한 횟수, 한번은 무조건 인출
    int temp = mid;

    for (int i = 0; i < n; i++)
    {
        // 돈이 모자라면 다시 K원을 꺼낸다.
        if (mid - a[i] < 0)
        {
            mid = temp;
            cnt++;
        }
        mid -= a[i];
    }

    return cnt <= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    lo = mx;
    hi = 1000000004;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        if (check(mid))
        {
            hi = mid - 1;
            k = mid;
        }
        else lo = mid + 1;
    }

    cout << k << '\n';
}