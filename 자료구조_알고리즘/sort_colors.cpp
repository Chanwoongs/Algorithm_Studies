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
			// 0�� �ü� �ֱ� ������ i�� �ѹ� �� üũ�Ѵ�. ��������
		}
		else // nums[i] == 1
		{
			i++;
		}
		
	}
}