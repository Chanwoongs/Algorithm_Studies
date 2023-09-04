// 아직 정답 수정 전 질문중
#include <iostream>

using namespace std;

int cnt;
int trg;
int mat[100004];
int res;
int num;

int main()
{
    cin >> cnt >> trg;

    for (int i = 1; i <= cnt; i++)
    {
        int temp;

        cin >> temp; 
        mat[temp]++;
    }
    for (int i = 1; i <= 100000; i++)
    {
        if (mat[i] > 0) num = i;

        if (num >= trg) return 0;

        int diff = trg - num;

        if (diff > 100000 || diff < 1) continue;

        if (mat[diff] > 0)
        {
            if (num == diff && mat[num] < 2) continue;
            if (diff == trg) continue;

            mat[diff]--;
            mat[num]--;

            res += 1;
        }
    }
    cout << res << '\n';
}