#include <iostream>

using namespace std;

int cnt;

int main()
{
    cin >> cnt;
    
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << '*';
        }
        for (int j = 1; j <= 2 * cnt - 2 * i; j++)
        {
            cout << ' ';
        }
        for (int j = 1; j <= i; j++)
        {
            cout << '*';
        }
        
        cout << '\n';
    }
    
    for (int i = 1; i <= cnt - 1; i++)
    {
        for (int j = 1; j <= cnt - i; j++)
        {
            cout << '*';
        }
        for (int j = 1; j <= 2 * i; j++)
        {
            cout << ' ';
        }
        for (int j = 1; j <= cnt - i; j++)
        {
            cout << '*';
        }
        
        cout << '\n';
    }
}