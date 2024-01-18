#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

unordered_set<int> dp[8];

int solution(int N, int number) {
    int answer = -1;
    
    // 큰문제 -> 여러개의 작은 문제들로 쪼개어 접근
    
    // 1 2  3   4    5     6      7       8
    // 5 55 555 5555 55555 555555 5555555 55555555
    
    // set[0] = {5}
    // set[1] = {55, 5-5, 5+5,...}
    
    int num = 0;
    for (int i = 0; i < 8; i++)
    {
        num = 10 * num + N;
        dp[i].insert(num);
    }
    
    for (int i = 1; i < 8; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (auto op1 : dp[j])
            {
                for (auto op2 : dp[i - j - 1])
                {
                    dp[i].insert(op1 + op2);
                    dp[i].insert(op1 - op2);
                    dp[i].insert(op1 * op2);
                    if (op2 != 0)
                        dp[i].insert(op1 / op2);
                }
            }
        }
    }
    
    for (int i = 0; i < 8; i++)
    {
        if (dp[i].find(number) != dp[i].end())
        {
            answer = i + 1;
            break;
        }
    }
    
    
    return answer;
}