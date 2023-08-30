#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt;
vector<int> v;

int main()
{
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    for (int ele : v)
    {
        cout << ele << '\n';
    }
}