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
	궁금한 점
	조사하는 중 반복문을 사용하는 것이 Bottom - Up 방법이다 라고 말하는 사이트가 많은데
	현재 제가 구현한 방식은 Memoization과 재귀를 같이 사용했습니다. 
	이 방법은 Top-Down에 해당 하는 방법인 것 같은데 DP의 개념에서 벗어난 것일까요?

*/ 