#include <iostream>
using namespace std;

void makePermutation(int n, int r, int depth)
{
	if (depth == r)
	{
		// do something
		return;
	}
	
	for (int i = depth; i < n; i++)
	{
		swap(a[i], a[depth]);
		makePermutation(n, r, depth + 1);
		swap(a[i], a[depth]);
	}
}
