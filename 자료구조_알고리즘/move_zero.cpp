void moveZeroes(int[] num)
{
	int wIdx = 0;
	for (int idx = 0; idx < nums.length; idx++)
	{
		if (nums[idx] != 0)
		{
			swap(nums[wIdx], nums[idx]);
			wIdx++;
		}
	}
	for (; wIdx < num.length; wIdx) // ������ �ڿ� ���� 0���� ���� ä���
	{
		nums[wIdx] = 0;
	}
}