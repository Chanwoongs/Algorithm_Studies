#include <iostream>
using namespace std;

int main() {
    int n, cnt = 1;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i)
                cout << "  ";
            else cout << cnt++ << ' ';
        }
        cout << '\n';
    }
    return 0;
}