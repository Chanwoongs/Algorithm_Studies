#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n;

    for (int i = n; i > 0; i--)
    {
        for (int k = 0; k < i; k++)
        {
            for (int j = 0; j < i; j++)
            {
                cout << "*";
            }   
            cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}