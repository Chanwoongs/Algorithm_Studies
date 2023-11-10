int findPeakElem(int nums[])
{
	int left = 0;
	int right = nums.length - 1;
	
	if (nums.size() <= 1)
	{
		return 0;
	}

	while (left < right)
	{
		int pivot = (left + right) / 2;
		int num = nums[pivot];
		int nextNum = nums[pivot + 1];

		if (num < nextNum) // 올라가는 경사
		{
			left = pivot + 1;
		}
		else
		{
			right = pivot; // 내려가는 경사
		}
	}
	return left; // or return right
}