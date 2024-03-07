#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	//sort
	vector<int> nums{ 1,3,4,5,6,6,7 };
	sort(nums.begin(), nums.end(), callable object);
	stable_sort(); // 컨테이너 내의 원소 순서가 바뀌지 않게 sort
	partial_sort(); // 컨테이너에서 원하는 갯수까지만 정렬
	nth_element(); // 선택한 원소 왼쪽엔 작은 것만, 오른쪽엔 큰것만 (정렬 X)

	//minmax
	min_element();
	max_element();
	minmax_element();

	//find
	auto it = find(nums.begin(), nums.end(), 2);
	int idx = distance(nums.begin(), it);
	//if sorted
	binary_search(); //logN

	//reduce, sum, product
	accumulate()
	reduce()
}