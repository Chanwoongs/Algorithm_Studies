#include <iostream>
using namespace std;

int cnt[104];
int a, b, c;
int price;
int startT, endT;

int main()
{
    cin >> a >> b >> c;
    for (int i = 0; i < 3; i++)
    {
        cin >> startT >> endT;
        
        for (int j = startT; j < endT; j++)
        {
            cnt[j]++;
        }
    }
    
    for (int i = 1; i < 100; i++)
    {
        if (cnt[i])
        {
            if (cnt[i] == 1) price += a;
            else if (cnt[i] == 2) price += 2 * b;
            else if (cnt[i] == 3) price += 3 * c;
        }
    }
    
    cout << price << '\n';
}