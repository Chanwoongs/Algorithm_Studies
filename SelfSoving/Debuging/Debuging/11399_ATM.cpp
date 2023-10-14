#include <iostream>
#include <algorithm>
using namespace std;

int n, res;
int a[1004];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++)
    {
        res += a[i] * (n - i);
    }

    cout << res << '\n';
}