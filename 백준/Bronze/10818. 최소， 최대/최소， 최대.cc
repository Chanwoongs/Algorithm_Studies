#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int nums[1000001] = {0,};
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    
    sort(nums, nums + n);
    
    cout << nums[0] << ' ' << nums[n - 1];
}