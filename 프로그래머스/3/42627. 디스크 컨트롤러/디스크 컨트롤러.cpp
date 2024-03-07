#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(vector<int>& a, vector<int>& b)
    {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    sort(jobs.begin(), jobs.end());
    
    int cnt = 0;
    int _time = 0;
    
    while (cnt < jobs.size() || pq.size())
    {
        // 작업이 남았고, 현재 시간보다 요청 시간이 작거나 같아야 작업에 들어감
        if (cnt < jobs.size() && jobs[cnt][0] <= _time)
        {
            pq.push(jobs[cnt]);
            cnt++;
            continue;
        }
        
        // 할 작업이 있다면 하고 시간을 늘려준다.
        if (pq.size())
        {
            _time += pq.top()[1]; // 작업 시간
            answer += _time - pq.top()[0]; // 요청부터 종료까지 걸린 시간
            pq.pop(); // 작업 완료
        }
        else
        {
            // 할 작업이 없다면 다음 제일 빠른 요청으로 다시 시작
            _time = jobs[cnt][0];
        }
    }
    
    return answer / jobs.size();
}