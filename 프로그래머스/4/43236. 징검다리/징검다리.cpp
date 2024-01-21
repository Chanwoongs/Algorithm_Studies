#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    
    int lo = 0;
    int hi = distance;
    while (lo <= hi)
    {
        int cnt = 0, prev = 0;
        int mid = (lo + hi) / 2;
        
        for (auto& r : rocks)
        {
            if (r - prev < mid)
                cnt++;
            else prev = r;
        }
        
        if (cnt <= n)
        {
            answer = max(mid, answer);
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    
    return answer;
}