#include <iostream>
using namespace std;

int main() {   
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b, res = 1;
        cin >> a >> b;

        for (int i = a; i <= b; i++)
        {
            res *= i;
        }

        cout << res << '\n';
    }

    return 0;
}