#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> answer;
int cnt;
bool flag, visited[10000001];

void go(string s, vector<vector<string>> tickets)
{
    if (cnt == (int)tickets.size()) flag = true;

    answer.push_back(s);

    for (int i = 0; i < tickets.size(); i++)
    {
        if (!visited[i] && tickets[i][0] == s)
        {
            visited[i] = true;
            cnt++;
            go(tickets[i][1], tickets);

            if (!flag)
            {
                answer.pop_back();
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    sort(tickets.begin(), tickets.end());

    go("ICN", tickets);

    return answer;
}