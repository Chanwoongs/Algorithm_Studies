#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int num;
    cin >> n;
    
    int max = -1000000;
    int min = 1000000;
    
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        if (max < num) max = num;
        if (min > num) min = num;
    }
    
    cout << min << ' ' << max;
}