#include <string>
#include <vector>

using namespace std;
int res = 0;

void go (int idx, int sum, vector<int> v, int t)
{
    if (idx == v.size())
    {
        if (sum == t) 
        {
            res++;   
        }
        return;
    }
    go (idx + 1, sum + v[idx], v, t);
    go (idx + 1, sum - v[idx], v, t);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    go(0, 0, numbers, target);
    answer = res;
    
    return answer;
}