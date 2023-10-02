#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
struct game {
    int x, y, c;
};
vector<game> a;
int n, dp[1001][1001];
bool visited[101];

int rpg(int STR, int INT)
{
    int& res = dp[STR][INT];
    if (~res) return res;

    res = 0;
    int pnt = 0;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        if (a[i].x <= STR || a[i].y <= INT) // ±ý ¼ö ÀÖ´Ù.
        {
            res++;
            if (!visited[i])
            {
                visited[i] = true;
                pnt += a[i].c;
                v.push_back(i);
            }
        }
    }
    for (int p = 0; p <= pnt; p++)
    {
        int nextSTR = min(1000, STR + p);
        int nextINT = min(1000, INT + pnt - p);
        res = std::max(res, rpg(nextSTR, nextINT));
    }

    for (int here : v)
    {
        visited[here] = 0;
    }

    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int STR, INT, PNT;
        cin >> STR >> INT >> PNT;
        a.push_back({ STR, INT, PNT });
    }
    memset(dp, -1, sizeof(dp));
    cout << rpg(1, 1) << '\n';

}