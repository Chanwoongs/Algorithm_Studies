#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, t;
vector<int> partyAdj[54];
vector<int> humanAdj[54];
bool truth[54];
bool checkParty[54];

int main() {
    cin >> n >> m;

    // 진실을 아는 사람 초기화
    cin >> t;
    queue<int> q;

    for (int i = 0; i < t; i++) 
    {
        int temp;
        cin >> temp;
        truth[temp] = true;
        q.push(temp);
    }

    // 파티 정보 입력
    for (int i = 1; i <= m; i++) 
    {
        int p;
        cin >> p;
        for (int j = 0; j < p; j++) 
        {
            int temp;
            cin >> temp;
            partyAdj[i].push_back(temp);
            humanAdj[temp].push_back(i);
        }
    }

    // 진실을 알게 되는 사람 및 파티 업데이트
    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();

        for (int par : humanAdj[current]) 
        {
            if (checkParty[par]) continue;

            checkParty[par] = true;
            for (int member : partyAdj[par]) 
            {
                if (!truth[member]) 
                {
                    truth[member] = true;
                    q.push(member);
                }
            }
        }
    }

    // 결과 출력
    int res = 0;
    for (int i = 1; i <= m; i++) 
    {
        if (!checkParty[i]) res++;
    }
    cout << res << '\n';

    return 0;
}