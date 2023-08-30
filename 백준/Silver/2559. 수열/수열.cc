#include <iostream>
#include <algorithm>
using namespace std;

int psum[100004];
int n;
int k;
int temp;
int res = -10000004;

int main()
{    
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        psum[i] = psum[i - 1] + temp;
    }
    for (int i = k; i <= n; i++)
    {
        res = max(res, psum[i] - psum[i - k]);
    }
    cout << res << '\n';
}