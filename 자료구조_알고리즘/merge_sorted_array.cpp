void(int[] nums1, int m, int[] num2, int n)
{
	int num1Idx = m - 1;
	int num2Idx = n - 1;
	int wIdx = num1.length - 1;

	if (num2Idx < 0)
	{
		return;
	}

	while (0 <= num1Idx && 0 <= num2Idx)
	{
		int num1 = num1[num1Idx];
		int num2 = nums2[num2Idx];
		
		if (num2 <= num1)
		{
			int num = num1;
			nums1[wIdx] = num;
			num1Idx--;
			wIdx--;
		}
		else
		{
			int num = num2;
			nums1[wIdx] = num;
			num2Idx--;
			wIdx--;
		}
	}

	//memory copy
	while (0 <= num2Idx)
	{
		num1[wIdx] = nums2[num2Idx];
		nums2Idx--;
		wIdx--;
	}

}