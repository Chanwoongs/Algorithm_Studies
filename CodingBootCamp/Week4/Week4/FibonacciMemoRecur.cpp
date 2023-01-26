#include <iostream>
#include <time.h>

using namespace std;
int Arr[10000] = { 0, };

int fiboRecursive(int num)
{
	if (num == 1 || num == 0)
	{
		return 1;
	}

	return fiboRecursive(num - 1) + fiboRecursive(num - 2);
}

int fiboMemoization(int num)
{
	if (num == 1 || num == 0)
	{
		Arr[num] = 1;

		return Arr[num];
	}

	int temp1 = Arr[num - 1];
	if (temp1 == 0)
	{
		temp1 = fiboMemoization(num - 1);
	}

	int temp2 = Arr[num - 2];
	if (temp2 == 0)
	{
		temp2 = fiboMemoization(num - 2);
	}

	Arr[num] = temp1 + temp2;

	return Arr[num];
}

int main()
{
	int n = 1;

	clock_t start, end;

	start = clock();
	cout << fiboRecursive(1) << endl;
	end = clock();
	cout << "Recursive Time, 1 : " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	start = clock();
	cout << fiboMemoization(1) << endl;
	end = clock();
	cout << "Memoization Time, 1 : " << (double)(end - start) / CLOCKS_PER_SEC << endl;

	start = clock();
	cout << fiboRecursive(40) << endl;
	end = clock();
	cout << "Recursive Time, 40 : " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	start = clock();
	cout << fiboMemoization(40) << endl;
	end = clock();
	cout << "Memoization Time, 40 : " << (double)(end - start) / CLOCKS_PER_SEC << endl;
}

/*
	�ñ��� ��
	�����ϴ� �� �ݺ����� ����ϴ� ���� Bottom - Up ����̴� ��� ���ϴ� ����Ʈ�� ������
	���� ���� ������ ����� Memoization�� ��͸� ���� ����߽��ϴ�. 
	�� ����� Top-Down�� �ش� �ϴ� ����� �� ������ DP�� ���信�� ��� ���ϱ��?

*/ 