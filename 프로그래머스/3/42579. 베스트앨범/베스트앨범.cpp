#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> gen;
map<string, map<int, int>> mus;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for (int i = 0; i < genres.size(); i++)
    {
        gen[genres[i]] += plays[i];
        mus[genres[i]][i] = plays[i];
    }
    
    while (gen.size() > 0)
    {
        string name;
        int mx = -1;
        
        for (auto& g : gen)
        {
            if (mx < g.second)
            {
                mx = g.second;
                name = g.first;
            }
        }
        
        for (int i = 0; i < 2; i++)
        {
            int num = -1;
            int cnt = -1;
            
            for (auto m : mus[name])
            {
                if (cnt < m.second)
                {
                    cnt = m.second;
                    num = m.first;
                }
            }
            if (num == -1) break;
            
            answer.push_back(num);
            mus[name].erase(num);
        }
        
        gen.erase(name);
    }
    
    return answer;
}