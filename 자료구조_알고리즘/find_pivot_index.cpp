// �ǹ� ���� ���� ������ ���� ������ ���ϴ� �˰���
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