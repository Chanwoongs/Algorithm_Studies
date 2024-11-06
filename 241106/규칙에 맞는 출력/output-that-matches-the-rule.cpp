#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n; i > 0; i--)
    {
        for (int j = i; j <= n; j++)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }


    return 0;
}