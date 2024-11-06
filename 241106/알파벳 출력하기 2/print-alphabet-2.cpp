#include <iostream>
using namespace std;

int main() {
    int a = (int)'A';
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                cout << "  ";
            }
            else
            {
                cout << (char)a++ << ' ';
            }
            if (a == (int)'Z' + 1) a = (int)'A';
        }
        cout << '\n';
    }

    return 0;
}