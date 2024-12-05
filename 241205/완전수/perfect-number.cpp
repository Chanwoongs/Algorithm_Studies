#include <iostream>
using namespace std;

int main() {
    int st, ed, res = 0;

    cin >> st >> ed;

    for (int i = st; i <= ed; i++)
    {
        int sum = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }

        if (sum == i)
        {
            res++;
        }
    }

    cout << res << '\n';

    return 0;
}