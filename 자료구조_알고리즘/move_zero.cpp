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
	for (; wIdx < num.length; wIdx) // 나머지 뒤에 숫자 0으로 전부 채우기
	{
		nums[wIdx] = 0;
	}
}