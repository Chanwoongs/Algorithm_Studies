#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll maxPassCnt(ll inTime, vector<int> times)
{
    ll sum = 0;
    
    for (auto t : times)
    {
        sum += inTime / (ll)t;
    }
    
    return sum;
}

ll solution(int n, vector<int> times) {
    ll answer = 0;

    ll max = 10e10;
    
    ll lo = 0;
    ll hi = *max_element(times.begin(), times.end()) * (ll)n;
    
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (maxPassCnt(mid, times) < n)
        {
            lo = mid + 1;
        }
        else
        {
            answer = mid;
            hi = mid - 1;
        }
    }
    
    return answer;
}
