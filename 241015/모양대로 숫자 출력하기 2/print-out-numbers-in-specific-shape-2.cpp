#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << cnt * 2 << ' ';
            
            cnt++;
            if (cnt == 5)
            {
                cnt = 1;
            }
        }
        cout << '\n';
    }


    return 0;
}