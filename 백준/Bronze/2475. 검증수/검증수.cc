#include <iostream>

using namespace std;

int num, res;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        
        res += num * num % 10;
        res %= 10;
    }
    cout << res << '\n';
}