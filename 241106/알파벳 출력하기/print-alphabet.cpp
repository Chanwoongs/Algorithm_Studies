#include <iostream>
using namespace std;

int main() {
    int a = (int)'A';
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << (char)a++;
        }
        cout << '\n';
    }
    return 0;
}