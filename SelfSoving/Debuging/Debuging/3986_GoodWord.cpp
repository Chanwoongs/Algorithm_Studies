#include <iostream>
#include <stack>

using namespace std;

int cnt, res;

int main()
{
    cin >> cnt;

    for (int i = 0; i < cnt; i++)
    {
        stack<char> s;
        string str;

        cin >> str;

        for (char let : str)
        {
            if (s.empty())
            {
                s.push(let);
                continue;
            }
            if (s.top() == let)
            {
                s.pop();
                continue;
            }
            s.push(let);
        }
        if (s.empty()) res += 1;
    }

    cout << res << '\n';
}