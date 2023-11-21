#include <iostream>
#include <algorithm>
using namespace std;

int t, n, res = 0;

int main()
{
    cin >> t;
    
    while (t--)
    {
        cin >> n;
        vector<int> v;
        res = 0;
        
        for(int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        
        for (int i = 0; i < n - 2; i++)
        {
            res = max(v[i + 2] - v[i], res);
        }
        cout << res << '\n';
    }
}

