#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <time.h>

#define SIZE 10

using namespace std;

void setData(vector<int>&, vector<int>&, vector<int>&, vector<int>&);
void printData(vector<int>, vector<int>, vector<int>);
double insertionSort(vector<int>&);
void mergeSort(int, int, vector<int>&, vector<int>&);
void mergeSortPartition(int, int, vector<int>&, vector<int>&);
void quickSort(int, int, vector<int>&);
int quickSortPartition(int, int, vector<int>&);

int main()
{
	vector<int> orderedData;
	vector<int> reversedData;
	vector<int> disorderedData;
	vector<int> tempData;

	clock_t start, end;

	orderedData.reserve(SIZE);
	reversedData.reserve(SIZE);
	disorderedData.reserve(SIZE);
	tempData.reserve(SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		orderedData.push_back(0);
		reversedData.push_back(0);
		disorderedData.push_back(0);
		tempData.push_back(0);
	}

	setData(orderedData, reversedData, disorderedData, tempData);

	printData(orderedData, reversedData, disorderedData);
	double insertionOrderedTime = insertionSort(orderedData);
	double insertionReversedTime = insertionSort(reversedData);
	double insertionDisorderedTime = insertionSort(disorderedData);

	cout << "Insertion Sort Time Check" << endl;
	cout << "Ordered Data : " << insertionOrderedTime / CLOCKS_PER_SEC << endl;
	cout << "Reversed Data Data : " << insertionReversedTime / CLOCKS_PER_SEC << endl;
	cout << "Disordered Data : " << insertionDisorderedTime / CLOCKS_PER_SEC << endl;
	printData(orderedData, reversedData, disorderedData);
	cout << endl;

	setData(orderedData, reversedData, disorderedData, tempData);

	printData(orderedData, reversedData, disorderedData);
	start = clock();
	mergeSortPartition(0, SIZE - 1, orderedData, tempData);
	end = clock();
	double mergeOrderedTime = static_cast<double>(end - start);
	start = clock();
	mergeSortPartition(0, SIZE - 1, reversedData, tempData);
	end = clock();
	double mergeReversedTime = static_cast<double>(end - start);
	start = clock();
	mergeSortPartition(0, SIZE - 1, disorderedData, tempData);
	end = clock();
	double mergeDisorderedTime = static_cast<double>(end - start);
	cout << "Merge Sort Time Check" << endl;
	cout << "Ordered Data : " << insertionOrderedTime / CLOCKS_PER_SEC << endl;
	cout << "Reversed Data Data : " << insertionReversedTime / CLOCKS_PER_SEC << endl;
	cout << "Disordered Data : " << insertionDisorderedTime / CLOCKS_PER_SEC << endl;
	printData(orderedData, reversedData, disorderedData);
	cout << endl;

	setData(orderedData, reversedData, disorderedData, tempData);

	printData(orderedData, reversedData, disorderedData);
	start = clock();
	quickSortPartition(0, SIZE - 1, orderedData);
	end = clock();
	double quickOrderedTime = static_cast<double>(end - start);
	start = clock();
	quickSortPartition(0, SIZE - 1, reversedData);
	end = clock();
	double quickReversedTime = static_cast<double>(end - start);
	start = clock();
	quickSortPartition(0, SIZE - 1, disorderedData);
	end = clock();
	double quickDisorderedTime = static_cast<double>(end - start);
	cout << "Quick Sort Time Check" << endl;
	cout << "Ordered Data : " << insertionOrderedTime / CLOCKS_PER_SEC << endl;
	cout << "Reversed Data Data : " << insertionReversedTime / CLOCKS_PER_SEC << endl;
	cout << "Disordered Data : " << insertionDisorderedTime / CLOCKS_PER_SEC << endl;
	printData(orderedData, reversedData, disorderedData);
	cout << endl;

	return 0;
}

void setData(vector<int> &ordered, vector<int> &reversed, vector<int> &disordered, vector<int> &temp)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, SIZE);

	for (int i = 1; i < SIZE + 1; i++)
	{
		ordered[i - 1] = i;
		disordered[i - 1] = dis(gen);
	}
	for (int i = SIZE; i > 0; i--)
	{
		reversed[i - 1] = 1 - (i - SIZE);
	}
}

void printData(vector<int> orderedData, vector<int> reversedData, vector<int> disorderedData)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << orderedData[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << reversedData[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << disorderedData[i] << " ";
	}
	cout << endl;
}

double insertionSort(vector<int> &input)
{
	clock_t start, end;

	start = clock();

	for (int i = 0; i < input.size() - 1; i++)
	{
		for (int k = i + 1; k > 0; k--)
		{
			if (input[k - 1] > input[k])
			{
				int temp = input[k - 1];
				input[k - 1] = input[k];
				input[k] = temp;
			}
			else
				break;
		}
	}

	end = clock();

	return static_cast<double>(end - start);
}

void mergeSort(int left, int right, vector<int> &input, vector<int> &temp)
{
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int	k = left;

	// 갈라진 두 개의 값을 비교하여 temp에 차례로 넣기
	while (i <= mid && j <= right)
	{
		if (input[i] <= input[k])
		{
			temp[k++] = input[i++];
		}
		else
		{
			temp[k++] = input[j++];
		}
	}

	while (i <= mid)
	{
		temp[k++] = input[i++];
	}
	while (k <= right)
	{
		temp[k++] = input[j++];
	}

	for (int i = left; i < right + 1; i++)
	{
		input[i] = temp[i];
	}
}

void mergeSortPartition(int left, int right, vector<int> &input, vector<int> &temp)
{
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		mergeSortPartition(left, mid, input, temp);
		mergeSortPartition(mid + 1, right, input, temp);
		mergeSort(left, right, input, temp);
	}
}

void quickSort(int left, int right, vector<int> &input)
{
	int q;

	if (left < right)
	{
		q = quickSortPartition(left, right, input);
		quickSort(left, q - 1, input);
		quickSort(q + 1, right, input);
	}
}

int quickSortPartition(int low, int high, vector<int> &input)
{
	int i, j, pivot, temp;
	
	// 마지막 값을 pivot으로 설정
	pivot = input[high]; 
	i = low - 1;
	for (j = low; j < high; j ++)
	{
		if (input[j] < pivot)
		{
			// i는 pivot보다 작은 값들의 개수를 index로 표현
			i++;
			temp = input[i];
			input[i] = input[j];
			input[j] = temp;
		}
	}

	// pivot이 있어야 할 위치로
	temp = input[i + 1];
	input[i + 1] = input[high];
	input[high] = temp;
	
	return i + 1;
}