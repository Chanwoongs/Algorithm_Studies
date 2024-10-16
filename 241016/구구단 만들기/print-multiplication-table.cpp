#include <iostream>
using namespace std;

int main() {
    int a, b;

    cin >> a >> b;

    if (b % 2 != 0)
    {
        b -= 1;
    }

    for (int i = 0; i < 9; i ++)
    {
        for (int j = b; j >= a; j -= 2)
        {
            cout << j << " * " << i + 1 << " = " << j * (i + 1) << ' ';

            if (j != a)
            {
                cout << "/ ";
            }
        }
        cout << '\n';
    }

    return 0;
}