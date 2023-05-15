#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, num;
    int scores[1024];
    int max = -1;
    float sum = 0;
    
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        scores[i] = num;
        
        if (max <= num) max = num;
    }
    
    for (int i = 0; i < n; i++)
    {
        sum += (float)scores[i] / (float)max * 100;
    }
    
    cout << sum / n;
    
    return 0;
}