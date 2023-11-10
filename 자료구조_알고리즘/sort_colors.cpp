void sortColors(int[] nums)
{
	int idx0 = 0;
	int idx2 = nums.length - 1;
	int i = 0;

	while (i <= idx 2)
	{
		if (nums[i] == 0)
		{
			swap(nums[i], nums[idx0]);
			idx++;
			i++;
		}
		else if (nums[i] == 2)
		{
			swap(nums[i], nums[idx2]);
			idx2--; 
			// 0이 올수 있기 때문에 i를 한번 더 체크한다. 증감없음
		}
		else // nums[i] == 1
		{
			i++;
		}
		
	}
}