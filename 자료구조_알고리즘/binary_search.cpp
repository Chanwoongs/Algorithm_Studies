#include <iostream>

int binarySearch(int[] nums, int target)
{
	int left = 0;
	int right = nums.length - 1;

	while (left <= right)
	{
		int pivot = (left + right) / 2;
		if (nums[pivot] == target)
		{
			return pivot;
		}
		else if (nums[pivot] < target)
		{
			left = pivot + 1;
		}
		else // target < pivot num
		{
			right = pivot - 1;
		}
	}
}