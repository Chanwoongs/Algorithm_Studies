#include <iostream>
#include <algorithm>

using namespace std;

int n, k, res;
int a[11];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++)
    {
        while (k - a[i] >= 0)
        {
            res++;
            k -= a[i];
        }
    }
    cout << res << '\n';
}