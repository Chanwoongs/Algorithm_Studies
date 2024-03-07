#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int, int> pii;

int main() {
    vector<vector<pii>> v(5);

    for (int i = 0; i < 5; i++)
    {
        v[i].push_back({ i + 1, i + 2 });
    }
    for (int i = 0; i < 5; i++)
    {
        for (auto& ele : v[i])
        {
            cout << ele.first << ' ' << ele.second << '\n';
        }
    }
    
    auto a = v[0][0];
    cout << a.first << '\n';
    v[0][0].first;
}