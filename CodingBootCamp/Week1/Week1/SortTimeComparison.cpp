#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <time.h>

#define SIZE 100000

using namespace std;

void setData(vector<int>&, vector<int>&, vector<int>&);
double insertionSort(vector<int>&);

int main()
{
	vector<int> orderedData;
	vector<int> unorderedData;
	vector<int> disorderedData;

	orderedData.reserve(SIZE);
	unorderedData.reserve(SIZE);
	disorderedData.reserve(SIZE);

	setData(orderedData, unorderedData, disorderedData);
	
	//for (int i = 0; i < SIZE; i++)
	//{
	//	cout << orderedData[i] << " ";
	//}
	//cout << endl;
	//for (int i = 0; i < SIZE; i++)
	//{
	//	cout << unorderedData[i] << " ";
	//}
	//cout << endl;
	//for (int i = 0; i < SIZE; i++)
	//{
	//	cout << disorderedData[i] << " ";
	//}
	//cout << endl;

	double insertionOrderedTime = insertionSort(orderedData);
	double insertionUnorderedTime = insertionSort(unorderedData);
	double insertionDisorderedTime = insertionSort(disorderedData);
	
	cout << "Insertion Sort Time Check" << endl;
	cout << "Ordered Data : " << insertionOrderedTime / CLOCKS_PER_SEC << endl;
	cout << "Unordered Data : " << insertionUnorderedTime / CLOCKS_PER_SEC << endl;
	cout << "Disordered Data : " << insertionDisorderedTime / CLOCKS_PER_SEC << endl;

	//for (int i = 0; i < SIZE; i++)
	//{
	//	cout << orderedData[i] << " ";
	//}
	//cout << endl;
	//for (int i = 0; i < SIZE; i++)
	//{
	//	cout << unorderedData[i] << " ";
	//}
	//cout << endl;
	//for (int i = 0; i < SIZE; i++)
	//{
	//	cout << disorderedData[i] << " ";
	//}
	//cout << endl;

	return 0;
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
		cout << i << " ";
	}

	end = clock();

	return static_cast<double>(end - start);
}

void setData(vector<int> &ordered, vector<int> &unordered, vector<int> &disordered)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, SIZE);

	for (int i = 1; i < SIZE + 1; i++)
	{
		ordered.push_back(i);
		disordered.push_back(dis(gen));
	}
	for (int i = SIZE; i > 0; i--)
	{
		unordered.push_back(i);
	}
}