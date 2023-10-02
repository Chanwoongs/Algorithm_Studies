#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> mp;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    int j = 0;
    for (int i = players.size() - 1; i >= 0; i--)
    {
        mp[players[j]] = i;
        j++;
    }
    for (auto c : callings)
    {
        mp[c] += 101;
    }
    answer.resize(players.size());
    for (auto& m : mp)
    {
        if (m.second < 100) m.second -= 1;
        else if (m.second > 100)
        {
            while (m.second > 100)
            {
                m.second -= 100;
            }
        }

        answer[m.second] = m.first;
    }

    return answer;
}