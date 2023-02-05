#include <iostream>

using namespace std;

int findPeak(int arr[][10000], int row, int col);

int main()
{
	int arr[][10000] = {
		{10, 8, 10, 10},
		{14, 13, 12, 11},
		{15, 9, 11, 21},
		{16, 17, 19, 20}
	};

	cout << findPeak(arr, 4, 4) << endl;
}

int findPeak(int arr[][10000], int row, int col)
{
	int colNum = col / 2;

	while (colNum != 0)
	{
		int max = -1;
		for (int i = 0; i < col; i++)
		{
			if (arr[row][i] > max)
			{
				max = arr[row][i];
			}
		}

		if (arr[row][colNum - 1] > max)
		{
			findPeak(arr, row , colNum - 1);
		}
		else if (arr[row][colNum + 1] > max)
		{
			findPeak(arr, row, colNum + 1);
		}
	}

	return arr[row][colNum];
}