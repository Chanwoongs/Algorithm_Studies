#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
ll a, b, cnt = -1;

void go(int idx, ll res)
{
    if (res == b)
    {
        cnt = idx;
        return;
    }
    else if (res > b) return;

    go(idx + 1, res * 2);
    go(idx + 1, (res * 10) + 1);
}

int main()
{
    cin >> a >> b;

    go(1, a);

    cout << cnt << '\n';
}