#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, minDp[3], maxDp[3], input[3];
int maxRes, minRes;

int main()
{
    cin >> n;
    
    cin >> maxDp[0] >> maxDp[1] >> maxDp[2];
    memcpy(minDp, maxDp, sizeof(maxDp));
    
    for (int i = 1; i < n; i++)
    {
        cin >> input[0] >> input[1] >> input[2];
        
        int a = maxDp[0], b = maxDp[1], c = maxDp[2];
        
        maxDp[0] = max(a, b) + input[0];
        maxDp[1] = max(a, max(b, c)) + input[1];
        maxDp[2] = max(b, c) + input[2];
        
        a = minDp[0], b = minDp[1], c = minDp[2];
        
        minDp[0] = min(a, b) + input[0];
        minDp[1] = min(a, min(b, c)) + input[1];
        minDp[2] = min(b, c) + input[2];
    }
    maxRes = max(maxDp[0], max(maxDp[1], maxDp[2]));
    minRes = min(minDp[0], min(minDp[1], minDp[2]));
    
    cout << maxRes << ' ' << minRes << '\n';
}