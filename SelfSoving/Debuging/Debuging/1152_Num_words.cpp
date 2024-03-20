#include <iostream>
#include <string>

using namespace std;

string s;
int res;

int main()
{
    getline(cin, s);

    while (1)
    {
        auto it = s.find(" ");
        if (it != string::npos)
        {
            res++;
            s = s.substr(it + 1, s.size() - it);
        }
        else break;
    }

    cout << res + 1 << '\n';
}