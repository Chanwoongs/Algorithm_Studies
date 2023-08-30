#include <iostream>
#include <string>

using namespace std;

string input, pal;
int cnt[104], flag;
char mid;

int main()
{
    cin >> input;
    for (char let : input) cnt[let]++;
    
    for (int i = 'Z'; i >= 'A'; i--) // 오름차순 때문에 Z부터 시작
    {
        if (cnt[i])
        {
            if (cnt[i] & 1)
            {
                mid = char(i);
                flag++;
                cnt[i]--; // 중앙에 넣을 것을 뺐기 때문에 -1
            }
            if (flag == 2) break; // 홀수가 2개 이상
            for (int j = 0; j < cnt[i]; j += 2)
            {
                pal = char(i) + pal;
                pal += char(i);
            }
        }
    }
    if (mid) pal.insert(pal.begin() + pal.size() / 2, mid);
    if (flag == 2) cout << "I'm Sorry Hansoo\n";
    else cout << pal << '\n';
}