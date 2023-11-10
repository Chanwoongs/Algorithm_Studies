#include <iostream>
#include <vector>

int findDuplicate(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        auto idx = nums[i];

        if (nums[idx] < 0) return idx;

        nums[idx] *= -1;
    }
    return 0;
}

int main()
{

}