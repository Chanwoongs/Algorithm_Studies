#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for (auto ele : scoville)
    {
        pq.push(ele);
    }
    
    while (pq.size() >= 2 && pq.top() < K)
    {
        int lo = pq.top(); pq.pop();
        int snd = pq.top(); pq.pop();
        int mix = lo + (snd * 2);
        
        pq.push(mix);
        answer++;
    }
    if (pq.top() < K) answer = -1;
    
    return answer;
}