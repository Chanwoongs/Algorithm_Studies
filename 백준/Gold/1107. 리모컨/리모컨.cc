#include <iostream>
#include <unordered_set>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n, m, temp, res;
unordered_set<int> brok;

int pressBtn(int x)
{
    int cnt = 0;

    if (x < 10)
    {
        if (brok.find(x) != brok.end())
            return 0;
        else return 1;
    }

    while (x > 0)
    {
        if (brok.find(x % 10) != brok.end())
            return 0;
        else
        {
            x /= 10;
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        brok.insert(temp);
    }

    res = abs(n - 100);

    for (int i = 0; i <= 1000000; i++)
    {
        int pressCnt = pressBtn(i);

        if (pressCnt > 0)
        {
            int totalCnt = pressCnt + abs(n - i);
            res = min(res, totalCnt);
        }
    }

    cout << res << '\n';
}