#include <iostream>
#include <cstdlib>
using namespace std;

typedef long long ll;

ll n, a[100004];
pair<ll, ll> res;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int left = 0, right = n - 1;
    ll sum = a[left] + a[right];
    res.first = a[left], res.second = a[right];
    while (left < right)
    {
        auto temp = a[left] + a[right];

        if (abs(sum) >= abs(temp))
        {
            sum = temp;
            res.first = a[left];
            res.second = a[right];
        }

        if (temp == 0) break;
        else if (temp > 0) right--;
        else left++;
    }
    cout << res.first << ' ' << res.second;
}