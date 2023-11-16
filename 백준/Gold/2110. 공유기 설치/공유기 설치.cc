#include <iostream>
#include <algorithm>

using namespace std;

int n, c, res;
vector<int> pos;

bool check(int mid)
{
    int cnt = 1;
    int prev = pos[0];
    
    for (int i = 1; i < n; i++)
    {
        if (pos[i] - prev >= mid) // 주어진 거리만큼 갈 수 있다면
        {
            cnt++;
            prev = pos[i];
        }
    }
    if (cnt >= c) return true;
    else return false;
}

int main()
{
    cin >> n >> c;
    pos.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> pos[i];
    }
    
    sort(pos.begin(), pos.end());
    
    int lo = 1; // 최소 간격
    int hi = pos[n - 1] - pos[0]; // 최대 간격
    
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        
        if (check(mid))
        {
            lo = mid + 1;
            res = mid;
        }
        else hi = mid - 1;
    }
    cout << res << '\n';
}