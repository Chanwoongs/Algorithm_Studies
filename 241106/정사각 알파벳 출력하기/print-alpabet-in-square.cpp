#include <iostream>
using namespace std;

int main() {
    int a = (int)'A';
    int n;
    cin >> n;

    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << (char)a++;
        }
        cout << '\n';
    }
    return 0;
}