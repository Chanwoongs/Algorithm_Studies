#include <iostream>
#include <set>

using namespace std;

int T;

int main()
{
    cin >> T;
    while (T--)
    {
        int t;
        cin >> t;

        multiset<int> ms;

        for (int k = 0; k < t; k++)
        {
            char a;
            int num;
            cin >> a >> num;

            if (a == 'D' && !ms.empty())
            {
                if (num == 1)
                {
                    ms.erase(--ms.end());
                }
                else
                {
                    ms.erase(ms.begin());
                }
            }
            else
            {
                ms.insert(num);
            }
        }

        if (ms.empty()) cout << "EMPTY" << '\n';
        else
        {
            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }
}
