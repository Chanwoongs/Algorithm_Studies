#include <iostream>

using namespace std;
int a, b, n;
int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        cout << a + b << '\n';
    }
}