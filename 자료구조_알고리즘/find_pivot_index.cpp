// 피벗 기준 왼쪽 오른쪽 합이 같은지 구하는 알고리즘
// Sliding
int pivotIndex(int[] nums)
{
	int sum = sum(nums);
	int leftSum = 0;
	int rightSum = sum;

	int pastPivotNum;
	for (int idx = 0; idx < nums.length; idx++)
	{
		int num = nums[idx];
		rightSum = rightSum - sum;
		leftSum = leftSum + pastPivotNum;

		if (leftSum == rightSum)
		{
			return idx;
		}
		pastPivotNum = num;
	}
	return -1;
}