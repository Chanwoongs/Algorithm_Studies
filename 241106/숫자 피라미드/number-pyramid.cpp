#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < i + 1 + i + 1; j++)
        {
            cout << i + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}