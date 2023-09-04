#include <iostream>
using namespace std;

int cnt[100];
int a, b, c;
int price;

void setTimeline()
{
    for (int i = 0; i < 3; i++)
    {
        int start, end;
 
        cin >> start, end;
        
        for (int j = start; j < end; j++)
        {
            cnt[j]++;
        }
    }
}

int main()
{
    cin >> a >> b >> c;
    setTimeline();
    
    for (int i = 0; i < 100; i++)
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
