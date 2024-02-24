#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t,n,mx;
	long long res;
    cin >> t;
    while (t--)
    {
		cin >> n;
		int arr[1000000] = {0,};
        mx = 0;
        res = 0;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = n-1; i >= 0; i--) // 거꾸로 탐색하면서
        {
            mx = max(mx, arr[i]); // 최대값 갱신
            res += mx - arr[i]; // 차이값을 더해준다
        }
        cout << res << "\n";
    }
}