#include <iostream>
using namespace std;

int main() {
    int n, cnt = 1;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                cout << "  ";
            }
            else cout << cnt++ << ' ';

            if (cnt == 10) cnt = 1;
        }
        cout << '\n';
    }

    return 0;
}